//
//  main.cpp
//  Practise
//
//  Created by Hank on 10/28/14.
//  Copyright (c) 2014 Hank. All rights reserved.
//

#define arraysize1(array) (sizeof(array) / sizeof(array[0]))

#include <iostream>
#include "deserter.h"
using namespace std;

int Problem1::getSpyNumber(int patchNumbers[]){
    int spy=5050;
    for (int i=0;i<99;i++){
        spy-=patchNumbers[i];
        
    }
    
    return spy;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int x[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,100};
    
    Problem1 p;
    //cout<<sizeof(x)/sizeof(x[0]);
    cout<<p.getSpyNumber(x);
    return 0;
}
