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
    double SD;

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
    std::set<E> unique_set();
    void search(double val);
    E operator[](int index);

    // Modifiers
    void append(E val, bool recalc_SD=true);
    void removem(E val, int m);
    void empty();
    void calc_SD();

    // Helpers
    double sqrt(double val);
    void print_unique();
    void update_data(E val);
    void print();
    void check_data(); // prints size, total, min, mean, etc.
};


#endif // LINKENODE_H
