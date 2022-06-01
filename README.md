# CS110C SimpleStat Project


### This group project utilize a suitable linear data structure dedicated to represent highly duplicated numeric data with very frequent demand for simple statistics (mentioned in the problem statement) as a C++ class template. The data structure will offer O(1) time access to those simple statistics. Updates to this data structure is very rare. So it is ok, if they may be expensive operations like O(n).


## SimpleStat
### A Simple statistics calculator that supports retrieval of standard seviation, max, mean, and min


### Files
File Name | Description
--- | ---
`LinearStructures\*` | Examples of different data structures (such as stack, double linked list, queue, etc)
`linkenode.h` | Base singly linked list structure used by Simple_stat
`simple_stat.h` | Simple_stat class declarations
`main.cpp` | Used to test out Simple_stat's functions (feel free to change or play around with this file)
`archived` | Contains old files used as a reference (class declaration and implementation are in two separate files - doesn't meet the project's requirements so had to archived it).
`CS110C_group_project_UML.pdf` | Class UML diagram


### Methods Available
Methods name | Description | return
--- | --- | ---
`append` | Takes a number and add it at the end of the linked list | `void`
`removem` | Remove m number of a given data element | `void`
`empty` | Deletes all data | `void`
`search` | Returns the location of the first occurrence and number of repetition | `pair<int=index location, int=# of repititions>`
`operator []` | Overloaded [], so you can access the nth index data | `double`
`feed` | takes any c++ containers and adds the data at the end of the linked list | `void`
`unique_set` | Returns all unique elements | `set`
`get_mean` | Returns the mean value in the current entire data set | `double`
`get_SD` | Returns the standard deviation in the current entire data set | `double`
`get_min` | Returns the min value in the current entire data set | `double`
`get_max` | Returns the max value in the current entire data set  | `double`


## Example Usage
```
#include <iostream>
#include "simple_stat.h"

int main()
{
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
    std::cout << "Access index 3: " << l5[3] << std::endl;

    std::pair<int, int> l5_pair = l5.search(16.5);
    std::cout << "Searching for 16.5: " << std::endl;
    std::cout << "found at index: " << l5_pair.first << " Number of repitions: " << l5_pair.second << std::endl;

    std::cout << "\nRemove 2.2 which was the min: " << std::endl;
    l5.removem(2.2, 1);
    std::cout << "New Length: " << l5.length_total() << std::endl;
    std::cout << "New min: " << l5.get_min() << std::endl;
    std::cout << "New Mean: " << l5.get_mean() << std::endl;
    std::cout << "New Standard Deviation: " << l5.get_SD() << std::endl;
    std::cout << "New # of Unique Elements: " << l5.length_unique() << std::endl;
    std::cout << "New Access index 3: " << l5[3] << std::endl;

    return 0;
}
```

### Authors
* Adriel Tolentino | [GitHub](https://github.com/adrielt07)
* Cody Brinkmann | [GitHub](https://github.com/CodyBrinkmann)
* Kellen Zheng | [GitHub](https://github.com/kellenzheng)
