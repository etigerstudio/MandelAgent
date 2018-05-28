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

void renderMandel(double minX, double maxX, double minY, double maxY, int resX, int resY, rgb_pixel defaultColor, rgb_pixel mandelColor, const char* filename){
    image<rgb_pixel> image(resX, resY);
    for (int y=0; y<resY; y++) {
        for (int x=0; x<resX; x++) {
            complex c = complex
            {minX + (maxX-minX) * x/resX,
                minY + (maxY-minY) * y/resY};
            if (isMandel(c)) {
                image.set_pixel(x, y, mandelColor);
            } else {
                image.set_pixel(x, y, defaultColor);
            }
        }
    }
    printf("Render Complete\n");
    image.write(filename);
}

const char* filenameForRank(int rank) {
    char* filename = new char[15];
    sprintf(filename, "mandel%d.png",rank);
    return filename;
}

int initMPI() {
    MPI_Init(NULL, NULL);
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    int name_len;
    MPI_Get_processor_name(processor_name, &name_len);
    printf("Hello world from processor %s, rank %d out of %d processors\n",
           processor_name, world_rank, world_size);
    return world_rank;
}

void deinitMPI() {
    MPI_Finalize();
}

double calcLowerBound(double min, double max, double sum, double order) {
    return min + (max - min) / sum * order;
}

double calcUpperBound(double min, double max, double sum, double lower) {
    return lower + (max - min) / sum ;
}

void renderForRank(int rank) {
    int col = rank % COLS;
    int row = rank / COLS;
    double minX = calcLowerBound(MIN_X, MAX_X, COLS, col);
    double maxX = calcUpperBound(MIN_X, MAX_X, COLS, minX);
    double minY = calcLowerBound(MIN_Y, MAX_Y, ROWS, row);
    double maxY = calcUpperBound(MIN_Y, MAX_Y, ROWS, minY);
    
    renderMandel(minX, maxX, minY, maxY, RESOLUTION, RESOLUTION, BLACK, WHITE, filenameForRank(rank));
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    int rank = initMPI();
    renderForRank(rank);
    deinitMPI();
    return 0;
}
