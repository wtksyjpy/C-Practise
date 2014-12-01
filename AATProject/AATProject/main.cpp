//
//  main.cpp
//  AATProject
//
//  Created by Hank on 11/25/14.
//  Copyright (c) 2014 Hank. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string trimEnd(string str)
{
    const string &delim =" \t" ;
    string r=str.erase(str.find_last_not_of(delim)+1);
    return r.erase(0,r.find_first_not_of(delim));
}

string trim(string str, string::size_type pos = 0)
{
    static const string delim = "\t\n\r"; //删除空格或者tab<span></span>字符
    pos = str.find_first_of(delim, pos);
    if (pos == string::npos)
        return str;
    return trim(str.erase(pos, 1));
}

int main(int argc, const char * argv[]) {
    // insert code here...
    char buffer[1024];
    fstream in;
    fstream out("/Users/admin107/Downloads/x.csv");
    in.open("/Users/admin107/Downloads/x.html",ios::in);
    int i=0;
    while(!in.eof())
    {
        ++i;
        in.getline(buffer,1024,'\n');
        out<<buffer<<",";
        if(i==11){
            i=0;
            out<<"\n";
        }
    }
    in.close();
    out.close();
    return 0;
}
