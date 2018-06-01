//
//  main.h
//  MandelAgent
//
//  Created by ALuier Bondar on 27/05/2018.
//  Copyright © 2018 E-Tiger Studio. All rights reserved.
//

#ifndef main_h
#define main_h

#include "colorMap.h"

using namespace png;

int RESOLUTION_X = 400;
int RESOLUTION_Y = 400;

const int ITERATION = 512;
const int COLOR_MAP_COUNT = 256;

const int COLS = 2;
const int ROWS = 2;

//const rgb_pixel WHITE = rgb_pixel(255, 255, 255);
//const rgb_pixel BLACK = rgb_pixel(0, 0, 0);

double MIN_X = -2;
double MAX_X = 1;
double MIN_Y = -1.5;
double MAX_Y = 1.5;

class complex {
public:
    double real, imag;
    double norm();
};

complex operator*(const complex& c1,const complex& c2);
complex operator+(const complex& c1,const complex& c2);

bool isMandel(complex c);
void renderMandel(double minX, double maxX, double minY, double maxY, int resX, int resY, rgb_pixel defaultColor, rgb_pixel mandelColor, char const* filename);

int initMPI();
void parseArguments(int argc, const char * argv[]);
void deinitMPI();

void renderForRank(int rank);
const char* filenameForRank(int rank);

#endif /* main_h */
