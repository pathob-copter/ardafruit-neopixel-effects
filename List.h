#pragma once

template<typename T>
struct Node
{
  T item;
  Node<T> *next;
  Node<T> *prev;
};

template<typename T>
class List {

  public:

    List(){};
    ~List(){};

  private:

    uint32_t _size;

    Node<T> *first;
    Node<T> *last;

};

