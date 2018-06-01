//
//  colorMap.h
//  MandelAgent
//
//  Created by ALuier Bondar on 30/05/2018.
//  Copyright © 2018 E-Tiger Studio. All rights reserved.
//

#ifndef colorMap_h
#define colorMap_h

struct pixel {
    unsigned char r,g,b;
};

pixel colorMap[256] = {{0,7,100},
    {1,10,104},
    {1,13,107},
    {1,15,110},
    {1,18,113},
    {1,20,116},
    {1,23,120},
    {2,25,123},
    {2,28,126},
    {3,30,129},
    {3,33,132},
    {4,35,135},
    {4,38,138},
    {5,40,141},
    {5,43,144},
    {6,45,147},
    {7,48,150},
    {8,50,153},
    {8,53,155},
    {9,55,158},
    {10,57,161},
    {11,60,163},
    {12,62,166},
    {13,65,169},
    {14,67,171},
    {15,70,174},
    {16,72,176},
    {17,75,178},
    {18,77,181},
    {19,79,183},
    {20,82,185},
    {21,84,187},
    {22,87,189},
    {23,89,191},
    {24,91,193},
    {26,94,195},
    {27,96,196},
    {28,99,198},
    {29,101,200},
    {30,103,201},
    {32,106,202},
    {33,108,204},
    {34,110,205},
    {36,113,206},
    {37,115,207},
    {39,118,209},
    {41,120,210},
    {43,123,211},
    {46,126,212},
    {48,128,214},
    {51,131,215},
    {54,134,216},
    {56,137,217},
    {59,140,218},
    {63,143,219},
    {66,146,221},
    {69,148,222},
    {73,151,223},
    {76,154,224},
    {80,157,225},
    {83,160,226},
    {87,163,227},
    {91,166,228},
    {95,169,229},
    {99,172,230},
    {103,175,231},
    {107,178,232},
    {111,181,233},
    {115,184,234},
    {119,187,235},
    {124,190,236},
    {128,193,237},
    {132,195,238},
    {136,198,239},
    {140,201,240},
    {145,204,241},
    {149,207,242},
    {153,209,242},
    {157,212,243},
    {161,214,244},
    {165,217,245},
    {169,219,245},
    {173,222,246},
    {177,224,247},
    {181,226,248},
    {185,229,248},
    {188,231,249},
    {192,233,249},
    {195,235,250},
    {199,237,250},
    {202,239,251},
    {205,240,251},
    {209,242,252},
    {212,244,252},
    {214,245,253},
    {217,247,253},
    {220,248,254},
    {222,249,254},
    {224,250,254},
    {227,251,254},
    {229,252,255},
    {230,253,255},
    {232,254,255},
    {233,254,255},
    {235,255,255},
    {236,255,255},
    {237,255,255},
    {237,255,255},
    {238,255,255},
    {239,255,255},
    {239,255,254},
    {240,255,252},
    {240,254,250},
    {241,254,248},
    {241,254,245},
    {242,253,242},
    {242,252,239},
    {243,252,235},
    {243,251,231},
    {244,250,227},
    {244,249,222},
    {245,248,217},
    {245,247,212},
    {246,246,207},
    {246,244,201},
    {246,243,195},
    {247,242,189},
    {247,241,183},
    {248,239,177},
    {248,238,171},
    {249,236,164},
    {249,235,158},
    {249,233,151},
    {250,231,145},
    {250,230,138},
    {250,228,131},
    {251,226,124},
    {251,225,118},
    {251,223,111},
    {252,221,104},
    {252,219,98},
    {252,217,91},
    {252,215,85},
    {253,213,78},
    {253,211,72},
    {253,209,66},
    {253,207,60},
    {254,205,55},
    {254,203,49},
    {254,201,44},
    {254,199,39},
    {254,197,34},
    {255,195,29},
    {255,193,25},
    {255,191,21},
    {255,189,17},
    {255,187,14},
    {255,185,11},
    {255,182,8},
    {255,180,6},
    {255,178,4},
    {255,176,2},
    {255,174,1},
    {255,172,1},
    {255,170,0},
    {255,168,0},
    {254,166,0},
    {253,163,0},
    {251,161,0},
    {249,158,0},
    {247,155,0},
    {244,152,0},
    {240,149,0},
    {237,145,0},
    {232,142,0},
    {228,138,0},
    {223,135,0},
    {218,131,0},
    {213,127,0},
    {208,123,0},
    {202,119,0},
    {196,115,0},
    {190,111,0},
    {184,107,0},
    {177,103,0},
    {171,99,0},
    {164,95,0},
    {157,91,0},
    {151,87,0},
    {144,83,0},
    {137,78,0},
    {130,74,0},
    {123,70,0},
    {116,66,0},
    {109,62,0},
    {102,58,0},
    {95,55,0},
    {88,51,0},
    {82,47,0},
    {75,44,0},
    {69,40,0},
    {63,37,0},
    {57,33,0},
    {51,30,0},
    {45,27,0},
    {40,24,0},
    {35,21,0},
    {30,19,0},
    {26,16,0},
    {21,14,0},
    {18,12,0},
    {14,10,0},
    {11,8,0},
    {8,7,0},
    {6,6,0},
    {4,5,0},
    {2,4,0},
    {1,3,0},
    {1,3,0},
    {0,2,0},
    {0,2,0},
    {0,2,0},
    {0,2,0},
    {0,2,0},
    {0,2,0},
    {0,2,0},
    {0,2,0},
    {0,2,0},
    {0,2,0},
    {0,2,0},
    {0,1,0},
    {0,1,0},
    {0,1,0},
    {0,1,0},
    {0,1,0},
    {0,1,0},
    {0,1,0},
    {0,1,0},
    {0,1,0},
    {0,1,0},
    {0,1,0},
    {0,1,0},
    {0,1,0},
    {0,1,0},
    {0,1,0},
    {0,1,0},
    {0,1,0},
    {0,1,0},
    {0,1,0},
    {0,1,0},
    {0,1,0},
    {0,1,0},
    {0,1,0},
    {0,1,0},
    {0,1,0},
    {0,0,0}};

#endif /* colorMap_h */