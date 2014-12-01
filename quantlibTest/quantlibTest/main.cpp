#include <ql/time/date.hpp>
#include <iostream>
using namespace QuantLib;

int main (){
    Date date(18, March, 2014);
    std::cout << date << std::endl;
}