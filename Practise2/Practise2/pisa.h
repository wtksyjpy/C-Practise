//
//  pisa.h
//  Practise2
//
//  Created by Hank on 10/28/14.
//  Copyright (c) 2014 Hank. All rights reserved.
//

#ifndef Practise2_pisa_h
#define Practise2_pisa_h
struct Coordinate {
    double x;
    double y;
    double z;
};

class Problem3{
public:
    bool checkBalconyBeam(Coordinate co1,Coordinate co2,Coordinate co3);
};
#endif
