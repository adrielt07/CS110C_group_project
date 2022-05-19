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
void SimpleStat<E>:: empty(){
    while(head != NULL) {
            end = head;
            head = head->next;
            delete end;
    }
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
E SimpleStat<E>::get_min()
{
    return min;
}

template <typename E>
E SimpleStat<E>::get_max()
{
    return min;
}

template <typename E>
E SimpleStat<E>::get_mean()
{
    return mean;
}

template <typename E>
E SimpleStat<E>::operator[](int index)
{
  int i;
  LinkNode<E> *runner = head;

  if (index > size - 1)
  {
    throw std::out_of_range("Out of range");
  }

  for (int i = 0; i < index; i++)
  {
    runner = runner->next;
  }
  return runner->element;
}


template <typename E>
void SimpleStat<E>::check_data()
{
    std::cout << "Total: " << total << std::endl;
    std::cout << "Size: " << size << std::endl;
    std::cout << "Min: " << this->get_min() << std::endl;
    std::cout << "Max: " << this->get_max() << std::endl;
    std::cout << "Mean: " << this->get_mean() << std::endl;
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
