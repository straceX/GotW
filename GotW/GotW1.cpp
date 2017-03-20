/* g++ GotW1.cpp -omain -std=c++11 */

#include <iostream>

int main()
{

    int ival1 = 13;
    int ival2{14}; // C++11
    int ival3(15);
    int ival4;
    int ival5(); // it's a function declaration

    std::cout << ival1 <<std::endl;
    std::cout << ival2 <<std::endl;
    std::cout << ival3 <<std::endl;
    std::cout << ival4 <<std::endl;
    std::cout << ival5 <<std::endl;

    return 0;
}


