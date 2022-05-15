#include "simplestat.h"

template <typename E>
SimpleStat<E>::SimpleStat()
{
  current = head = NULL;
}

template <typename E>
SimpleStat<E>::SimpleStat(E *val)
{
  current = head = NULL;
  for (int i = 0; i < 5; i++) // We need to account for the size of array
  {
    this->append(val[i]);
  }
}

template <typename E>
SimpleStat<E>::SimpleStat(std::vector<E> &vec)
{
  current = head = NULL;
  for(int i : vec)
    this->append(i);
}

template <typename E>
void SimpleStat<E>::append(E val)
{
  LinkNode<E> *n = new LinkNode<E>(val);
  if (head == NULL)
  {
    head = n;
    current = head;
    min = val;
    total = val;
    size = 1;
    return;
  }
  this->update_data(val);
  current->next = n;
  current = current->next;
}

template <typename E>
void SimpleStat<E>::print()
{
  current = head;
  while(current != NULL)
  {
    std::cout << current->element << " ";
    current = current->next;
  }
}

template <typename E>
double SimpleStat<E>::get_min()
{
    return min;
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
