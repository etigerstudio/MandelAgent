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
