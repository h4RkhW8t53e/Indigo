import os
import sys
sys.path.append(os.path.normpath(os.path.join(os.path.abspath(__file__), '..', '..', '..', "common")))
from env_indigo import *

indigo = Indigo()
indigo.setOption("ignore-noncritical-query-features", "true")

tests = [
    { "name" : "issue269test_RGroupsWarning",  "test": "rgroup", "expected": '''[{"code":20,"message":"Structure contains R-groups"}]'''}, 
    { "name" : "issue269test_ChiralityWarning",  "test": "chirality", "expected": '''[{"code":31,"message":"Structure contains chirality"}]'''},
    { "name" : "issue269test_StereochemistryWarning",  "test": "stereo", "expected": '''[{"code":11,"message":"Structure contains stereocenters defined by 3D coordinates","ids":[0,1,2,3,4,5,6,7,8,9]}]'''},
    { "name" : "issue269test_PseudoatomWarning",  "test": "pseudoatom", "expected": '''[{"code":8,"message":"Structure contains pseudoatoms","ids":[5]}]'''},
    { "name" : "issue269test_RadicalWarning",  "test": "radical", "expected": '''[{"code":6,"message":"Structure contains radicals","ids":[1,3,5]}]'''},
    { "name" : "issue269test_QueryWarning",  "test": "query", "expected": '''[{"code":14,"message":"Structure contains query features"}]'''},
    { "name" : "issue269test_All",  "test": "all", "expected": '''[{"code":4,"message":"Structure contains RGroup components, so valency could not be checked"},{"code":7,"message":"Structure contains pseudoatoms, so radicals could not be checked"},{"code":8,"message":"Structure contains pseudoatoms","ids":[27,29]},{"code":11,"message":"Structure contains stereocenters defined by 3D coordinates","ids":[0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,28,30,31,32,34,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,239,240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255,256,257,258,259,260,261,262,263,264,265,266,267,268,269,270,271,272,273,274,275,276,277,278,279,280,281,282,283,284,285,286,287,288,289,290,291,292,293,294,295,296,297,298,299,300,301,302,303,304,305,306,307,308,309,310,311,312,313,314,315,316,317,318,319,320,321,322,323,324,325,326,327,328,329,330,331,332,333,334,335,336,337,338,339,340,341,342,343,344,345,346,347,348,349,350,351,352,353,354,355,356,357,358,359,360,361,362,363,364,365,366,367,368,369,370,371,372,373,374,375,376,377,378,379,380,381,382,383,384,385,386,387,388,389,390,391,392,393,394,395,396,397,398,399,400,401,402,403,404,405,406,407,408,409,410,411,412,413,414,415,416,417,418,419,420,421]},{"code":12,"message":"Structure contains stereocenters with undefined stereo configuration","ids":[0,4,6,8,9,14,32,34,43,81,119,127,128,129,130,131,132,133,134,137,139,140,141,142,143,144,145,146,147,148,149,151,152,153,154,155,156,157,159,160,162,163,164,165,166,168,169,171,176,178,181,184,302,303,304,305,306]},{"code":18,"message":"Structure contains overlapping atoms","ids":[355,356,357,359,360,361,363,364,365,366,371,372,373,374,375,376,377,378,379,380,381,382,383,384,385,386,387,388,389,390,391,392,393,394,395,396,397,398,399,400,401,402,403,404,405,406,407,408,409,410,411,412,413,414,415,416,417,418,419,420,421]},{"code":19,"message":"Structure contains overlapping bonds.","ids":[283,308,310,312,314,316,318,320,322,324,326,328,330,332,334,336,338,340,342]},{"code":20,"message":"Structure contains R-groups"},{"code":21,"message":"Structure contains S-groups"},{"code":23,"message":"Structure has non-zero charge"},{"code":32,"message":"Not implemented yet: check salt"},{"code":33,"message":"Structure supports only Molfile V3000"}]'''},
    { "name" : "issue269test_Issue_293_All",  "test": "radical;pseudoatom;stereo;query;overlap_atom;overlap_bond;rgroup;chirality;3d_coord", "expected": '''[{"code":6,"message":"Structure contains radicals","ids":[13,15,17]},{"code":14,"message":"Structure contains query features"}]'''},
    ] 

errors = ''
for test in tests:
    print(f"\nTEST: {test['name']}\n")
    with open(joinPath(f"molecules/{test['name']}.mol"), 'r') as file:
        molfile = file.read()
    res = indigo.check2(molfile, test['test'])
    if (res == test['expected']):
        print("OK\n")
    else:
        print("FAIL\n")
        err = f"""
        {test['name']} FAILED:
           EXPECTED: {test['expected']}
           ACTUAL: {res}
           
           """
        print(err)
        errors += err
if (errors != ""):
    raise Exception(errors)
else:
    print("\nPASSED\n")
