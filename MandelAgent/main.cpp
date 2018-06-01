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

int mandelIter(complex c){
    int count = 0;
    complex z = c;
    while (count<ITERATION && z.norm()<=4) {
        z = z * z + c;
        count++;
    }
    return count;
    //Legacy isMandel():
    /*if(count<ITERATION){
        return false;
    } else {
        return true;
    }*/
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

void renderMandel(double minX, double maxX, double minY, double maxY, int resX, int resY, pixel colorMap[], const char* filename){
    image<rgb_pixel> image(resX, resY);
    for (int y=0; y<resY; y++) {
        for (int x=0; x<resX; x++) {
            complex c = complex
            {minX + (maxX-minX) * x/resX,
                minY + (maxY-minY) * y/resY};
            int it = (mandelIter(c)-1) * COLOR_MAP_COUNT / ITERATION;
//              Faster, but may cause segument fault:
//            image[x][y] = rgb_pixel(colorMap[it].r,
//                                    colorMap[it].g,colorMap[it].b);
            image.set_pixel(x, resY - y - 1, rgb_pixel(colorMap[it].r, colorMap[it].g, colorMap[it].b));
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
    MPI_Init(0, NULL);
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    return world_rank;
}

void deinitMPI() {
    MPI_Finalize();
}

void renderForRank(int rank) {
    int col = rank % COLS;
    int row = rank / COLS;
    double blockX = (MAX_X - MIN_X) / COLS;
    double blockY = (MAX_Y - MIN_Y) / ROWS;
    double minX = MIN_X + blockX * col;
    double maxX = minX + blockX;
    double maxY = MAX_Y - blockY * row;
    double minY = maxY - blockY;
    
    renderMandel(minX, maxX, minY, maxY, RESOLUTION_X,
                 RESOLUTION_Y, colorMap, filenameForRank(rank));
}

void parseArguments(int argc, const char * argv[]){
    if(argc >= 5){
        MIN_X = atof(argv[1]);
        MAX_X = atof(argv[2]);
        MIN_Y = atof(argv[3]);
        MAX_Y = atof(argv[4]);
        if(argc >= 7) {
            RESOLUTION_X = atoi(argv[5]);
            RESOLUTION_Y = atoi(argv[6]);
        }
    }
}

int main(int argc, const char * argv[]) {
    int rank = initMPI();
    parseArguments(argc, argv);
    renderForRank(rank);
    deinitMPI();
    return 0;
}
