#include "simplestat.h"

template <typename E>
SimpleStat<E>::SimpleStat()
{
  end = head = NULL;
}

template <typename E>
SimpleStat<E>::SimpleStat(E *val, int size)
{
  end = head = NULL;
  for (int i = 0; i < size; i++)
  {
    this->append(val[i]);
  }
}

template <typename E>
SimpleStat<E>::SimpleStat(std::vector<E> &vec)
{
  end = head = NULL;
  for(double i : vec)
    this->append(i);
}

template <typename E>
SimpleStat<E>::SimpleStat(std::set<E> &s)
{
  end = head = NULL;
  for(double i : s)
    this->append(i);
}

template <typename E>
void SimpleStat<E>::append(E val)
{
  LinkNode<E> *n = new LinkNode<E>(val);
  if (head == NULL)
  {
    head = n;
    end = head;
    min = val;
    max = val;
    mean = val / 1;
    total += val;
    size += 1;
    return;
  }
  this->update_data(val);
  end->next = n;
  end = end->next;
}

template <typename E>
void SimpleStat<E>::print()
{
  end = head;
  while(end != NULL)
  {
    std::cout << end->element << " ";
    end = end->next;
  }
}

template <typename E>
double SimpleStat<E>::get_min()
{
    return min;
}

template <typename E>
double SimpleStat<E>::get_mean()
{
    return mean;
}

template <typename E>
void SimpleStat<E>::check_data()
{
    std::cout << "Total: " << total << std::endl;
    std::cout << "Size: " << size << std::endl;
    std::cout << "Min: " << min << std::endl;
    std::cout << "Max: " << max << std::endl;
    std::cout << "Mean: " << mean << std::endl;
}

template <typename E>
void SimpleStat<E>::update_data(E val)
{
  this->total += val;
  this->size += 1;

  this->mean = total / size;
  if (val < this->min)
  {
    this->min = val;
  }
  if (val > this->max)
  {
    this->max = val;
  }
}
