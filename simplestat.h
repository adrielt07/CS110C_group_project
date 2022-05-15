#ifndef SIMPLESTAT_H
#define SIMPLESTAT_H
#include <iostream>
#include "linkenode.h"


template <typename E> 
class SimpleStat {
  private:
    LinkNode<E> *current, *head;
    int size;
    double total;
    double min;
    double mean;
    double max;

  public:
    // Constructors
    SimpleStat();
    SimpleStat(E *val);
    SimpleStat(std::vector<E> &vec);
    
    // Getters
    double get_min();
    double get_mean();
    double get_max();

    // Modifiers
    void append(E val);

    // Helpers
    void update_data(E val);
    void print();
    void check_data(); // prints size, total, min, mean, etc.
};


#endif // LINKENODE_H