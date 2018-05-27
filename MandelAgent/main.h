//
//  main.h
//  MandelAgent
//
//  Created by ALuier Bondar on 27/05/2018.
//  Copyright © 2018 E-Tiger Studio. All rights reserved.
//

#ifndef main_h
#define main_h

class complex {
public:
    double real, imag;
    double norm();
};

complex operator*(const complex& c1,const complex& c2);
complex operator+(const complex& c1,const complex& c2);

#endif /* main_h */
