#include <iostream>
#include "simple_stat.h"


int main()
{
    // *** TEST Default Constructor *** //
    Simple_stat<double> l;
    l.append(16.5);
    l.append(2.5);
    l.append(3.3);
    l.append(4.10);
    std::cout << "< Check l data >" << std::endl;
    std::cout << " Index test: " << l[3] << std::endl;
    l.check_data();


    // **** TEST CONSTRUCTOR FOR VECTOR AND ARRAY **** //

    //  Test vector
    std::vector<double> vect;
    vect.push_back(10.1);
    vect.push_back(20.2);
    vect.push_back(30.5);
    vect.push_back(15.3);
    vect.push_back(20.2);
    Simple_stat<double> l3(vect);
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
    Simple_stat<double> l4(s);
    std::cout << "\n Check l4 data >" << std::endl;
    l4.check_data();

    std::cout << "\n Feed l4 with vect data" << std::endl;
    l4.feed(vect);

    std::cout << "\n Re-checking l4 data >" << std::endl;
    l4.check_data();


    std::cout << "\n< Check l4 data after running empty() >" << std::endl;
    l4.empty();
    l4.check_data();

    // Test an array
    int size = 10;
    double arr_double [size] = { 16.5, 2.2, 77.9, 40.15, 30, 40.15, 52, 39, 16.5, 16.5 };
    Simple_stat<double> l2(arr_double, size);
    std::cout << "\n< Check l2 data >" << std::endl;
    l2.check_data();
    l2.search(16.5);

    // Test std::array
    std::array<double, 10> arr{ 16.5, 2.2, 77.9, 40.15, 30, 40.15, 52, 39, 16.5, 16.5 };
    Simple_stat<double> l5(arr);
    std::cout << "\n Check l5 data >" << std::endl;
    l5.check_data();
    l5.search(16.5);

    std::cout << "\n Testing l5 getters >" << std::endl;
    std::cout << "Length: " << l5.length_total() << std::endl;
    std::cout << "Min: " << l5.get_min() << std::endl;
    std::cout << "Max: " << l5.get_max() << std::endl;
    std::cout << "Mean: " << l5.get_mean() << std::endl;
    std::cout << "Standard Deviation: " << l5.get_SD() << std::endl;
    std::cout << "# of Unique Elements: " << l5.length_unique() << std::endl;
    std::pair<int, int> l5_pair = l5.search(16.5);
    std::cout << "Searching for 16.5: " << std::endl;
    std::cout << "found at index: " << l5_pair.first << "Number of repitions: " << l5_pair.second << std::endl;

    std::cout << "\nRemove 2.2 which was the min: " << std::endl;
    l5.removem(2.2, 1);
    std::cout << "New min: " << l5.get_min() << std::endl;
    std::cout << "New Mean: " << l5.get_mean() << std::endl;
    std::cout << "New Standard Deviation: " << l5.get_SD() << std::endl;

    return 0;
}
