//
//  printerForm.h
//  Practise5
//
//  Created by Hank on 10/28/14.
//  Copyright (c) 2014 Hank. All rights reserved.
//

#ifndef Practise5_printerForm_h
#define Practise5_printerForm_h

class Problem6{
    
public:
    std::string convertToWords(int number);
    std::string print(std::string printerForm[],char const *pchar,int temp);
    std::vector<std::string> split(std::string ret);
    std::string trim(std::string &str);
    bool isnum(std::string s);

};
#endif
