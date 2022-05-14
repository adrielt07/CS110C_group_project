#ifndef SIMPLESTAT_H
#define SIMPLESTAT_H
#include <iostream>
#include "linkenode.h"


template <typename E> 
class SimpleStat {
  private:
    LinkNode<E> *current, *head;
  public:
    SimpleStat();
    void print();
    void append(E val);
};


#endif // LINKENODE_H