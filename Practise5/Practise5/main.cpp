//
//  main.cpp
//  Practise5
//
//  Created by Hank on 10/28/14.
//  Copyright (c) 2014 Hank. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <string.h>
#include <vector>
#include <ctype.h>
#include "printerForm.h"

using namespace std;

//Take a number and return its string(check-written) form.
string Problem6::convertToWords(int number)
{
    string printerForm[]={"","One","Two", "Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
    
    string s = to_string(number);
    char const *pchar = s.c_str();  //use char const* as target type
    int length=strlen(pchar);
    bool cal1=false,cal2=false,cal3=false;
    
    string ret="";
    if(length>9){
        string temp(ret);
        ret+=print(printerForm,pchar,length-9);
        if(trim(temp).size()!=trim(ret).size())
            ret+=" Billion";
        pchar=s.substr(length-9,9).c_str();
        cal1=true;
    }
    if (length>6){
        string temp(ret);
        if(cal1)
            ret+=print(printerForm,pchar,3);
        else
            ret+=print(printerForm,pchar,length-6);
        
        if(trim(temp).size()!=trim(ret).size())
            
            ret+=" Million";
        pchar=s.substr(length-6,6).c_str();
        cal2=true;
    }
    if (length>3){
        string temp(ret);
        
        if(cal2)
            ret+=print(printerForm,pchar,3);
        else
            ret+=print(printerForm,pchar,length-3);
        if(trim(temp).size()!=trim(ret).size())
            
            ret+=" Thousand";
        pchar=s.substr(length-3,3).c_str();
        cal3=true;
    }
    
    if(cal3)
        ret+=print(printerForm,pchar,3);
    else
        ret+=print(printerForm,pchar,length);
    
    //Implements this, return a string.
    
    vector<string> str_list=split(ret);
    
    ret="";
    for(int i=0;i<str_list.size()-1;i++){
        if(!isnum(str_list[i]))
        ret+=str_list[i]+" ";
    }
    ret+=str_list[str_list.size()-1];
    return ret;
}


string Problem6::print(string printerForm[],char const *pchar,int temp){
    string ret="";
    if (temp==3){
        ret+=" "+printerForm[pchar[0]-'0'];
        if(strlen(ret.c_str())>2)
            ret+=" Hundred";
        if(pchar[1]=='1')
            ret+=" "+printerForm[pchar[2]-'0'+10];
        else if(pchar[1]=='0')
            ret+=" "+printerForm[pchar[2]-'0'];
        else
            ret+=" "+printerForm[pchar[1]-'0'+18]+" "+printerForm[pchar[2]-'0'];
    }
    else if(temp==2){
        ret+=" ";
        if(pchar[0]=='1')
            ret+=printerForm[pchar[1]-'0'+10]+=" ";
        else
            ret+=" "+printerForm[pchar[0]-'0'+18]+" "+printerForm[pchar[1]-'0'];
    }
    else if(temp==1){
        ret+=" ";
        ret+=printerForm[pchar[0]-'0']+" ";
    }
    return ret;
}

vector<string> Problem6::split(string ret){
    vector<string> vret;
    char s[ret.size()];
    strncpy(s,ret.c_str(),ret.size());
    char *p;
    p = strtok(s," ");
    while(p)
    {
        vret.push_back(p);
        p=strtok(NULL, " ");
    }
    
    return vret;
}

string Problem6::trim(string &src)
{
    
    string newStr;
//    for (int i=0;i<src.size();i++){
//        if(src[0]!=' ')
//        {
//            newStr.push_back(src[0]);
//        }
//    }
    
    for(char& ch : src) {
        if(ch!=' ')
        {
            newStr.push_back(ch);
        }
    };
    
//    
//    for_each(src.begin(),src.end(),[&newStr](char ch){
//        if(ch!=' ')
//        {
//            newStr.push_back(ch);
//        }
//    });

    return newStr;
    
}

bool Problem6::isnum(string s)
{
    stringstream sin(s);
    double t;
    char p;
    if(!(sin >> t))
        return false;
    if(sin >> p)
        return false;
    else
        return true;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    Problem6 p;
    cout<<p.convertToWords(1000008)<<endl;
    //    string str="asdfg rewqt asdfsa   ";
    //    vector<string> strv=p.split(str);
    //
    //   // cout<<str;
    //    for(int i=0;i<strv.size()-1;i++){
    //        cout<<strv[i]<<endl;
    //    }
    return 0;
}
