//
//  main.cpp
//  MandelAgent
//
//  Created by ALuier Bondar on 27/05/2018.
//  Copyright © 2018 E-Tiger Studio. All rights reserved.
//

#include <iostream>
#include <png++/png.hpp>
#include <mpi.h>
#include "main.h"

using namespace png;

const int RESOLUTION = 400;
const int ITERATION = 1000;
const double X_MIN = -2;
const double X_MAX = 2;
const double Y_MIN = -2;
const double Y_MAX = 2;
const double MIN_X = -2;
const double MAX_X = 1;
const double MIN_Y = -1.5;
const double MAX_Y = 1.5;

const rgb_pixel WHITE = rgb_pixel(255, 255, 255);
const rgb_pixel BLACK = rgb_pixel(0, 0, 0);

bool isMandel(complex c){
    int count = 0;
    complex z = c;
    while (count<ITERATION && z.norm()<=4) {
        z = z * z + c;
        count++;
    }
    if(count<ITERATION){
        return false;
    } else {
        return true;
    }
}

double complex::norm(){
    return this->imag * this->imag + this->real * this->real;
}

complex operator*(const complex& c1,const complex& c2){
    return complex
    {c1.real * c2.real - c1.imag * c2.imag,
        c1.real * c2.imag + c1.imag * c2.real};
}

complex operator+(const complex& c1,const complex& c2){
    return complex
    {c1.real + c2.real, c1.imag + c2.imag};
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
