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
    E get_min();
    E get_mean();
    E get_max();
    E get_SD();
    int length_total();
    int length_unique();
    int search();
    E operator[](int index);

    // Modifiers
    void append(E val);
    void removem(E val, int m);
    void empty();

    // Helpers
    void update_data(E val);
    void print();
    void check_data(); // prints size, total, min, mean, etc.
};


#endif // LINKENODE_H
