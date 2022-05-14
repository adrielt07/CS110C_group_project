#include "simplestat.h"

template <typename E>
SimpleStat<E>::SimpleStat()
{
  current = head = NULL;
}

template <typename E>
void SimpleStat<E>::append(E val)
{
  LinkNode<E> *n = new LinkNode<E>(val);
  if (head == NULL)
  {
    head = n;
    current = head;
    return;
  }
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