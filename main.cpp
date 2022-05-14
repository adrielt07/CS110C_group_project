#include "simplestat.cpp"

int main()
{
    SimpleStat<double> l;
    l.append(6.1);
    l.append(2.5);
    l.append(3.3);
    l.append(4.10);
    std::cout << "Min is: " << l.get_min() << std::endl;
    l.check_data();
    return 1;
}
