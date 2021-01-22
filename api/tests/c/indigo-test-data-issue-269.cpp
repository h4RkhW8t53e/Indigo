extern "C" const char* issue269test_RGroupsWarning = R"(
  Ketcher  1142115522D 1   1.00000     0.00000     0

  7  6  0     0  0            999 V2000
    5.8000   -6.3250    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0
    6.6660   -6.8250    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0
    7.5321   -6.3250    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0
    8.3981   -6.8250    0.0000 R#  0  0  0  0  0  0  0  0  0  0  0  0
    9.2641   -6.3250    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0
   10.1301   -6.8250    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0
   10.9962   -6.3250    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0
  1  2  1  0     0  0
  2  3  1  0     0  0
  3  4  1  0     0  0
  4  5  1  0     0  0
  5  6  1  0     0  0
  6  7  1  0     0  0
M  RGP  1   4   1
M  END
)";

extern "C" const char* issue269test_RGroupsWarning_response = R"([{"code":20,"message":"Structure contains R-groups"}])";

extern "C" const char* issue269test_ChiralityWarning = R"(
  Ketcher  1142115512D 1   1.00000     0.00000     0

 10 10  0     1  0            999 V2000
   11.1577   -6.2248    0.0000 O   0  0  0  0  0  0  0  0  0  0  0  0
   11.1577   -8.2251    0.0000 O   0  0  0  0  0  0  0  0  0  0  0  0
    9.4193   -9.2252    0.0000 O   0  0  0  0  0  0  0  0  0  0  0  0
    7.6923   -8.2251    0.0000 O   0  0  0  0  0  0  0  0  0  0  0  0
    9.4193   -6.2248    0.0000 O   0  0  0  0  0  0  0  0  0  0  0  0
   10.2886   -6.7249    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0
   10.2886   -7.7248    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0
    9.4193   -8.2251    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0
    8.5613   -7.7248    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0
    8.5613   -6.7249    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0
  5 10  1  0     0  0
 10  9  1  0     0  0
  9  8  1  0     0  0
  8  7  1  0     0  0
  7  6  1  0     0  0
  6  5  1  0     0  0
  6  1  1  6     0  0
  7  2  1  1     0  0
  8  3  1  6     0  0
  9  4  1  6     0  0
M  END
)";

extern "C" const char* issue269test_ChiralityWarning_response = R"([{"code":31,"message":"Structure contains chirality"}])";

extern "C" const char* issue269test_StereochemistryWarning = R"(
  Ketcher  1142115472D 1   1.00000     0.00000     0

 10  9  0     0  0            999 V2000
    6.3750   -5.9750    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0
    7.2410   -6.4750    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0
    8.1071   -5.9750    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0
    8.9731   -6.4750    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0
    9.8391   -5.9750    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0
   10.7051   -6.4750    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0
   11.5712   -5.9750    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0
   12.4372   -6.4750    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0
    9.8391   -4.9750    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0
    9.8391   -6.9750    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0
  1  2  1  0     0  0
  2  3  1  0     0  0
  3  4  1  0     0  0
  4  5  1  0     0  0
  5  6  1  0     0  0
  6  7  1  0     0  0
  7  8  1  0     0  0
  5  9  1  6     0  0
  5 10  1  1     0  0
M  END
)";

extern "C" const char* issue269test_StereochemistryWarning_response =
    R"([{"code":11,"message":"Structure contains stereocenters defined by 3D coordinates","ids":[0,1,2,3,4,5,6,7,8,9]}])";

extern "C" const char* issue269test_PseudoatomWarning = R"(
  Ketcher  1142115522D 1   1.00000     0.00000     0

  8  7  0     0  0            999 V2000
    6.0000   -6.8000    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0
    6.8660   -7.3000    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0
    7.7321   -6.8000    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0
    8.5981   -7.3000    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0
    9.4641   -6.8000    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0
   10.3301   -7.3000    0.0000 HAR 0  0  0  0  0  0  0  0  0  0  0  0
   11.1962   -6.8000    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0
   12.0622   -7.3000    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0
  1  2  1  0     0  0
  2  3  1  0     0  0
  3  4  1  0     0  0
  4  5  1  0     0  0
  5  6  1  0     0  0
  6  7  1  0     0  0
  7  8  1  0     0  0
M  END
)";

extern "C" const char* issue269test_PseudoatomWarning_response = R"([{"code":8,"message":"Structure contains pseudoatoms","ids":[5]}])";

extern "C" const char* issue269test_RadicalWarning = R"(
  Ketcher  1142115482D 1   1.00000     0.00000     0

  8  7  0     0  0            999 V2000
    4.6250   -7.1750    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0
    5.4910   -7.6750    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0
    6.3571   -7.1750    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0
    7.2231   -7.6750    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0
    8.0891   -7.1750    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0
    8.9551   -7.6500    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0
    9.8212   -7.1750    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0
   10.6872   -7.6750    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0
  1  2  1  0     0  0
  2  3  1  0     0  0
  3  4  1  0     0  0
  4  5  1  0     0  0
  5  6  1  0     0  0
  6  7  1  0     0  0
  7  8  1  0     0  0
M  RAD  3   2   2   4   1   6   3
M  END
)";

extern "C" const char* issue269test_RadicalWarning_response = R"([{"code":6,"message":"Structure contains radicals","ids":[1,3,5]}])";

extern "C" const char* issue269test_QueryWarning = R"(
  Ketcher  1142115462D 1   1.00000     0.00000     0

 11 10  0     0  0            999 V2000
    6.0250   -8.2000    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0
    6.8910   -8.7000    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0
    7.7571   -8.2000    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0
    8.6231   -8.7000    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0
    9.4891   -8.2000    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0
   10.3551   -8.7000    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0
   11.2212   -8.2000    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0
   12.0872   -8.7000    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0
   12.9532   -8.2000    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0
   13.8192   -8.7000    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0
   14.6853   -8.2000    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0
  1  2  8  0     0  0
  2  3  1  0     0  0
  3  4  4  0     0  0
  4  5  1  0     0  0
  5  6  5  0     0  0
  6  7  1  0     0  0
  7  8  6  0     0  0
  8  9  1  0     0  0
  9 10  7  0     0  0
 10 11  1  0     0  0
M  END
)";

extern "C" const char* issue269test_QueryWarning_response = R"([{"code":14,"message":"Structure contains query features"}])";

extern "C" const char* issue269test_All = R"(
  SMMXDraw11211110492D

  0  0  0     0  0            999 V3000
M  V30 BEGIN CTAB
M  V30 COUNTS 422 344 11 0 0
M  V30 BEGIN ATOM
M  V30 1 C 17.148 -12.6449 0 0 
M  V30 2 C 17.7896 -13.1664 0 0 CFG=3 
M  V30 3 C 17.6586 -13.9827 0 0 CFG=2 
M  V30 4 C 16.8862 -14.2776 0 0 CFG=2 
M  V30 5 N 16.2447 -13.756 0 0 MASS=14 
M  V30 6 C 16.3756 -12.9396 0 0 CFG=1 
M  V30 7 C 15.734 -12.4181 0 0 
M  V30 8 O 16.7553 -15.0939 0 0 
M  V30 9 C 18.3002 -14.5043 0 0 
M  V30 10 C 18.1692 -15.3207 0 0 
M  V30 11 C 19.0726 -14.2095 0 0 
M  V30 12 C 17.2789 -11.8285 0 0 
M  V30 13 C 18.562 -12.8716 0 0 
M  V30 14 N 15.4722 -14.0508 0 0 MASS=15 
M  V30 15 C 15.3413 -14.8672 0 0 MASS=14 
M  V30 16 C 14.5689 -15.162 0 0 CFG=1 
M  V30 17 C 14.438 -15.9783 0 0 CFG=1 
M  V30 18 C 15.0795 -16.4999 0 0 
M  V30 19 C 14.9486 -17.3162 0 0 
M  V30 20 C 15.5902 -17.8378 0 0 CHG=-1 
M  V30 21 C 14.1761 -17.6111 0 0 CHG=1 
M  V30 22 C 15.8519 -16.2051 0 0 RAD=3 MASS=13 
M  V30 23 C 13.6655 -16.2731 0 0 RAD=2 
M  V30 24 C 13.9274 -14.6405 0 0 RAD=1 
M  V30 25 C 15.9829 -15.3888 0 0 
M  V30 26 C 19.2035 -13.3931 0 0 
M  V30 27 C 25.0307 -10.4954 0 0 
M  V30 28 SDF 24.6174 -11.2115 0 0 
M  V30 29 C 25.0307 -11.9275 0 0 
M  V30 30 SDF 23.7906 -11.2115 0 0 
M  V30 31 C 18.6929 -12.0553 0 0 
M  V30 32 C 19.4653 -11.7605 0 0 ATTCHPT=1 
M  V30 33 C 19.5963 -10.9441 0 0 MASS=11 
M  V30 34 R# 20.3687 -10.6493 0 0 RGROUPS=(1 2) 
M  V30 35 C 21.1411 -10.3544 0 0 MASS=15 
M  V30 36 R# 21.272 -9.5381 0 0 RGROUPS=(1 1) 
M  V30 37 R# 21.7827 -10.876 0 0 RGROUPS=(1 5) 
M  V30 38 C 18.9547 -10.4225 0 0 MASS=10 
M  V30 39 C 14.9616 -12.7129 0 0 CFG=2 
M  V30 40 P 15.8649 -11.6018 0 0 
M  V30 41 N 14.1892 -13.0077 0 0 
M  V30 42 C 14.6668 -11.9405 0 0 
M  V30 43 O 15.2564 -13.4854 0 0 
M  V30 44 C 18.8108 -15.8422 0 0 
M  V30 45 C 17.3968 -15.6155 0 0 
M  V30 46 C 19.5833 -15.5474 0 0 
M  V30 47 C 18.6799 -16.6586 0 0 
M  V30 48 C 29.7552 -10.4403 0 0 
M  V30 49 C 29.3418 -9.7244 0 0 CFG=1 
M  V30 50 C 28.9284 -9.0083 0 0 
M  V30 51 C 28.1017 -9.0083 0 0 
M  V30 52 C 29.7552 -11.8724 0 0 
M  V30 53 C 29.3418 -12.5884 0 0 CFG=2 
M  V30 54 C 28.9284 -13.3044 0 0 
M  V30 55 C 29.3418 -11.1564 0 0 
M  V30 56 C 29.3418 -14.0204 0 0 
M  V30 57 C 28.5151 -11.1564 0 0 CFG=2 
M  V30 58 C 27.6883 -11.1564 0 0 
M  V30 59 C 27.2749 -10.4403 0 0 
M  V30 60 O 27.2749 -11.8724 0 0 
M  V30 61 C 34.0663 -11.2115 0 0 
M  V30 62 C 33.2395 -11.2115 0 0 CFG=2 
M  V30 63 C 32.4128 -11.2115 0 0 
M  V30 64 O 31.9994 -11.9275 0 0 
M  V30 65 C 31.9994 -10.4954 0 0 
M  V30 66 C 34.4797 -10.4954 0 0 
M  V30 67 S 34.4797 -11.9275 0 0 
M  V30 68 C 15.055 -20.9466 0 0 
M  V30 69 C 14.2282 -20.9466 0 0 CFG=1 
M  V30 70 C 13.4014 -20.9466 0 0 
M  V30 71 O 12.988 -21.6626 0 0 
M  V30 72 C 15.4683 -20.2305 0 0 
M  V30 73 S 15.4683 -21.6626 0 0 
M  V30 74 C 19.0264 -21.36 0 0 
M  V30 75 C 19.7424 -21.7734 0 0 
M  V30 76 C 20.4584 -21.36 0 0 
M  V30 77 C 20.4584 -20.5332 0 0 
M  V30 78 C 19.7424 -20.1198 0 0 
M  V30 79 C 19.0264 -20.5332 0 0 
M  V30 80 N 21.2447 -21.6155 0 0 CHG=1 
M  V30 81 C 21.7307 -20.9466 0 0 
M  V30 82 N 21.2447 -20.2777 0 0 
M  V30 83 C 17.5944 -21.36 0 0 
M  V30 84 C 18.3104 -21.7734 0 0 
M  V30 85 C 18.3104 -20.1198 0 0 
M  V30 86 C 17.5944 -20.5332 0 0 
M  V30 87 C 21.5002 -19.4914 0 0 
M  V30 88 C 21.5002 -22.4018 0 0 
M  V30 89 O 24.5256 -20.4983 0 0 CHG=1 
M  V30 90 C 25.1945 -20.9843 0 0 
M  V30 91 C 24.939 -21.7706 0 0 
M  V30 92 C 24.1122 -21.7706 0 0 
M  V30 93 C 23.8567 -20.9843 0 0 
M  V30 94 C 26.383 -13.3579 0 0 
M  V30 95 C 27.099 -13.7713 0 0 
M  V30 96 C 27.099 -14.598 0 0 
M  V30 97 O 26.383 -15.0114 0 0 
M  V30 98 B 25.6669 -14.598 0 0 
M  V30 99 C 25.6669 -13.7713 0 0 
M  V30 100 C 24.5256 -19.6715 0 0 
M  V30 101 C 17.9075 -16.9534 0 0 
M  V30 102 C 17.2659 -16.4318 0 0 
M  V30 103 C 29.7304 -16.197 0 0 
M  V30 104 C 30.5407 -16.3613 0 0 
M  V30 105 C 31.2264 -16.8232 0 0 
M  V30 106 C 31.6832 -17.5123 0 0 
M  V30 107 C 31.8416 -18.3238 0 0 
M  V30 108 C 31.3797 -19.0095 0 0 
M  V30 109 C 31.2154 -19.8198 0 0 
M  V30 110 C 30.5263 -20.2766 0 0 
M  V30 111 C 29.7148 -20.4349 0 0 
M  V30 112 C 29.0291 -19.9731 0 0 
M  V30 113 C 28.2188 -19.8088 0 0 
M  V30 114 C 27.7619 -19.1197 0 0 
M  V30 115 C 27.6036 -18.3082 0 0 
M  V30 116 C 28.0655 -17.6224 0 0 
M  V30 117 C 28.2298 -16.8122 0 0 
M  V30 118 C 28.9189 -16.3553 0 0 
M  V30 119 S 33.318 -15.9056 0 0 
M  V30 120 C 34.0339 -15.4922 0 0 
M  V30 121 N 34.75 -15.9056 0 0 
M  V30 122 C 34.75 -16.7324 0 0 
M  V30 123 C 34.0339 -17.1458 0 0 
M  V30 124 C 33.318 -16.7324 0 0 
M  V30 125 C 34.0339 -14.6654 0 0 
M  V30 126 C 34.0339 -13.8386 0 0 
M  V30 127 C 34.0339 -13.0119 0 0 
M  V30 128 C 13.4036 -8.5831 0 0 
M  V30 129 C 12.8362 -9.1806 0 0 
M  V30 130 C 13.1275 -9.9617 0 0 
M  V30 131 C 13.9267 -9.9617 0 0 
M  V30 132 C 14.6673 -9.823 0 0 
M  V30 133 C 14.236 -9.1096 0 0 
M  V30 134 C 14.9813 -8.5971 0 0 
M  V30 135 C 15.3695 -10.2415 0 0 
M  V30 136 C 15.9762 -9.6667 0 0 
M  V30 137 C 15.8055 -8.8491 0 0 
M  V30 138 C 13.818 -10.7901 0 0 
M  V30 139 C 14.4462 -11.3889 0 0 
M  V30 140 C 15.2234 -11.0802 0 0 
M  V30 141 C 12.3587 -9.9019 0 0 
M  V30 142 C 12.1054 -10.7072 0 0 
M  V30 143 C 12.9843 -10.7901 0 0 
M  V30 144 C 12.273 -8.5175 0 0 
M  V30 145 C 11.8528 -9.0489 0 0 
M  V30 146 C 11.5902 -9.7105 0 0 
M  V30 147 C 13.004 -7.3741 0 0 
M  V30 148 C 12.6051 -7.902 0 0 
M  V30 149 C 13.7412 -7.9055 0 0 
M  V30 150 C 14.1723 -7.3751 0 0 
M  V30 151 C 14.9813 -7.7465 0 0 
M  V30 152 C 11.8442 -7.2747 0 0 
M  V30 153 C 11.5548 -8.0131 0 0 
M  V30 154 C 11.3125 -8.6869 0 0 
M  V30 155 C 10.8884 -9.2606 0 0 
M  V30 156 C 10.5159 -9.9408 0 0 
M  V30 157 C 11.2695 -10.4075 0 0 
M  V30 158 C 10.8887 -11.125 0 0 
M  V30 159 C 11.6962 -11.4526 0 0 
M  V30 160 C 10.1197 -10.6722 0 0 
M  V30 161 C 9.7217 -11.4156 0 0 
M  V30 162 C 10.4488 -11.8391 0 0 
M  V30 163 C 10.3365 -8.6486 0 0 
M  V30 164 C 9.8317 -9.3388 0 0 
M  V30 165 C 9.532 -10.0754 0 0 
M  V30 166 C 10.754 -7.8312 0 0 
M  V30 167 C 9.9911 -7.9344 0 0 
M  V30 168 C 11.1847 -6.1769 0 0 
M  V30 169 C 10.9787 -7.0025 0 0 
M  V30 170 C 11.9596 -6.3896 0 0 
M  V30 171 C 12.6983 -6.0202 0 0 
M  V30 172 C 13.3338 -6.5358 0 0 
M  V30 173 C 13.9502 -6.2878 0 0 
M  V30 174 C 14.4057 -6.6719 0 0 
M  V30 175 C 10.2937 -6.4588 0 0 
M  V30 176 C 9.4976 -6.7343 0 0 
M  V30 177 C 9.3159 -7.5703 0 0 
M  V30 178 C 8.7916 -8.2269 0 0 
M  V30 179 C 8.9902 -9.0874 0 0 
M  V30 180 C 8.1803 -8.8586 0 0 
M  V30 181 C 7.949 -9.6426 0 0 
M  V30 182 C 8.7454 -9.9361 0 0 
M  V30 183 C 8.4303 -10.7386 0 0 
M  V30 184 C 8.8792 -11.4156 0 0 
M  V30 185 C 19.2645 -17.2432 0 0 
M  V30 186 P 19.0505 -18.0418 0 0 CHG=-2 
M  V30 187 P 20.0913 -17.2432 0 0 CHG=2 
M  V30 188 W 22.5846 -15.6997 0 0 CHG=5 
M  V30 189 W 24.1201 -15.6111 0 0 CHG=-5 
M  V30 190 C 24.9173 -17.8553 0 0 
M  V30 191 C 24.0905 -17.8553 0 0 
M  V30 192 C 23.2637 -17.8553 0 0 
M  V30 193 O 22.8503 -18.5713 0 0 
M  V30 194 C 22.8503 -17.1392 0 0 
M  V30 195 C 25.3307 -17.1392 0 0 
M  V30 196 S 25.3307 -18.5713 0 0 
M  V30 197 Ag 51.912 -25.5029 0 0 
M  V30 198 T 40.1825 -10.4037 0 0 
M  V30 199 Ar 50.1716 -13.0836 0 0 
M  V30 200 Xe 50.1131 -15.6241 0 0 
M  V30 201 Mn 44.3999 -18.492 0 0 
M  V30 202 Zn 50.1365 -22.6918 0 0 
M  V30 203 Cu 50.1373 -26.8517 0 0 
M  V30 204 B 40.1867 -11.7274 0 0 
M  V30 205 Kr 50.1524 -14.3538 0 0 
M  V30 206 Pd 50.0956 -19.7864 0 0 
M  V30 207 Rn 50.1048 -17.0003 0 0 
M  V30 208 Pt 50.1248 -21.2687 0 0 
M  V30 209 Cd 50.1407 -24.0916 0 0 
M  V30 210 H 36.1797 -10.4555 0 0 
M  V30 211 Li 36.1906 -11.6772 0 0 
M  V30 212 Na 36.178 -13.0845 0 0 
M  V30 213 K 36.178 -14.3413 0 0 
M  V30 214 Rb 36.1488 -15.6233 0 0 
M  V30 215 Cs 36.1154 -17.0054 0 0 
M  V30 216 Sc 36.1196 -18.5253 0 0 
M  V30 217 Y 36.1154 -19.7864 0 0 
M  V30 218 La 36.1196 -21.2437 0 0 
M  V30 219 Ce 36.1028 -22.6802 0 0 
M  V30 220 Tb 36.1113 -24.0623 0 0 
M  V30 221 Th 36.0862 -25.5697 0 0 
M  V30 222 Bk 36.0862 -26.956 0 0 
M  V30 223 D 38.2868 -10.4371 0 0 
M  V30 224 Be 38.2868 -11.7065 0 0 
M  V30 225 Mg 38.2534 -13.1053 0 0 
M  V30 226 Ca 38.2158 -14.3205 0 0 
M  V30 227 Sr 38.2199 -15.6191 0 0 
M  V30 228 Ba 38.2199 -17.0346 0 0 
M  V30 229 Ti 38.2366 -18.5212 0 0 
M  V30 230 Zr 38.2074 -19.8198 0 0 
M  V30 231 Hf 38.2158 -21.2437 0 0 
M  V30 232 Pr 38.2158 -22.7053 0 0 
M  V30 233 Dy 38.1782 -24.0665 0 0 
M  V30 234 Pa 38.1657 -25.5447 0 0 
M  V30 235 Cf 38.1573 -26.9435 0 0 
M  V30 236 He 50.2042 -10.4161 0 0 
M  V30 237 Ne 50.1749 -11.6864 0 0 
M  V30 238 Al 40.1867 -13.0928 0 0 
M  V30 239 Ga 40.1867 -14.3623 0 0 
M  V30 240 In 40.1575 -15.6358 0 0 
M  V30 241 Tl 40.1867 -17.0388 0 0 
M  V30 242 V 40.1909 -18.5212 0 0 
M  V30 243 Nb 40.1909 -19.8198 0 0 
M  V30 244 Ta 40.1909 -21.2437 0 0 
M  V30 245 Nd 40.1909 -22.7053 0 0 
M  V30 246 Ho 40.1909 -24.0582 0 0 
M  V30 247 U 40.2034 -25.5238 0 0 
M  V30 248 Es 40.17 -26.9269 0 0 
M  V30 249 Fr 42.3037 -10.412 0 0 
M  V30 250 C 42.2912 -11.7148 0 0 
M  V30 251 Si 42.2912 -13.0803 0 0 
M  V30 252 Ge 42.2621 -14.3455 0 0 
M  V30 253 Sn 42.2912 -15.6233 0 0 
M  V30 254 Pb 42.2912 -17.0388 0 0 
M  V30 255 Cr 42.2661 -18.492 0 0 
M  V30 256 Mo 42.2746 -19.8282 0 0 
M  V30 257 W 42.3413 -21.273 0 0 
M  V30 258 Pm 42.333 -22.676 0 0 
M  V30 259 Er 42.3664 -24.0457 0 0 
M  V30 260 Np 42.3706 -25.5655 0 0 
M  V30 261 Fm 42.333 -26.956 0 0 
M  V30 262 Ra 44.3165 -10.4078 0 0 
M  V30 263 N 44.3415 -11.6856 0 0 
M  V30 264 P 44.3582 -13.0803 0 0 
M  V30 265 As 44.3415 -14.3497 0 0 
M  V30 266 Sb 44.3666 -15.6024 0 0 
M  V30 267 Bi 44.3707 -17.0388 0 0 
M  V30 268 Fe 46.4043 -18.4627 0 0 
M  V30 269 Tc 44.425 -19.8323 0 0 
M  V30 270 Re 44.3958 -21.2396 0 0 
M  V30 271 Sm 44.3916 -22.6968 0 0 
M  V30 272 Tm 44.3999 -24.0582 0 0 
M  V30 273 Pu 44.4292 -25.5655 0 0 
M  V30 274 Md 44.4501 -26.9352 0 0 
M  V30 275 Ac 46.4001 -10.412 0 0 
M  V30 276 O 46.4085 -11.6856 0 0 
M  V30 277 S 46.4168 -13.0803 0 0 
M  V30 278 Se 46.4376 -14.3497 0 0 
M  V30 279 Te 46.4085 -15.6233 0 0 
M  V30 280 Po 46.4376 -17.0305 0 0 
M  V30 281 Ni 50.1373 -18.4837 0 0 
M  V30 282 Ru 46.4293 -19.8491 0 0 
M  V30 283 Os 46.4293 -21.2396 0 0 
M  V30 284 Eu 46.4627 -22.6968 0 0 
M  V30 285 Yb 46.4837 -24.0164 0 0 
M  V30 286 Am 46.4711 -25.5363 0 0 
M  V30 287 No 46.5087 -26.9435 0 0 
M  V30 288 Rf 48.2749 -10.4455 0 0 
M  V30 289 F 48.3001 -11.6689 0 0 
M  V30 290 Cl 48.3001 -13.1512 0 0 
M  V30 291 Br 48.2791 -14.3497 0 0 
M  V30 292 I 48.3209 -15.6108 0 0 
M  V30 293 At 48.3001 -17.0013 0 0 
M  V30 294 Co 48.3001 -18.4627 0 0 
M  V30 295 Rh 48.3543 -19.8198 0 0 
M  V30 296 Ir 48.3835 -21.2687 0 0 
M  V30 297 Gd 48.3777 -22.6976 0 0 
M  V30 298 Lu 48.4003 -23.9913 0 0 
M  V30 299 Cm 48.3668 -25.5372 0 0 
M  V30 300 Lr 48.3961 -26.9243 0 0 
M  V30 301 Hg 50.1516 -25.5037 0 0 
M  V30 302 Au 51.9078 -26.9227 0 0 
M  V30 303 C 8.5293 -13.9576 0 0 
M  V30 304 C 9.2453 -13.5442 0 0 
M  V30 305 C 9.9613 -13.9576 0 0 
M  V30 306 C 10.6773 -13.5442 0 0 
M  V30 307 C 11.3933 -13.9576 0 0 
M  V30 308 C 12.1093 -13.5442 0 0 
M  V30 309 N 12.8254 -13.9576 0 0 
M  V30 310 C 9.9613 -14.7843 0 0 
M  V30 311 C 9.2453 -15.1977 0 0 
M  V30 312 C 10.5459 -15.3689 0 0 
M  V30 313 C 9.2453 -16.0245 0 0 
M  V30 314 C 9.8299 -16.6091 0 0 
M  V30 315 N 10.5459 -16.1957 0 0 
M  V30 316 N 7.8132 -13.5442 0 0 
M  V30 317 C 8.5293 -14.7843 0 0 
M  V30 318 C 9.2453 -12.7174 0 0 
M  V30 319 C 10.6773 -12.7174 0 0 
M  V30 320 N 11.3933 -14.7843 0 0 
M  V30 321 C 7.8133 -15.1977 0 0 
M  V30 322 C 7.8133 -16.0245 0 0 
M  V30 323 C 8.5293 -16.4379 0 0 
M  V30 324 C 8.5293 -17.2647 0 0 
M  V30 325 C 7.8133 -17.678 0 0 
M  V30 326 C 7.0973 -17.2647 0 0 
M  V30 327 C 6.3812 -17.678 0 0 
M  V30 328 C 5.6652 -17.2647 0 0 
M  V30 329 C 4.9492 -17.678 0 0 
M  V30 330 C 4.2332 -17.2647 0 0 
M  V30 331 C 4.2332 -16.4379 0 0 
M  V30 332 C 3.5172 -16.0245 0 0 
M  V30 333 C 3.5172 -15.1977 0 0 
M  V30 334 C 4.2332 -14.7843 0 0 
M  V30 335 C 4.2332 -13.9576 0 0 
M  V30 336 C 4.9492 -13.5442 0 0 
M  V30 337 C 4.9492 -12.7174 0 0 
M  V30 338 C 4.2332 -12.304 0 0 
M  V30 339 C 3.5172 -12.7174 0 0 
M  V30 340 C 3.5172 -13.5442 0 0 
M  V30 341 C 2.8012 -13.9576 0 0 
M  V30 342 C 2.0852 -13.5442 0 0 
M  V30 343 C 1.3692 -13.9576 0 0 
M  V30 344 C 1.3692 -14.7843 0 0 
M  V30 345 C 0.6532 -15.1977 0 0 
M  V30 346 C 0.6532 -16.0245 0 0 
M  V30 347 C 1.3692 -16.4379 0 0 
M  V30 348 C 1.3692 -17.2647 0 0 
M  V30 349 C 0.6532 -17.678 0 0 
M  V30 350 C 0.6532 -18.5048 0 0 
M  V30 351 C 1.3692 -18.9182 0 0 
M  V30 352 C 1.3692 -19.745 0 0 
M  V30 353 C 2.0852 -20.1584 0 0 
M  V30 354 C 2.0852 -20.9851 0 0 
M  V30 355 C 2.8012 -21.3985 0 0 
M  V30 356 C 3.5172 -20.9851 0 0 
M  V30 357 C 4.2332 -21.3985 0 0 
M  V30 358 C 4.9492 -20.9851 0 0 
M  V30 359 C 5.6652 -21.3985 0 0 
M  V30 360 C 6.3812 -20.9851 0 0 
M  V30 361 C 7.0973 -21.3985 0 0 
M  V30 362 C 7.8133 -20.9851 0 0 
M  V30 363 C 8.5293 -21.3985 0 0 
M  V30 364 C 9.2453 -20.9851 0 0 
M  V30 365 C 9.9613 -21.3985 0 0 
M  V30 366 C 10.6773 -20.9851 0 0 
M  V30 367 C 11.3933 -21.3985 0 0 
M  V30 368 C 12.1093 -20.9851 0 0 
M  V30 369 C 12.1093 -20.1584 0 0 
M  V30 370 C 12.8253 -19.745 0 0 
M  V30 371 C 12.8727 -20.4034 0 0 
M  V30 372 C 4.2332 -21.3985 0 0 
M  V30 373 C 3.5172 -20.9851 0 0 
M  V30 374 C 4.9492 -20.9851 0 0 
M  V30 375 C 7.0973 -21.3985 0 0 
M  V30 376 C 6.3812 -20.9851 0 0 
M  V30 377 C 7.8133 -20.9851 0 0 
M  V30 378 C 7.0973 -21.3985 0 0 
M  V30 379 C 6.3812 -20.9851 0 0 
M  V30 380 C 7.8133 -20.9851 0 0 
M  V30 381 C 7.0973 -21.3985 0 0 
M  V30 382 C 6.3812 -20.9851 0 0 
M  V30 383 C 7.8133 -20.9851 0 0 
M  V30 384 C 7.0973 -21.3985 0 0 
M  V30 385 C 6.3812 -20.9851 0 0 
M  V30 386 C 7.8133 -20.9851 0 0 
M  V30 387 C 9.9613 -21.3985 0 0 
M  V30 388 C 9.2453 -20.9851 0 0 
M  V30 389 C 10.6773 -20.9851 0 0 
M  V30 390 C 11.3933 -21.3985 0 0 
M  V30 391 C 9.9613 -21.3985 0 0 
M  V30 392 C 9.2453 -20.9851 0 0 
M  V30 393 C 10.6773 -20.9851 0 0 
M  V30 394 C 11.3933 -21.3985 0 0 
M  V30 395 C 9.9613 -21.3985 0 0 
M  V30 396 C 9.2453 -20.9851 0 0 
M  V30 397 C 10.6773 -20.9851 0 0 
M  V30 398 C 11.3933 -21.3985 0 0 
M  V30 399 C 9.9613 -21.3985 0 0 
M  V30 400 C 9.2453 -20.9851 0 0 
M  V30 401 C 10.6773 -20.9851 0 0 
M  V30 402 C 11.3933 -21.3985 0 0 
M  V30 403 C 9.9613 -21.3985 0 0 
M  V30 404 C 9.2453 -20.9851 0 0 
M  V30 405 C 10.6773 -20.9851 0 0 
M  V30 406 C 11.3933 -21.3985 0 0 
M  V30 407 C 9.9613 -21.3985 0 0 
M  V30 408 C 9.2453 -20.9851 0 0 
M  V30 409 C 10.6773 -20.9851 0 0 
M  V30 410 C 11.3933 -21.3985 0 0 
M  V30 411 C 9.9613 -21.3985 0 0 
M  V30 412 C 9.2453 -20.9851 0 0 
M  V30 413 C 10.6773 -20.9851 0 0 
M  V30 414 C 11.3933 -21.3985 0 0 
M  V30 415 C 9.9613 -21.3985 0 0 
M  V30 416 C 9.2453 -20.9851 0 0 
M  V30 417 C 10.6773 -20.9851 0 0 
M  V30 418 C 11.3933 -21.3985 0 0 
M  V30 419 C 9.9613 -21.3985 0 0 
M  V30 420 C 9.2453 -20.9851 0 0 
M  V30 421 C 10.6773 -20.9851 0 0 
M  V30 422 C 11.3933 -21.3985 0 0 
M  V30 END ATOM
M  V30 BEGIN BOND
M  V30 1 1 1 2 
M  V30 2 1 2 3 
M  V30 3 1 3 4 
M  V30 4 1 4 5 
M  V30 5 1 5 6 
M  V30 6 1 1 6 
M  V30 7 1 6 7 CFG=1 
M  V30 8 1 4 8 CFG=1 
M  V30 9 1 3 9 CFG=1 
M  V30 10 1 9 10 
M  V30 11 1 9 11 
M  V30 12 1 1 12 
M  V30 13 1 2 13 CFG=2 
M  V30 14 1 5 14 
M  V30 15 1 14 15 
M  V30 16 1 15 16 
M  V30 17 1 16 17 
M  V30 18 1 17 18 
M  V30 19 2 18 19 
M  V30 20 1 19 20 
M  V30 21 1 19 21 
M  V30 22 1 18 22 
M  V30 23 1 17 23 CFG=1 
M  V30 24 1 16 24 CFG=1 
M  V30 25 1 15 25 
M  V30 26 1 11 26 
M  V30 27 1 27 28 
M  V30 28 1 28 29 
M  V30 29 1 28 30 
M  V30 30 1 13 31 
M  V30 31 2 31 32 
M  V30 32 1 32 33 
M  V30 33 1 33 34 
M  V30 34 1 34 35 
M  V30 35 1 35 36 
M  V30 36 1 35 37 
M  V30 37 1 33 38 
M  V30 38 1 7 39 
M  V30 39 1 7 40 
M  V30 40 1 39 41 
M  V30 41 1 39 42 CFG=1 
M  V30 42 1 39 43 CFG=1 
M  V30 43 1 10 44 
M  V30 44 1 10 45 
M  V30 45 1 44 46 
M  V30 46 1 44 47 
M  V30 47 2 48 49 
M  V30 48 2 49 50 
M  V30 49 1 48 55 
M  V30 50 1 50 51 CFG=1 
M  V30 51 2 52 53 
M  V30 52 2 53 54 
M  V30 53 1 52 55 
M  V30 54 1 54 56 CFG=3 
M  V30 55 2 55 57 
M  V30 56 2 57 58 
M  V30 57 1 58 59 CFG=3 
M  V30 58 1 58 60 
M  V30 59 2 61 62 
M  V30 60 2 62 63 
M  V30 61 1 63 64 
M  V30 62 1 63 65 
M  V30 63 1 61 66 CFG=3 
M  V30 64 1 61 67 
M  V30 65 2 68 69 
M  V30 66)"
                                          R"( 2 69 70 
M  V30 67 1 70 71 
M  V30 68 1 68 72 CFG=1 
M  V30 69 1 68 73 
M  V30 70 1 74 75 
M  V30 71 2 75 76 
M  V30 72 2 77 78 
M  V30 73 1 78 79 
M  V30 74 1 77 82 
M  V30 75 1 77 76 
M  V30 76 1 76 80 
M  V30 77 2 80 81 
M  V30 78 1 81 82 
M  V30 79 2 79 85 
M  V30 80 1 74 79 
M  V30 81 2 84 74 
M  V30 82 1 83 84 
M  V30 83 1 85 86 
M  V30 84 2 83 86 
M  V30 85 1 82 87 
M  V30 86 1 80 88 
M  V30 87 1 89 90 
M  V30 88 2 90 91 
M  V30 89 1 91 92 
M  V30 90 2 92 93 
M  V30 91 1 89 93 
M  V30 92 1 94 95 
M  V30 93 2 95 96 
M  V30 94 1 96 97 
M  V30 95 1 97 98 
M  V30 96 1 98 99 
M  V30 97 2 94 99 
M  V30 98 1 89 100 
M  V30 99 2 47 101 
M  V30 100 1 101 102 
M  V30 101 1 103 104 
M  V30 102 1 104 105 
M  V30 103 1 105 106 
M  V30 104 2 106 107 
M  V30 105 1 107 108 
M  V30 106 2 108 109 
M  V30 107 1 109 110 
M  V30 108 2 110 111 
M  V30 109 1 111 112 
M  V30 110 2 112 113 
M  V30 111 1 113 114 
M  V30 112 2 114 115 
M  V30 113 1 115 116 
M  V30 114 2 116 117 
M  V30 115 1 118 117 CFG=2 
M  V30 116 2 118 103 
M  V30 117 1 119 120 
M  V30 118 1 120 121 
M  V30 119 1 121 122 
M  V30 120 1 122 123 
M  V30 121 3 123 124 
M  V30 122 1 119 124 
M  V30 123 1 120 125 
M  V30 124 3 125 126 
M  V30 125 1 126 127 
M  V30 126 1 133 132 
M  V30 127 1 135 136 
M  V30 128 1 136 137 
M  V30 129 1 134 137 
M  V30 130 1 140 135 
M  V30 131 1 132 135 
M  V30 132 1 132 131 
M  V30 133 1 138 139 
M  V30 134 1 139 140 
M  V30 135 1 143 138 
M  V30 136 1 138 131 
M  V30 137 1 130 131 
M  V30 138 1 142 143 
M  V30 139 1 141 130 
M  V30 140 1 130 129 
M  V30 141 1 140 40 
M  V30 142 1 144 129 
M  V30 143 1 129 128 
M  V30 144 1 149 128 
M  V30 145 1 128 133 
M  V30 146 1 133 134 
M  V30 147 1 134 151 
M  V30 148 1 150 151 
M  V30 149 1 144 148 
M  V30 150 1 145 144 
M  V30 151 1 154 145 
M  V30 152 1 146 145 
M  V30 153 1 146 157 
M  V30 154 1 159 142 
M  V30 155 1 146 141 
M  V30 156 1 142 141 
M  V30 157 1 158 159 
M  V30 158 1 156 157 
M  V30 159 1 158 157 
M  V30 160 1 162 158 
M  V30 161 1 161 162 
M  V30 162 1 160 156 
M  V30 163 1 156 155 
M  V30 164 1 163 155 
M  V30 165 1 155 154 
M  V30 166 1 154 153 
M  V30 167 1 166 153 
M  V30 168 1 153 152 
M  V30 169 1 168 169 
M  V30 170 1 168 170 
M  V30 171 1 171 170 
M  V30 172 1 170 152 
M  V30 173 1 148 152 
M  V30 174 1 148 147 
M  V30 175 1 171 172 
M  V30 176 1 173 172 
M  V30 177 1 172 147 
M  V30 178 1 147 149 
M  V30 179 1 149 150 
M  V30 180 1 150 174 
M  V30 181 1 173 174 
M  V30 182 1 175 169 
M  V30 183 1 166 169 
M  V30 184 1 167 166 
M  V30 185 1 175 176 
M  V30 186 1 176 177 
M  V30 187 1 177 178 
M  V30 188 1 164 163 
M  V30 189 1 177 167 
M  V30 190 1 163 167 
M  V30 191 1 178 179 
M  V30 192 1 179 180 
M  V30 193 1 179 164 
M  V30 194 1 165 164 
M  V30 195 1 180 181 
M  V30 196 1 181 182 
M  V30 197 1 182 183 
M  V30 198 1 165 182 
M  V30 199 1 184 161 
M  V30 200 1 165 160 
M  V30 201 1 161 160 
M  V30 202 1 183 184 
M  V30 203 1 153 144 
M  V30 204 1 155 146 
M  V30 205 1 166 163 
M  V30 206 1 129 141 
M  V30 207 1 169 152 
M  V30 208 1 148 128 
M  V30 209 1 156 164 
M  V30 210 1 160 158 
M  V30 211 1 157 142 
M  V30 212 1 130 143 
M  V30 213 1 133 131 
M  V30 214 1 179 182 
M  V30 215 1 47 185 
M  V30 216 1 185 186 
M  V30 217 1 185 187 
M  V30 218 2 190 191 
M  V30 219 2 191 192 
M  V30 220 1 192 193 
M  V30 221 1 192 194 
M  V30 222 1 190 195 
M  V30 223 1 190 196 
M  V30 224 1 303 304 
M  V30 225 1 304 305 
M  V30 226 1 305 306 
M  V30 227 1 306 307 
M  V30 228 1 307 308 
M  V30 229 1 308 309 
M  V30 230 1 305 310 
M  V30 231)"
                                          R"( 1 310 311 
M  V30 232 2 310 312 
M  V30 233 2 311 313 
M  V30 234 1 313 314 
M  V30 235 2 314 315 
M  V30 236 1 312 315 
M  V30 237 1 303 316 
M  V30 238 1 303 317 
M  V30 239 1 304 318 
M  V30 240 1 306 319 
M  V30 241 1 307 320 
M  V30 242 1 317 321 
M  V30 243 1 321 322 
M  V30 244 1 322 323 
M  V30 245 1 323 324 
M  V30 246 1 324 325 
M  V30 247 1 325 326 
M  V30 248 1 326 327 
M  V30 249 1 327 328 
M  V30 250 1 328 329 
M  V30 251 1 329 330 
M  V30 252 1 330 331 
M  V30 253 1 331 332 
M  V30 254 1 332 333 
M  V30 255 1 333 334 
M  V30 256 1 334 335 
M  V30 257 1 335 336 
M  V30 258 1 336 337 
M  V30 259 1 337 338 
M  V30 260 1 338 339 
M  V30 261 1 339 340 
M  V30 262 1 340 341 
M  V30 263 1 341 342 
M  V30 264 1 342 343 
M  V30 265 1 343 344 
M  V30 266 1 344 345 
M  V30 267 1 345 346 
M  V30 268 1 346 347 
M  V30 269 1 347 348 
M  V30 270 1 348 349 
M  V30 271 1 349 350 
M  V30 272 1 350 351 
M  V30 273 1 351 352 
M  V30 274 1 352 353 
M  V30 275 1 353 354 
M  V30 276 1 354 355 
M  V30 277 1 356 357 
M  V30 278 1 357 358 
M  V30 279 1 358 359 
M  V30 280 1 360 361 
M  V30 281 1 361 362 
M  V30 282 1 362 363 
M  V30 283 1 364 365 
M  V30 284 1 365 366 
M  V30 285 1 366 367 
M  V30 286 1 367 368 
M  V30 287 1 368 369 
M  V30 288 1 369 370 
M  V30 289 1 370 371 
M  V30 290 1 70 371 
M  V30 291 1 373 372 
M  V30 292 1 372 374 
M  V30 293 1 356 374 
M  V30 294 1 373 355 
M  V30 295 1 376 375 
M  V30 296 1 375 377 
M  V30 297 1 377 379 
M  V30 298 1 379 378 
M  V30 299 1 378 380 
M  V30 300 1 380 382 
M  V30 301 1 382 381 
M  V30 302 1 381 383 
M  V30 303 1 383 385 
M  V30 304 1 385 384 
M  V30 305 1 384 386 
M  V30 306 1 360 386 
M  V30 307 1 376 359 
M  V30 308 1 388 387 
M  V30 309 1 387 389 
M  V30 310 1 389 390 
M  V30 311 1 390 392 
M  V30 312 1 392 391 
M  V30 313 1 391 393 
M  V30 314 1 393 394 
M  V30 315 1 394 396 
M  V30 316 1 396 395 
M  V30 317 1 395 397 
M  V30 318 1 397 398 
M  V30 319 1 398 400 
M  V30 320 1 400 399 
M  V30 321 1 399 401 
M  V30 322 1 401 402 
M  V30 323 1 402 404 
M  V30 324 1 404 403 
M  V30 325 1 403 405 
M  V30 326 1 405 406 
M  V30 327 1 406 408 
M  V30 328 1 408 407 
M  V30 329 1 407 409 
M  V30 330 1 409 410 
M  V30 331 1 410 412 
M  V30 332 1 412 411 
M  V30 333 1 411 413 
M  V30 334 1 413 414 
M  V30 335 1 414 416 
M  V30 336 1 416 415 
M  V30 337 1 415 417 
M  V30 338 1 417 418 
M  V30 339 1 418 420 
M  V30 340 1 420 419 
M  V30 341 1 419 421 
M  V30 342 1 421 422 
M  V30 343 1 364 422 
M  V30 344 1 388 363 
M  V30 END BOND
M  V30 BEGIN SGROUP
M  V30 1 SUP 1 ATOMS=(6 310 311 312 313 314 315) XBONDS=(1 230) BRKXYZ=(9 -
M  V30 9.41 -14.37 0 10.51 -14.37 0 0 0 0) BRKXYZ=(9 11.06 -14.27 0 -
M  V30 11.06 -17.12 0 0 0 0) LABEL=PhN ESTATE=E 
M  V30 2 DAT 2 ATOMS=(6 84 74 75 79 85 78) CBONDS=(5 81 70 80 79 73) -
M  V30 FIELDNAME=comment -
M  V30 FIELDDISP="   -1.8442   -1.4984    DR    ALL  1     " -
M  V30 FIELDDATA=Selection 
M  V30 3 SRU 3 ATOMS=(3 111 110 112) XBONDS=(2 110 107) BRKXYZ=(9 28.62 -
M  V30 -20.31 0 28.62 -19.48 0 0 0 0) BRKXYZ=(9 30.87 -19.64 0 30.87 -
M  V30 -20.46 0 0 0 0) CONNECT=HT LABEL=n 
M  V30 4 SRU 4 ATOMS=(2 105 104) XBONDS=(2 101 103) BRKXYZ=(9 30.13 -16.69 0 -
M  V30 30.13 -15.87 0 0 0 0) BRKXYZ=(9 31.87 -17.17 0 31.04 -17.17 0 -
M  V30 0 0 0) CONNECT=HH LABEL=n 
M  V30 5 SRU 5 ATOMS=(1 184) XBONDS=(2 202 199) BRKXYZ=(9 8.24 -11.08 0 9.07 -
M  V30 -11.08 0 0 0 0) BRKXYZ=(9 9.3 -11 0 9.3 -11.83 0 0 0 0) -
M  V30 CONNECT=EU LABEL=n 
M  V30 6 GEN 6 ATOMS=(2 175 176) XBONDS=(2 186 182) BRKXYZ=(9 9.82 -7.15 0 -
M  V30 8.99 -7.15 0 0 0 0) BRKXYZ=(9 10.63 -6.32 0 10.63 -7.15 0 0 0 0) 
M  V30 7 MUL 7 ATOMS=(6 357 356 358 372 373 374) XBONDS=(2 279 294) PATOMS=(3  -
M  V30 357 356 358) BRKXYZ=(9 3.16 -21.61 0 3.16 -20.78 0 0 0 0) BRKXYZ=(9 -
M  V30 5.3 -20.78 0 5.3 -21.61 0 0 0 0) MULT=2 
M  V30 8 MUL 8 ATOMS=(15 361 360 362 375 376 377 378 379 380 381 382 383 384  -
M  V30 385 386) XBONDS=(2 282 307) PATOMS=(3 361 360 362) BRKXYZ=(9 6.02 -
M  V30 -21.61 0 6.02 -20.78 0 0 0 0) BRKXYZ=(9 8.17 -20.78 0 8.17 -
M  V30 -21.61 0 0 0 0) MULT=5 
M  V30 9 MUL 9 ATOMS=(40 365 364 366 367 387 388 389 390 391 392 393 394 395  -
M  V30 396 397 398 399 400 401 402 403 404 405 406 407 408 409 410 411 412  -
M  V30 413 414 415 416 417 418 419 420 421 422) XBONDS=(2 286 344) -
M  V30 PATOMS=(4 365 364 366 367) BRKXYZ=(9 8.88 -21.61 0 8.88 -
M  V30 -20.78 0 0 0 0) BRKXYZ=(9 11.75 -20.78 0 11.75 -21.61 0 0 0 0) -
M  V30 MULT=10 
M  V30 10 SRU 10 ATOMS=(4 327 326 325 328) XBONDS=(2 250 246) BRKXYZ=(9 5.3 -
M  V30 -17.89 0 5.3 -17.06 0 0 0 0) BRKXYZ=(9 8.17 -17.06 0 8.17 -
M  V30 -17.89 0 0 0 0) CONNECT=EU LABEL=Z 
M  V30 11 SRU 11 ATOMS=(1 338) XBONDS=(2 260 259) BRKXYZ=(9 3.87 -12.92 0 -
M  V30 3.87 -12.1 0 0 0 0) BRKXYZ=(9 4.59 -12.1 0 4.59 -12.92 0 0 0 0) -
M  V30 CONNECT=EU LABEL=Z 
M  V30 END SGROUP
M  V30 BEGIN COLLECTION
M  V30 MDLV30/STEABS ATOMS=(2 6 17)
M  V30 MDLV30/STEREL1 ATOMS=(2 3 4)
M  V30 MDLV30/STEREL2 ATOMS=(1 16)
M  V30 MDLV30/STERAC2 ATOMS=(1 39)
M  V30 END COLLECTION
M  V30 END CTAB
M  END
)";

extern "C" const char* issue269test_All_response = R"([{"code":4,"message":"Structure contains RGroup components, so valency could not be checked"},{"code":7,"message":"Structure contains pseudoatoms, so radicals could not be checked"},{"code":8,"message":"Structure contains pseudoatoms","ids":[27,29]},{"code":11,"message":"Structure contains stereocenters defined by 3D coordinates","ids":[399,0,1,393,2,3,387,4,5,397,6,7,407,8,9,401,10,11,395,12,13,405,14,15,415,16,17,409,18,19,403,20,21,413,22,23,24,25,26,411,28,30,31,32,34,419,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,391,56,57,385,58,59,60,61,389,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,314,129,130,260,131,132,318,133,134,312,135,136,258,137,138,268,139,140,262,141,142,256,143,144,266,145,146,276,147,148,270,149,150,264,151,152,274,153,154,284,155,156,278,157,158,272,159,160,161,162,292,163,164,165,166,167,168,290,169,170,300,171,172,294,173,174,288,175,176,298,177,178,308,179,180,302,181,182,296,183,184,306,185,186,316,187,188,310,189,190,304,191,192,378,193,194,324,195,196,382,197,198,376,199,200,322,201,202,332,203,204,326,205,206,320,207,208,330,209,210,340,211,212,334,213,214,328,215,216,338,217,218,348,219,220,342,221,222,336,223,224,282,225,226,356,227,228,286,229,230,280,231,232,354,233,234,364,235,236,358,237,238,352,239,240,362,241,242,372,243,244,366,245,246,360,247,248,370,249,250,380,251,252,374,253,254,368,255,257,259,261,263,265,267,269,271,273,275,277,279,281,283,285,287,289,291,293,295,297,299,301,303,305,307,309,311,313,315,317,319,321,323,325,327,329,331,333,335,337,339,341,343,344,345,346,347,349,350,351,353,355,357,359,361,363,365,367,369,371,373,375,377,379,381,383,384,386,388,390,392,394,396,398,400,402,404,406,408,410,412,414,416,417,418,420,421]},{"code":12,"message":"Structure contains stereocenters with undefined stereo configuration","ids":[0,4,6,8,9,14,32,34,43,81,119,127,128,129,130,131,132,133,134,137,139,140,141,142,143,144,145,146,147,148,149,151,152,153,154,155,156,157,159,160,162,163,164,165,166,168,169,171,176,178,302,181,184,306,304,303,305]},{"code":18,"message":"Structure contains overlapping atoms","ids":[407,391,399,411,403,395,387,363,415,355,419,393,366,389,397,401,405,409,413,417,357,421,385,361,376,379,382,378,359,375,381,384,420,356,371,364,386,390,394,398,402,406,410,414,418,372,360,374,377,380,383,373,365,388,392,396,400,404,408,412,416]},{"code":19,"message":"Structure contains overlapping bonds.","ids":[314,283,324,316,308,328,320,312,332,336,340,318,310,322,326,330,334,338,342]},{"code":20,"message":"Structure contains R-groups"},{"code":21,"message":"Structure contains S-groups"},{"code":23,"message":"Structure has non-zero charge"},{"code":32,"message":"Not implemented yet: check salt"},{"code":33,"message":"Structure supports only Molfile V3000"}])";


extern "C" const char* issue269test_Issue_293_All = R"(
  SMMXDraw04061618152D

 27 26  2  0  0  0  0  0  0  0999 V2000
    6.5709   -4.1572    0.0000 N   0  3  0  0  0  4  0  0  0  0  0  0
    7.3070   -3.7322    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0
    8.0432   -4.1572    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0
    8.7793   -3.7322    0.0000 Q   0  0  0  0  0  0  0  0  0  0  0  0
    9.5154   -4.1572    0.0000 A   0  0  0  0  0  0  0  0  0  0  0  0
   10.2515   -3.7322    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0
   10.9877   -4.1572    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0
   11.7238   -3.7322    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0
   12.4599   -4.1572    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0
   13.1960   -3.7322    0.0000 C   0  0  3  1  0  0  1  0  0  0  0  0
   13.9321   -4.1572    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0
   14.6683   -3.7322    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0
   15.4044   -4.1572    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0
   16.1405   -3.7322    0.0000 C   0  0  3  0  0  0  0  0  0  0  0  0
   16.8766   -4.1572    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0
   17.6128   -3.7322    0.0000 C   0  0  3  0  0  0  0  0  0  0  0  0
   18.3489   -4.1572    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0
   19.0850   -3.7322    0.0000 C   0  4  0  0  0  0  0  0  0  0  0  0
    9.5154   -5.0072    0.0000 C   0  0  3  0  0  0  0  0  0  0  0  0
    8.7793   -5.4322    0.0000 L   0  0  0  0  0  0  0  0  0  0  0  0
   10.2515   -5.4322    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0
   10.2515   -6.2822    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0
   10.9877   -6.7072    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0
   10.9877   -7.5572    0.0000 C   1  0  0  0  0  0  0  0  0  0  0  0
   11.7238   -7.9822    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0
   11.7238   -8.8322    0.0000 C   0  0  0  0  0  0  0  0  0  0  0  0
   12.4599   -9.2572    0.0000 L   0  0  0  0  0  0  0  0  0  0  0  0
  1  2  1  0  0  0  0
  2  3  1  0  0  0  0
  3  4  1  0  0  0  0
  4  5  1  0  0  0  0
  5  6  1  0  0  0  0
  6  7  1  0  0  0  0
  7  8  1  0  0  0  0
  8  9  1  0  0  0  0
  9 10  1  0  0  0  0
 10 11  1  0  0  0  0
 11 12  1  0  0  0  0
 12 13  1  0  0  0  0
 13 14  1  0  0  0  0
 14 15  1  0  0  0  0
 15 16  1  0  0  0  0
 16 17  1  0  0  0  0
 17 18  1  0  0  0  0
  5 19  1  0  0  0  0
 19 20  1  0  0  0  0
 19 21  1  0  0  0  0
 21 22  1  0  0  0  0
 22 23  1  0  0  0  0
 23 24  1  0  0  0  0
 24 25  1  0  0  0  0
 25 26  1  0  0  0  0
 26 27  1  0  0  0  0
 20 F    5   6   7   8   9  17
 27 T    5   6   7   5  13  31
M  CHG  1   1   1
M  RAD  3  14   3  16   1  18   2
M  ISO  1  24  13
M  RBC  4   6  -1  21   4  23   3  25   2
M  SUB  1  12   2
M  UNS  1   8   1
M  ALS  20  7 F C   N   O   F   Cl  Br  I   
M  ALS  27  5 T C   N   B   Al  Ga  
M  END
)";

extern "C" const char* issue269test_Issue_293_All_response = R"([{"code":6,"message":"Structure contains radicals","ids":[13,15,17]},{"code":14,"message":"Structure contains query features"}])";
