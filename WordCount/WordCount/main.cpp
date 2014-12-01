//
//  main.cpp
//  WordCount
//
//  Created by Hank on 11/23/14.
//  Copyright (c) 2014 Hank. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(int, char **) {
    map<string, int> dict;
    string s;
    while(cin>>s)
        ++dict[s];
    map<string, int>::iterator it=dict.begin();
    for(; it!=dict.end(); ++it)
        cout<<it->first<<": "<<it->second<<" λn"<<"\n";
    return 0;
}
