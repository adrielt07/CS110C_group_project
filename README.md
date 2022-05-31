# CS110C SimpleStat Project


### This group project utilize a suitable linear data structure dedicated to represent highly duplicated numeric data with very frequent demand for simple statistics (mentioned in the problem statement) as a C++ class template. The data structure will offer O(1) time access to those simple statistics. Updates to this data structure is very rare. So it is ok, if they may be expensive operations like O(n).


## SimpleStat
### A Simple statistics calculator that supports retrieval of standard seviation, max, mean, and min


### Files
File Name | Description
--- | ---
`LinearStructures\*` | Examples of different data structures (such as stack, double linked list, queue, etc)
`linkenode.h` | Base singly linked list structure used by simplestat
`simplestat.h` | SimpleStat class declarations
`simplestat.cpp` | SimpleStat implementations
`main.cpp` | Used to test out SimpleStat's functions (feel free to change or play around with this file)


### Methods Available
Methods name | Description | return
--- | --- | ---
`append` | Takes a number and add it at the end of the linked list | `void`
`removem` | Remove m number of a given data element | `void`
`empty` | Deletes all data | `void`
`search` | Returns the location of the first occurrence and repetition | `pair`
`operator []` | Overloaded [], so you can access the nth index data | `double`
`feed` | takes any c++ containers and adds the data at the end of the linked list(work in progress) | `void`
`unique_set` | Returns all unique elements | `set`
`get_mean` | Returns the mean value in the current entire data set | `double`
`get_SD` | Returns the standard deviation in the current entire data set | `double`
`get_min` | Returns the min value in the current entire data set | `double`
`get_max` | Returns the max value in the current entire data set  | `double`


## Example Usage
```
#include <iostream>
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
}
```

### Authors
* Adriel Tolentino | [GitHub](https://github.com/adrielt07)
* Cody Brinkmann | [GitHub](https://github.com/CodyBrinkmann)
* Kellen Zheng | [GitHub](https://github.com/kellenzheng)
