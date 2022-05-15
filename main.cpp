#include <iostream>
#include <vector>
#include "simplestat.cpp"


int main()
{
    // *** TEST Default Constructor *** //
    SimpleStat<double> l;
    l.append(16);
    l.append(2.5);
    l.append(3.3);
    l.append(4.10);
    std::cout << "< Check l data >" << std::endl;
    l.check_data();


    // **** TEST CONSTRUCTOR FOR VECTOR AND ARRAY **** //
    // Test an array

    double arr_int [5] = { 16, 2, 77, 40, 30 }; 
    SimpleStat<double> l2(arr_int);
    std::cout << "\n< Check l2 data >" << std::endl;
    l2.check_data();

    //  Test vector
    std::vector<int> vect;
    vect.push_back(10);
    vect.push_back(20);
    vect.push_back(30);
    SimpleStat<int> l3(vect);
    std::cout << "\n< Check l3 data >" << std::endl;
    l3.check_data();
    return 1;
}
