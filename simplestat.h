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

  public:
    SimpleStat();
    SimpleStat(E *val);
    SimpleStat(std::vector<E> &vec);
    void print();
    void append(E val);
    double get_min();
    void check_data(); // prints size, total, min, mean, etc.
};


#endif // LINKENODE_H