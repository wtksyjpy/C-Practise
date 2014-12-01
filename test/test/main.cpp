//
//  main.cpp
//  test
//
//  Created by Hank on 11/17/14.
//  Copyright (c) 2014 Hank. All rights reserved.
//

#include <iostream>
#include <math.h>

int main() {
    // insert code here...
    double exp=0.0;
    double p=1.0/2500000000.0;

    for (double i=0;i<=0.5;i+=0.00001){
        for (double j=0;j<=0.5;j+=0.00001){
            exp+=sqrt(i*i+j*j);
        }
    }
    exp=p*exp;
    std::cout << exp;
    return 0;
}

