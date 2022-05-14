#include "simplestat.cpp"

int main()
{
    SimpleStat<int> l;
    l.append(1);
    l.append(2);
    l.append(3);
    l.append(4);
    l.print();
    return 1;
}
