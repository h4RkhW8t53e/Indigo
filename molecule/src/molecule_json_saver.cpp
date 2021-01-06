/****************************************************************************
 * Copyright (C) from 2009 to Present EPAM Systems.
 *
 * This file is part of Indigo toolkit.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 ***************************************************************************/

#include "molecule/molecule_json_saver.h"
#include "molecule/molecule.h"
#include "molecule/query_molecule.h"

#include <vector>
#include <set>

using namespace indigo;
using namespace rapidjson;

IMPL_ERROR(MoleculeJsonSaver, "molecule json saver");

MoleculeJsonSaver::MoleculeJsonSaver(Output& output) : _output(output)
{
}

void MoleculeJsonSaver::_checkSGroupIndices(BaseMolecule& mol, Array<int>& sgs_list)
{
    QS_DEF(Array<int>, orig_ids);
    QS_DEF(Array<int>, added_ids);
    QS_DEF(Array<int>, sgs_mapping);
    QS_DEF(Array<int>, sgs_changed);

    sgs_list.clear();
    orig_ids.clear();
    added_ids.clear();
    sgs_mapping.clear_resize(mol.sgroups.end());
    sgs_mapping.zerofill();
    sgs_changed.clear_resize(mol.sgroups.end());
    sgs_changed.zerofill();

    int iw = 1;
    for (int i = mol.sgroups.begin(); i != mol.sgroups.end(); i = mol.sgroups.next(i))
    {
        SGroup& sgroup = mol.sgroups.getSGroup(i);
        if (sgroup.parent_group == 0)
        {
            sgs_mapping[i] = iw;
            iw++;
        }
    }
    for (int i = mol.sgroups.begin(); i != mol.sgroups.end(); i = mol.sgroups.next(i))
    {
        if (sgs_mapping[i] == 0)
        {
            sgs_mapping[i] = iw;
            iw++;
        }
    }

    for (int i = mol.sgroups.begin(); i != mol.sgroups.end(); i = mol.sgroups.next(i))
    {
        SGroup& sgroup = mol.sgroups.getSGroup(i);
        if (sgroup.original_group == 0)
        {
            sgroup.original_group = sgs_mapping[i];
        }
        else
        {
            for (int j = mol.sgroups.begin(); j != mol.sgroups.end(); j = mol.sgroups.next(j))
            {
                SGroup& sg = mol.sgroups.getSGroup(j);
                if (sg.parent_group == sgroup.original_group && sgs_changed[j] == 0)
                {
                    sg.parent_group = sgs_mapping[i];
                    sgs_changed[j] = 1;
                }
            }
            sgroup.original_group = sgs_mapping[i];
        }
        orig_ids.push(sgroup.original_group);
    }

    for (int i = mol.sgroups.begin(); i != mol.sgroups.end(); i = mol.sgroups.next(i))
    {
        SGroup& sgroup = mol.sgroups.getSGroup(i);
        if (sgroup.parent_group == 0)
        {
            sgs_list.push(i);
            added_ids.push(sgroup.original_group);
        }
        else
        {
            if (orig_ids.find(sgroup.parent_group) == -1 || sgroup.parent_group == sgroup.original_group)
            {
                sgroup.parent_group = 0;
                sgs_list.push(i);
                added_ids.push(sgroup.original_group);
            }
        }
    }

    for (;;)
    {
        for (int i = mol.sgroups.begin(); i != mol.sgroups.end(); i = mol.sgroups.next(i))
        {
            SGroup& sgroup = mol.sgroups.getSGroup(i);
            if (sgroup.parent_group == 0)
                continue;

            if (added_ids.find(sgroup.original_group) != -1)
                continue;

            if (added_ids.find(sgroup.parent_group) != -1)
            {
                sgs_list.push(i);
                added_ids.push(sgroup.original_group);
            }
        }
        if (sgs_list.size() == mol.countSGroups())
            break;
    }
}

void MoleculeJsonSaver::saveSGroups( BaseMolecule& mol, rapidjson::Writer<rapidjson::StringBuffer>& writer )
{
	QS_DEF(Array<int>, sgs_sorted);
    _checkSGroupIndices(mol, sgs_sorted);

    if (mol.countSGroups() > 0)
    {
		writer.Key("sgroups");
        writer.StartArray();
        int idx = 1;
        for (int i = 0; i < sgs_sorted.size(); i++)
        {
            int sg_idx = sgs_sorted[i];
			saveSGroup( mol.sgroups.getSGroup(sg_idx), writer );
		}
		writer.EndArray();
	}
}

void indigo::MoleculeJsonSaver::saveSGroup(SGroup & sgroup, rapidjson::Writer<rapidjson::StringBuffer>& writer)
{
	writer.Key("type");
	writer.String(SGroup::typeToString(sgroup.sgroup_type));
	writer.Key("atoms");
	writer.StartArray();
	for( int i = 0; i < sgroup.atoms.size(); i++ )
		writer.Int( sgroup.atoms[i] );

	writer.EndArray();

	switch( sgroup.sgroup_type )
	{
	    case SGroup::SG_TYPE_GEN:
		break;
		case SGroup::SG_TYPE_DAT:
		{
			DataSGroup& dsg = (DataSGroup&)sgroup;
			auto name = dsg.name.ptr();
			if (name && strlen(name) )
			{
				writer.Key("fieldName");
				writer.String( name );
			}
			auto data = dsg.data.ptr();
			if (data && strlen(data))
			{
				writer.Key("fieldData");
				writer.String(data);
			}
			auto field_type = dsg.description.ptr();
			if (field_type && strlen(field_type))
			{
				writer.Key("fieldType");
				writer.String( field_type );
			}
			auto query_code = dsg.querycode.ptr();
			if (query_code && strlen(query_code))
			{
				writer.Key("queryType");
				writer.String(query_code);
			}
			auto query_oper = dsg.queryoper.ptr();
			if (query_oper && strlen(query_oper) )
			{
				writer.Key("queryOp");
				writer.String(query_oper);
			}

			writer.Key("x");
			writer.Double(dsg.display_pos.x );
			writer.Key("y");
			writer.Double(dsg.display_pos.y );

			if( !dsg.detached )
			{
				writer.Key("dataDetached");
				writer.Bool( false );
			}

			if( dsg.relative )
			{
				writer.Key("placement");
				writer.Bool( true );
			}

			if( dsg.display_units )
			{
				writer.Key("display");
				writer.Bool(true);
			}

			char tag = dsg.tag;
			if( tag != 0 && tag != ' ' )
			{
				writer.Key( "tag" );
				std::string tag_s{ tag };
				writer.String( tag_s.c_str() );
			}

			if( dsg.num_chars > 0)
			{
				writer.Key( "displayedChars" );
				writer.Int( dsg.num_chars );
			}
		}
		break;
		case SGroup::SG_TYPE_SUP:
		{
			Superatom& sa = (Superatom&)sgroup;
			writer.Key("name");
			writer.String( sa.subscript.ptr() );
		}
		break;
		case SGroup::SG_TYPE_SRU:
		{
			RepeatingUnit& ru = (RepeatingUnit&)sgroup;
			writer.Key("subscript");
			writer.String( ru.subscript.ptr() );
			writer.Key("connectivity");
			switch (ru.connectivity)
			{
			    case SGroup::HEAD_TO_TAIL:
					writer.String("HT");
				break;
				case SGroup::HEAD_TO_HEAD:
					writer.String("HH");
				break;
				case SGroup::EITHER:
					writer.String("EU");
				break;
				default:
					throw Error("Invalid connectivity");
				break;
			}

		}
		break;
		case SGroup::SG_TYPE_MUL:
		{
			MultipleGroup& mg = (MultipleGroup&)sgroup;
			writer.Key("mul");
			writer.Int( mg.multiplier );
		}
		break;
		case SGroup::SG_TYPE_MON:
			throw Error("SG_TYPE_MON not implemented yet");
		break;
		case SGroup::SG_TYPE_MER:
			throw Error("SG_TYPE_MER not implemented yet");
		break;
		case SGroup::SG_TYPE_COP:
			throw Error("SG_TYPE_COP not implemented yet");
		break;
		case SGroup::SG_TYPE_CRO:
			throw Error("SG_TYPE_CRO not implemented yet");
		break;
		case SGroup::SG_TYPE_MOD:
			throw Error("SG_TYPE_MOD not implemented yet");
		break;
		case SGroup::SG_TYPE_GRA:
			throw Error("SG_TYPE_GRA not implemented yet");
		break;
		case SGroup::SG_TYPE_COM:
			throw Error("SG_TYPE_COM not implemented yet");
		break;
		case SGroup::SG_TYPE_MIX:
			throw Error("SG_TYPE_MIX not implemented yet");
		break;
		case SGroup::SG_TYPE_FOR:
			throw Error("SG_TYPE_FOR not implemented yet");
		break;
		case SGroup::SG_TYPE_ANY:
			throw Error("SG_TYPE_ANY not implemented yet");
		break;
		default:
		break;
	}
}

void MoleculeJsonSaver::saveBonds( BaseMolecule& mol, rapidjson::Writer<rapidjson::StringBuffer>& writer )
{
    QS_DEF(Array<char>, buf);
    ArrayOutput out(buf);
    if (mol.edgeCount() > 0)
    {
		writer.Key("bonds");
        writer.StartArray();
        for (auto i : mol.edges())
        {
            writer.StartObject();
            writer.Key("type");
			int bond_order = mol.getBondOrder(i);
			if (bond_order < 0 && _pqmol )
            {
                int qb = QueryMolecule::getQueryBondType(_pqmol->getBond(i));
                if (qb == QueryMolecule::QUERY_BOND_SINGLE_OR_DOUBLE)
                    bond_order = 5;
                else if (qb == QueryMolecule::QUERY_BOND_SINGLE_OR_AROMATIC)
                    bond_order = 6;
                else if (qb == QueryMolecule::QUERY_BOND_DOUBLE_OR_AROMATIC)
                    bond_order = 7;
                else if (qb == QueryMolecule::QUERY_BOND_ANY)
                    bond_order = 8;
			   if( bond_order < 0 )
                 throw Error("Invalid query bond");
            }

            if (bond_order == BOND_ZERO && _pmol )
            {
                bond_order = 9;
				const Edge& edge = mol.getEdge(i);
                if ((_pmol->getAtomNumber(edge.beg) == ELEM_H) || (_pmol->getAtomNumber(edge.end) == ELEM_H))
                    bond_order = 10;
            }

            writer.Uint(bond_order);

			int topology = -1;
			if (_pqmol)
			{
				_pqmol->getBond(i).sureValue(QueryMolecule::BOND_TOPOLOGY, topology);
				if ( topology > 0)
				{
					writer.Key("topology");
					writer.Uint(topology);
				}
			}

            const Edge& e1 = mol.getEdge(i);
            writer.Key("atoms");
            writer.StartArray();
            writer.Int(e1.beg);
            writer.Int(e1.end);
            writer.EndArray();

            int stereo = mol.getBondDirection(i);
            switch( stereo )
            {
                case BOND_UP:
                    stereo = 1;
                    break;
                case BOND_EITHER:
                    stereo = 4;
                    break;
                case BOND_DOWN:
                    stereo = 6;
                    break;
                default:
                    break;
            }

            if( mol.cis_trans.isIgnored(i) )
                stereo = 3;

            const auto parity = mol.cis_trans.getParity(i);
            if (parity == MoleculeCisTrans::CIS)
            {
                stereo = 7;
            }
            else if (parity == MoleculeCisTrans::TRANS)
            {
                stereo = 8;
            }

            if( stereo )
            {
                writer.Key("stereo");
                writer.Uint( stereo );
            }
            writer.EndObject();
        }
		writer.EndArray();
    }
}

void MoleculeJsonSaver::saveAtoms( BaseMolecule& mol, Writer<StringBuffer>& writer )
{
    QS_DEF(Array<char>, buf);
    ArrayOutput out(buf);
    if (mol.vertexCount() > 0)
    {
        for (auto i : mol.vertices())
        {
            writer.StartObject();
            QS_DEF(Array<int>, rg_list);
            int radical = 0;
            if( mol.isRSite(i) )
            {
                mol.getAllowedRGroups( i, rg_list );
                writer.Key("type");
                writer.String("rg-label");
                writer.Key("$refs");
                writer.StartArray();
                for( int j = 0; j < rg_list.size(); ++j )
                {
                    buf.clear();
                    out.printf("rg-%d", rg_list[j] );
                    buf.push(0);
                    writer.String(buf.ptr());
                }
                writer.EndArray();
            } else
            {
                if (!mol.isPseudoAtom(i))
                {
                    radical = mol.getAtomRadical(i);
                }
                mol.getAtomSymbol(i, buf);
                writer.Key("label");
                writer.String(buf.ptr());
            }
            if (BaseMolecule::hasCoord(mol) )
            {
                const Vec3f& coord = mol.getAtomXyz(i);
                writer.Key("location");
                writer.StartArray();
                writer.Double(coord.x);
                writer.Double(coord.y);
                writer.Double(coord.z);
                writer.EndArray();
            }
            int charge = mol.getAtomCharge(i);
            int evalence = mol.getExplicitValence(i);
            int isotope = mol.getAtomIsotope(i);
            if( charge )
            {
                writer.Key("charge");
                writer.Int( charge );
            }
            if( evalence > 0 )
            {
                writer.Key("explicitValence");
                writer.Int( evalence );
            }
            if( radical )
            {
                writer.Key("radical");
                writer.Int( radical );
            }

            if( isotope )
            {
                writer.Key("isotope");
                writer.Int( isotope );
            }
            writer.EndObject();
        }
    }
}

void MoleculeJsonSaver::saveRGroup( PtrPool<BaseMolecule>& fragments, int rgnum, rapidjson::Writer<rapidjson::StringBuffer>& writer )
{
    QS_DEF(Array<char>, buf);
    ArrayOutput out(buf);

    buf.clear();
    out.printf( "rg%d", rgnum );
    buf.push(0);

    writer.Key(buf.ptr());
    writer.StartObject();
    writer.Key("rlogic");
    writer.StartObject();
    writer.Key("number");
    writer.Int( rgnum );
    writer.EndObject(); //rlogic
    writer.Key("type");
    writer.String("rgroup");

    writer.Key("atoms");
    writer.StartArray();
    for (int j = fragments.begin(); j != fragments.end(); j = fragments.next(j))
        saveAtoms( *fragments[j], writer );
    writer.EndArray();

    writer.Key("bonds");
    writer.StartArray();
    for (int j = fragments.begin(); j != fragments.end(); j = fragments.next(j))
        saveBonds( *fragments[j], writer );
    writer.EndArray();
    writer.EndObject();
}


void MoleculeJsonSaver::saveMolecule( BaseMolecule& mol )
{
    // bool have_z = BaseMolecule::hasZCoord(*_mol);
    QS_DEF(Array<char>, buf);
    ArrayOutput out(buf);
    LocaleGuard locale_guard;
    //
    StringBuffer s;
    std::set<int> rgrp_full_list;
    Writer<StringBuffer> writer(s);
    std::stringstream result;

    _pmol = dynamic_cast<Molecule*>(&mol);
    _pqmol = dynamic_cast<QueryMolecule*>(&mol);

    writer.StartObject();

    writer.Key("root");
    writer.StartObject();
    writer.Key("nodes");
    writer.StartArray();

    writer.StartObject();
    writer.Key("$ref");
    writer.String( "mol0" );
    writer.EndObject();

    int n_rgroups = mol.rgroups.getRGroupCount();
    for ( int i = 1; i <= n_rgroups; ++i )
    {
        buf.clear();
        out.printf( "rg%d", i );
        buf.push(0);
        writer.StartObject();
        writer.Key("$ref");
        writer.String( buf.ptr() );
        writer.EndObject();
    }

    writer.EndArray(); // nodes
    writer.EndObject(); // root

    writer.Key("mol0");
    writer.StartObject();
    writer.Key("type");
    writer.String("molecule");

    writer.Key("atoms");
    writer.StartArray();
    saveAtoms( mol, writer );
    writer.EndArray();

    saveBonds( mol, writer );

	saveSGroups( mol, writer );
    writer.EndObject(); // mol0

    for ( int i = 1; i <= n_rgroups; i++ )
    {
        auto& rgrp = mol.rgroups.getRGroup(i);
        if( rgrp.fragments.size() )
            saveRGroup( rgrp.fragments, i, writer );
    }

    writer.EndObject();
    result << s.GetString();
    _output.printf("%s", result.str().c_str());
}
