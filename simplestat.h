#ifndef SIMPLESTAT_H
#define SIMPLESTAT_H
#include <iostream>
#include "linkenode.h"


template <typename E> 
class SimpleStat {
  private:
    LinkNode<E> *end, *head;
    int size = 0;
    double total = 0;
    double min;
    double mean;
    double max;

  public:
    // Constructors
    SimpleStat();
    SimpleStat(E *val, int size);
    SimpleStat(std::vector<E> &vec);
    SimpleStat(std::set<E> &s);

    // Getters
    double get_min();
    double get_mean();
    double get_max();
    double get_SD();

    // Modifiers
    void append(E val);

    // Helpers
    void update_data(E val);
    void print();
    void check_data(); // prints size, total, min, mean, etc.
};


#endif // LINKENODE_H