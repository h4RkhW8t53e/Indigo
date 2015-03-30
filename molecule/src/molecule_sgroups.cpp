/****************************************************************************
 * Copyright (C) 2009-2013 GGA Software Services LLC
 * 
 * This file is part of Indigo toolkit.
 * 
 * This file may be distributed and/or modified under the terms of the
 * GNU General Public License version 3 as published by the Free Software
 * Foundation and appearing in the file LICENSE.GPL included in the
 * packaging of this file.
 * 
 * This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
 * WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 ***************************************************************************/

#include "base_cpp/scanner.h"
#include "base_cpp/tlscont.h"

#include "molecule/molecule_sgroups.h"

using namespace indigo;

static SGroup::SgType mappingForSgTypes[] = 
{
   { SGroup::SG_TYPE_GEN, "GEN" },
   { SGroup::SG_TYPE_DAT, "DAT" },
   { SGroup::SG_TYPE_SUP, "SUP" },
   { SGroup::SG_TYPE_SRU, "SRU" },
   { SGroup::SG_TYPE_MUL, "MUL" },
   { SGroup::SG_TYPE_MON, "MON" },
   { SGroup::SG_TYPE_MER, "MER" },
   { SGroup::SG_TYPE_COP, "COP" },
   { SGroup::SG_TYPE_CRO, "CRO" },
   { SGroup::SG_TYPE_MOD, "MOD" },
   { SGroup::SG_TYPE_GRA, "GRA" },
   { SGroup::SG_TYPE_COM, "COM" },
   { SGroup::SG_TYPE_MIX, "MIX" },
   { SGroup::SG_TYPE_FOR, "FOR" },
   { SGroup::SG_TYPE_ANY, "ANY" },
};

SGroup::SGroup ()
{
   sgroup_type = SGroup::SG_TYPE_GEN;
   brk_style = 0;
   original_group = 0;
   parent_group = 0;
}

const char * SGroup::typeToString(int sg_type)
{
   for (int i = 0; i < NELEM(mappingForSgTypes); i++)
   {
      if (sg_type == mappingForSgTypes[i].int_type)
         return mappingForSgTypes[i].str_type;
   }
   return NULL;
}

int SGroup::getType(const char * sg_type)
{
   for (int i = 0; i < NELEM(mappingForSgTypes); i++)
   {
      if (strcasecmp(sg_type, mappingForSgTypes[i].str_type) == 0)
      {
         return mappingForSgTypes[i].int_type;
      }
   }
   return -1;
}

SGroup::~SGroup ()
{
}

DataSGroup::DataSGroup ()
{
   sgroup_type = SGroup::SG_TYPE_DAT;
   detached = false;
   relative = false;
   display_units = false;
   dasp_pos = 1;
   num_chars = 0;
   tag = ' ';
}

DataSGroup::~DataSGroup ()
{
}

Superatom::Superatom ()
{
   sgroup_type = SGroup::SG_TYPE_SUP;
   contracted = -1;
}

Superatom::~Superatom ()
{
}

RepeatingUnit::RepeatingUnit ()
{
   sgroup_type = SGroup::SG_TYPE_SRU;
   connectivity = 0;
}

RepeatingUnit::~RepeatingUnit ()
{
}

MultipleGroup::MultipleGroup ()
{
   sgroup_type = SGroup::SG_TYPE_MUL;
   multiplier = 1;
}

MultipleGroup::~MultipleGroup ()
{
}

IMPL_ERROR(MoleculeSGroups, "molecule sgroups");

MoleculeSGroups::MoleculeSGroups ()
{
}

MoleculeSGroups::~MoleculeSGroups ()
{
}

void MoleculeSGroups::clear ()
{
   _sgroups.clear();
}

void MoleculeSGroups::clear (int sg_type)
{
   int count = 0;
   for (int i = _sgroups.begin(); i != _sgroups.end(); i = _sgroups.next(i))
   {
     if (_sgroups.at(i)->sgroup_type == sg_type)
        remove(i);
   }
}

void MoleculeSGroups::remove (int idx)
{
   _sgroups.remove(idx);
}

int MoleculeSGroups::begin ()
{
   return _sgroups.begin();
}

int MoleculeSGroups::end ()
{
   return _sgroups.end();
}

int MoleculeSGroups::next (int i)
{
   return _sgroups.next(i);
}

int MoleculeSGroups::addSGroup (const char * sg_type)
{
   int sgroup_type = SGroup::getType(sg_type);

   if (sgroup_type == -1)
      throw Error("Unknown SGroup type = %s", sg_type);

   int idx = -1;
   switch (sgroup_type)
   {
      case SGroup::SG_TYPE_GEN: idx = _sgroups.add(new SGroup()); break;
      case SGroup::SG_TYPE_DAT: idx = _sgroups.add(new DataSGroup()); break;
      case SGroup::SG_TYPE_SUP: idx = _sgroups.add(new Superatom()); break;
      case SGroup::SG_TYPE_SRU: idx = _sgroups.add(new RepeatingUnit()); break;
      case SGroup::SG_TYPE_MUL: idx = _sgroups.add(new MultipleGroup()); break;
      default: idx = _sgroups.add(new SGroup());
   }
   return idx;
}

int MoleculeSGroups::addSGroup (int sg_type)
{
   int idx = -1;
   switch (sg_type)
   {
      case SGroup::SG_TYPE_GEN: idx = _sgroups.add(new SGroup()); break;
      case SGroup::SG_TYPE_DAT: idx = _sgroups.add(new DataSGroup()); break;
      case SGroup::SG_TYPE_SUP: idx = _sgroups.add(new Superatom()); break;
      case SGroup::SG_TYPE_SRU: idx = _sgroups.add(new RepeatingUnit()); break;
      case SGroup::SG_TYPE_MUL: idx = _sgroups.add(new MultipleGroup()); break;
      default: idx = _sgroups.add(new SGroup());
   }
   return idx;
}

SGroup & MoleculeSGroups::getSGroup (int idx)
{
   return *_sgroups.at(idx);
}

SGroup & MoleculeSGroups::getSGroup (int idx, int sg_type)
{
   int count = -1;
   for (int i = _sgroups.begin(); i != _sgroups.end(); i = _sgroups.next(i))
   {
     if (_sgroups.at(i)->sgroup_type == sg_type)
     {
        count++;
        if (count == idx)
           return *_sgroups.at(i);
     }
   }
   throw Error("Sgroup index %d or type %d wrong", idx, sg_type);
}

int MoleculeSGroups::getSGroupCount ()
{
   return _sgroups.size();
}

int MoleculeSGroups::getSGroupCount (int sg_type)
{
   int count = 0;
   for (int i = _sgroups.begin(); i != _sgroups.end(); i = _sgroups.next(i))
   {
     if (_sgroups.at(i)->sgroup_type == sg_type)
        count++;
   }
   return count;
}

bool MoleculeSGroups::isPolimer ()
{
   return getSGroupCount(SGroup::SG_TYPE_SRU) > 0;
}


void MoleculeSGroups::findSGroups (const char *property, const char *value, Array<int> &sgs)
{
   QS_DEF(Array<int>, s_indices);
   int s_property;
   int s_type;
   int s_int;

   sgs.clear();
   s_indices.clear();

   parseCondition (property, value, s_property, s_type, s_int, s_indices);

   if (s_type == PropertyTypes::PROPERTY_INT)
      findSGroups(s_property, s_int, sgs);
   else if (s_type == PropertyTypes::PROPERTY_STRING)
      findSGroups(s_property, value, sgs);
   else if (s_type == PropertyTypes::PROPERTY_INT_ARRAY)
      findSGroups(s_property, s_indices, sgs);
}

void MoleculeSGroups::parseCondition (const char* property, const char* value, 
                                      int &s_property, int &s_type, int &s_int, Array<int> &s_indices)
{
   struct Mapping
   {
      const char *property;
      int  sg_property;
      int  property_type;
   };

   static Mapping mappingForProperties[] = 
   {
      { "SG_TYPE", SGroup::SG_TYPE, PROPERTY_INT },
      { "SG_CLASS", SGroup::SG_CLASS, PROPERTY_STRING },
      { "SG_LABEL", SGroup::SG_LABEL, PROPERTY_STRING },
      { "SG_DISPLAY_OPTION", SGroup::SG_DISPLAY_OPTION, PROPERTY_INT },
      { "SG_BRACKET_STYLE", SGroup::SG_BRACKET_STYLE, PROPERTY_INT },
      { "SG_DATA", SGroup::SG_DATA, PROPERTY_STRING },
      { "SG_DATA_NAME", SGroup::SG_DATA_NAME, PROPERTY_STRING },
      { "SG_DATA_TYPE", SGroup::SG_DATA_TYPE, PROPERTY_STRING },
      { "SG_DATA_DESCRIPTION", SGroup::SG_DATA_DESCRIPTION, PROPERTY_STRING },
      { "SG_DATA_DISPLAY", SGroup::SG_DATA_DISPLAY, PROPERTY_STRING },
      { "SG_DATA_LOCATION", SGroup::SG_DATA_LOCATION, PROPERTY_STRING },
      { "SG_DATA_TAG", SGroup::SG_DATA_TAG, PROPERTY_STRING },
      { "SG_QUERY_CODE", SGroup::SG_QUERY_CODE, PROPERTY_STRING },
      { "SG_QUERY_OPER", SGroup::SG_QUERY_OPER, PROPERTY_STRING },
      { "SG_PARENT", SGroup::SG_PARENT, PROPERTY_INT },
      { "SG_CHILD", SGroup::SG_CHILD, PROPERTY_INT },
      { "SG_ATOMS", SGroup::SG_ATOMS, PROPERTY_INT_ARRAY },
      { "SG_BONDS", SGroup::SG_BONDS, PROPERTY_INT_ARRAY },
   };

   for (int i = 0; i < NELEM(mappingForProperties); i++)
   {
      if (strcasecmp(property, mappingForProperties[i].property) == 0)
      {
         int int_value = 0;
         if (strcasecmp(property, "SG_TYPE") == 0)
         {
            for (int j = 0; j < NELEM(mappingForSgTypes); j++)
            {
               if (strcasecmp(value, mappingForSgTypes[j].str_type) == 0)
               {
                  int_value = mappingForSgTypes[j].int_type;
               }
            }
         }
         else if (value != NULL)
         {
            if (mappingForProperties[i].property_type == PROPERTY_INT)
            {
               BufferScanner buf_scanner(value);
               int_value = buf_scanner.readInt();
            }
            else if (mappingForProperties[i].property_type == PROPERTY_BOOL)
            {
               if (strcasecmp(value, "true") == 0)
                  int_value = 1;
               else if (strcasecmp(value, "false") == 0)
                  int_value = 0;
               else
               {
                  BufferScanner buf_scanner(value);
                  int_value = buf_scanner.readInt();
               }
            }
            else if (mappingForProperties[i].property_type == PROPERTY_INT_ARRAY)
            {
               BufferScanner buf_scanner(value);
               while (!buf_scanner.isEOF())
               {
                  s_indices.push(buf_scanner.readInt1());
               }
            }
         }
         s_property = mappingForProperties[i].sg_property;
         s_type = mappingForProperties[i].property_type;
         s_int = int_value;

         return;
      }
   }

   throw Error("unsupported condition property: %s", property);
}

void MoleculeSGroups::findSGroups (int property, int value, Array<int> &sgs)
{
   int i;
   if (property == SGroup::SG_TYPE)
   {
      for (i = _sgroups.begin(); i != _sgroups.end(); i = _sgroups.next(i))
      {
         SGroup &sg = *_sgroups.at(i);
         if (sg.sgroup_type == value)
         {
            sgs.push(i);
         }
      } 
   }
   else if (property == SGroup::SG_BRACKET_STYLE)
   {
      for (i = _sgroups.begin(); i != _sgroups.end(); i = _sgroups.next(i))
      {
         SGroup &sg = *_sgroups.at(i);
         if (sg.brk_style == value)
         {
            sgs.push(i);
         }
      } 
   }
   else if (property == SGroup::SG_DISPLAY_OPTION)
   {
      for (i = _sgroups.begin(); i != _sgroups.end(); i = _sgroups.next(i))
      {
         SGroup &sg = *_sgroups.at(i);
         if (sg.sgroup_type == SGroup::SG_TYPE_SUP)
         {
            Superatom &sup = (Superatom &)sg;
            if (sup.contracted == value)
            {
               sgs.push(i);
            }
         }
      } 
   }
   else if (property == SGroup::SG_PARENT)
   {
      for (i = _sgroups.begin(); i != _sgroups.end(); i = _sgroups.next(i))
      {
         SGroup &sg = *_sgroups.at(i);
         if (sg.parent_group == value)
         {
            sgs.push(i);
         }
      } 
   }
   else if (property == SGroup::SG_CHILD)
   {
      if (!_sgroups.hasElement(value))
         return;

      SGroup &sg = *_sgroups.at(value);
      if (sg.parent_group != 0)
      {
         int idx = _findSGroupById(sg.parent_group);
         if (idx != -1)
            sgs.push(idx);
      }    
   }
   else
      throw Error("Unknown or incomaptible value Sgroup property: %d", property);
}

void MoleculeSGroups::findSGroups (int property, const char *str, Array<int> &sgs)
{
   int i;
   if (property == SGroup::SG_CLASS)
   {
      for (i = _sgroups.begin(); i != _sgroups.end(); i = _sgroups.next(i))
      {
         SGroup &sg = *_sgroups.at(i);
         if (sg.sgroup_type == SGroup::SG_TYPE_SUP)
         {
            Superatom &sa = (Superatom &)sg;
            BufferScanner sc(sa.sa_class);
            if (sa.sa_class.size() == (strlen(str) + 1) && sc.findWord(str))
            {
               sgs.push(i);
            }
         }
      } 
   }
   else if (property == SGroup::SG_LABEL)
   {
      for (i = _sgroups.begin(); i != _sgroups.end(); i = _sgroups.next(i))
      {
         SGroup &sg = *_sgroups.at(i);
         if (sg.sgroup_type == SGroup::SG_TYPE_SUP)
         {
            Superatom &sa = (Superatom &)sg;
            BufferScanner sc(sa.subscript);
            if (sa.subscript.size() == (strlen(str) + 1) && sc.findWord(str))
            {
               sgs.push(i);
            }
         }
         else if (sg.sgroup_type == SGroup::SG_TYPE_SRU)
         {
            RepeatingUnit &ru = (RepeatingUnit &)sg;
            BufferScanner sc(ru.subscript);
            if (ru.subscript.size() == (strlen(str) + 1) && sc.findWord(str))
            {
               sgs.push(i);
            }
         }
      } 
   }
   else if (property == SGroup::SG_DATA)
   {
      for (i = _sgroups.begin(); i != _sgroups.end(); i = _sgroups.next(i))
      {
         SGroup &sg = *_sgroups.at(i);
         if (sg.sgroup_type == SGroup::SG_TYPE_DAT)
         {
            DataSGroup &dg = (DataSGroup &)sg;
            BufferScanner sc(dg.data);
            if (dg.data.size() == (strlen(str) + 1) && sc.findWord(str))
            {
               sgs.push(i);
            }
         }
      } 
   }
   else if (property == SGroup::SG_DATA_NAME)
   {
      for (i = _sgroups.begin(); i != _sgroups.end(); i = _sgroups.next(i))
      {
         SGroup &sg = *_sgroups.at(i);
         if (sg.sgroup_type == SGroup::SG_TYPE_DAT)
         {
            DataSGroup &dg = (DataSGroup &)sg;
            BufferScanner sc(dg.name);
            if (dg.name.size() == (strlen(str) + 1) && sc.findWord(str))
            {
               sgs.push(i);
            }
         }
      } 
   }
   else if (property == SGroup::SG_DATA_TYPE)
   {
      for (i = _sgroups.begin(); i != _sgroups.end(); i = _sgroups.next(i))
      {
         SGroup &sg = *_sgroups.at(i);
         if (sg.sgroup_type == SGroup::SG_TYPE_DAT)
         {
            DataSGroup &dg = (DataSGroup &)sg;
            BufferScanner sc(dg.type);
            if (dg.type.size() == (strlen(str) + 1) && sc.findWord(str))
            {
               sgs.push(i);
            }
         }
      } 
   }
   else if (property == SGroup::SG_DATA_DESCRIPTION)
   {
      for (i = _sgroups.begin(); i != _sgroups.end(); i = _sgroups.next(i))
      {
         SGroup &sg = *_sgroups.at(i);
         if (sg.sgroup_type == SGroup::SG_TYPE_DAT)
         {
            DataSGroup &dg = (DataSGroup &)sg;
            BufferScanner sc(dg.description);
            if (dg.description.size() == (strlen(str) + 1) && sc.findWord(str))
            {
               sgs.push(i);
            }
         }
      } 
   }
   else if (property == SGroup::SG_DATA_DISPLAY)
   {
      for (i = _sgroups.begin(); i != _sgroups.end(); i = _sgroups.next(i))
      {
         SGroup &sg = *_sgroups.at(i);
         if (sg.sgroup_type == SGroup::SG_TYPE_DAT)
         {
            DataSGroup &dg = (DataSGroup &)sg;
            if (((strcasecmp(str, "detached") == 0) && dg.detached) ||
                ((strcasecmp(str, "attached") == 0) && !dg.detached))
            {
               sgs.push(i);
            }
         }
      } 
   }
   else if (property == SGroup::SG_DATA_LOCATION)
   {
      for (i = _sgroups.begin(); i != _sgroups.end(); i = _sgroups.next(i))
      {
         SGroup &sg = *_sgroups.at(i);
         if (sg.sgroup_type == SGroup::SG_TYPE_DAT)
         {
            DataSGroup &dg = (DataSGroup &)sg;
            if (((strcasecmp(str, "relative") == 0) && dg.relative) ||
                ((strcasecmp(str, "absolute") == 0) && !dg.relative))
            {
               sgs.push(i);
            }
         }
      } 
   }
   else if (property == SGroup::SG_DATA_TAG)
   {
      for (i = _sgroups.begin(); i != _sgroups.end(); i = _sgroups.next(i))
      {
         SGroup &sg = *_sgroups.at(i);
         if (sg.sgroup_type == SGroup::SG_TYPE_DAT)
         {
            DataSGroup &dg = (DataSGroup &)sg;
            if ((strlen(str) == 1) && str[0] == dg.tag)
            {
               sgs.push(i);
            }
         }
      } 
   }
   else if (property == SGroup::SG_QUERY_CODE)
   {
      for (i = _sgroups.begin(); i != _sgroups.end(); i = _sgroups.next(i))
      {
         SGroup &sg = *_sgroups.at(i);
         if (sg.sgroup_type == SGroup::SG_TYPE_DAT)
         {
            DataSGroup &dg = (DataSGroup &)sg;
            BufferScanner sc(dg.querycode);
            if (dg.querycode.size() == (strlen(str) + 1) && sc.findWord(str))
            {
               sgs.push(i);
            }
         }
      } 
   }
   else if (property == SGroup::SG_QUERY_OPER)
   {
      for (i = _sgroups.begin(); i != _sgroups.end(); i = _sgroups.next(i))
      {
         SGroup &sg = *_sgroups.at(i);
         if (sg.sgroup_type == SGroup::SG_TYPE_DAT)
         {
            DataSGroup &dg = (DataSGroup &)sg;
            BufferScanner sc(dg.queryoper);
            if (dg.queryoper.size() == (strlen(str) + 1) && sc.findWord(str))
            {
               sgs.push(i);
            }
         }
      } 
   }
   else
      throw Error("Unknown or incomaptible value Sgroup property: %d", property);
}

void MoleculeSGroups::findSGroups (int property, Array<int> &indices, Array<int> &sgs)
{
   int i;
   if (property == SGroup::SG_ATOMS)
   {
      for (i = _sgroups.begin(); i != _sgroups.end(); i = _sgroups.next(i))
      {
         SGroup &sg = *_sgroups.at(i);
         if (_cmpIndices(sg.atoms, indices))
         {
            sgs.push(i);
         }
      } 
   }
   else if (property == SGroup::SG_BONDS)
   {
      for (i = _sgroups.begin(); i != _sgroups.end(); i = _sgroups.next(i))
      {
         SGroup &sg = *_sgroups.at(i);
         if (_cmpIndices(sg.bonds, indices))
         {
            sgs.push(i);
         }
      } 
   }
   else
      throw Error("Unknown or incomaptible value Sgroup property: %d", property);
}

int MoleculeSGroups::_findSGroupById (int id)
{
   for (int i = _sgroups.begin(); i != _sgroups.end(); i = _sgroups.next(i))
   {
      SGroup &sg = *_sgroups.at(i);
      if (sg.original_group == id)
      {
         return i;
      }
   } 
   return -1;
}

bool MoleculeSGroups::_cmpIndices (Array<int> &t_inds, Array<int> &q_inds)
{
   for (int i = 0; i < q_inds.size(); i++)
   {
      if (t_inds.find(q_inds[i]) == -1)
         return false;
   }
   return true;
}