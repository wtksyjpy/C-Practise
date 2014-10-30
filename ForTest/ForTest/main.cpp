//
//  main.cpp
//  ForTest
//
//  Created by Hank on 5/5/14.
//  Copyright (c) 2014 Hank. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
int main()
{
	std::vector<std::string> numberVector;
	
	numberVector.push_back("abc");
	numberVector.push_back("def");
	numberVector.push_back("ghi");

	
    std::string valueToFind = "a";
	
	std::vector<std::string>::iterator position = std::find(numberVector.begin(), numberVector.end(), valueToFind);
	
	std::cout << "The value is " << *position << std::endl;
	
	bool exists = (position != numberVector.end());
	
	if (exists)
	{
		std::cout << "Exists: true" << std::endl;
	}
	else
	{
		std::cout << "Exists: false" << std::endl;
	}
    
	int index = position - numberVector.begin();
	
	std::cout << "Index: " << index << std::endl;
    char buf[10];

    sprintf(buf, "%02d", 0);
    std::cout << "Index: " << buf << std::endl;
    std::string result1 ="00";
    std::string result2 ="00";

    std::string result3 ="00";

    std::cout <<result1+"/"+result2+"/"+result3;
    
    std::vector<int> numVec;
    
    numVec.push_back(1);
    numVec.push_back(2);
    numVec.push_back(3);
    numVec.push_back(4);
    numVec.push_back(5);
    numVec.push_back(6);

    std::cout <<*max_element(numVec.begin(), numVec.begin()+1);
    std::vector<int> numVecTest(numVec.begin()+4, numVec.begin()+5);
    std::cout <<numVecTest[0]<<numVecTest.size();
    
    ofstream file;
    
	file.open("/Users/admin107/Documents/ForTest/ForTest/test.txt");
    
	file<<"Hello file\n"<<75;
    
	file.close();

	return 0;
}