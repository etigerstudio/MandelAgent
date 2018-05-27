//
//  main.h
//  MandelAgent
//
//  Created by ALuier Bondar on 27/05/2018.
//  Copyright © 2018 E-Tiger Studio. All rights reserved.
//

#ifndef main_h
#define main_h

using namespace png;

class complex {
public:
    double real, imag;
    double norm();
};

complex operator*(const complex& c1,const complex& c2);
complex operator+(const complex& c1,const complex& c2);

bool isMandel(complex c);
void renderMandel(double minX, double maxX, double minY, double maxY, int resX, int resY, rgb_pixel defaultColor, rgb_pixel mandelColor, char const* filename);

#endif /* main_h */
