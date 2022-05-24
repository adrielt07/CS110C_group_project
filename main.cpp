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
    std::cout << " Index test: " << l[3] << std::endl;
    l.check_data();


    // **** TEST CONSTRUCTOR FOR VECTOR AND ARRAY **** //
    // Test an array
    int size = 10;
    double arr_double [size] = { 16.5, 2.2, 77.9, 40.15, 30, 40.15, 52, 39, 16.5, 16.5 };
    SimpleStat<double> l2(arr_double, size);
    std::cout << "\n< Check l2 data >" << std::endl;
    l2.check_data();
    l2.search(16.5);

    //  Test vector
    std::vector<double> vect;
    vect.push_back(10.1);
    vect.push_back(20.2);
    vect.push_back(30.5);
    vect.push_back(15.3);
    vect.push_back(20.2);
    SimpleStat<double> l3(vect);
    std::cout << "\n< Check l3 data >" << std::endl;
    l3.check_data();
    l3.search(20.2);

    // Test Set
    std::set<double> s;
    s.insert(4.3);
    s.insert(5.5);
    s.insert(5.10);
    s.insert(5.5);
    s.insert(4.3);
    s.insert(6.1);
    SimpleStat<double> l4(s);
    std::cout << "\n< Check l4 data >" << std::endl;
    l4.check_data();
    l4.search(10);

    std::cout << "\n< Check l4 data after running empty() >" << std::endl;
    l4.empty();
    l4.check_data();
    return 0;
}
