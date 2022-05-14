#ifndef SIMPLESTAT_H
#define SIMPLESTAT_H
#include <iostream>
#include "linkenode.h"


template <typename E> 
class SimpleStat {
  private:
    LinkNode<E> *current, *head;
    double min;

  public:
    SimpleStat();
    void print();
    void append(E val);
    double get_min();
};


#endif // LINKENODE_H