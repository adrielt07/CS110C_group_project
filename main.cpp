#include <iostream>
#include <bits/stdc++.h>
#include "simplestat.cpp"


int main()
{
    // *** TEST Default Constructor *** //
    SimpleStat<double> l;
    l.append(16.5);
    l.append(2.5);
    l.append(3.3);
    l.append(4.10);
    std::cout << "< Check l data >" << std::endl;
    l.check_data();


    // **** TEST CONSTRUCTOR FOR VECTOR AND ARRAY **** //
    // Test an array
    int size = 5;
    double arr_double [size] = { 16.5, 2.2, 77.9, 40.15, 30 }; 
    SimpleStat<double> l2(arr_double, size);
    std::cout << "\n< Check l2 data >" << std::endl;
    l2.check_data();

    //  Test vector
    std::vector<double> vect;
    vect.push_back(10.1);
    vect.push_back(20.2);
    vect.push_back(30.5);
    SimpleStat<double> l3(vect);
    std::cout << "\n< Check l3 data >" << std::endl;
    l3.check_data();

    // Test Set
    std::set<double> s;
    s.insert(4.3);
    s.insert(5.5);
    s.insert(5.10);
    SimpleStat<double> l4(s);
    std::cout << "\n< Check l4 data >" << std::endl;
    l4.check_data();

    return 0;
}
