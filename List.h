#ifndef ADAFRUITNEOPIXELEFFECTS_LIST_H
#define ADAFRUITNEOPIXELEFFECTS_LIST_H

#include "Adafruit_NeoPixel_Effects.h"

namespace AdafruitNeopixelEffects
{

  template<class T>
  class _Node
  {
    public:
      _Node(T item) : _item(item) {};
      _Node(T item, _Node<T>* prev, _Node<T>* next = 0) : _prev(prev), _next(next) {_item = item;};
  
      T _item;
      _Node<T>* _next;
      _Node<T>* _prev;
  };
  
  template<class T>
  class _List
  {
  
    public:
  
      _List();
      _List(T array[], uint32_t size);
      _List(const _List<T>& other);
      ~_List();

      _List& operator=(const _List<T>& other);
  
      void add(T item);
  
      T first() const;
      T last() const;
  
      T iterate();
      T get(uint32_t index) const;
  
      uint32_t size() const;
      bool empty() const;
      
      _Node<T>* _first;
      _Node<T>* _last;
  
    private:

      void copy(const _List<T>& other);
      void clear();
  
      _Node<T>* _iterate;
  
      uint32_t _size;
  
  };
  
}

using namespace AdafruitNeopixelEffects;

template<class T>
_List<T>::_List()
  : _first(0), _last(0), _iterate(0), _size(0)
{
  Serial.println("Create List");
}

template<class T>
_List<T>::_List(T array[], uint32_t size)
  : _first(0), _last(0), _iterate(0), _size(0)
{
  for (uint32_t i = 0; i < size; i++)
  {
    add(array[i]);
  }
}

template<class T>
_List<T>::_List(const _List<T>& other)
{
  //TODO
}

template<class T>
_List<T>::~_List()
{
  clear();
}

template<class T>
_List<T>& _List<T>::operator=(const _List<T>& other)
{
  //TODO
}

template<class T>
void _List<T>::add(T item)
{
//  Serial.print("add: ");
//  Serial.println(item.toInt());
  
  _Node<T>* prev = _last;
  _Node<T>* node = new _Node<T>(item, prev);

//  Serial.print("Node: ");
//  Serial.println(node->_item.toInt());
  
  _last = node;
  if (prev != 0)
  {
    prev->_next = node;
  }
  else
  {
//    Serial.println("_first = node;");
    _first = node;
//    Serial.println(_first->_item.toInt());
  }
  _size++;
}

template<class T>
T _List<T>::first() const
{
  _Node<T>* node = _first;
  T result = node->_item;
//  Serial.print("first: ");
//  Serial.println(result.toInt());
  return result;
}

template<class T>
T _List<T>::last() const
{
  return _last->_item;
}

template<class T>
T _List<T>::iterate()
{  
  if (_iterate == 0 || _iterate->_next == 0)
  {
    _iterate = _first;
  }
  else
  {
    _iterate = _iterate->_next;
  }

  return _iterate->_item;
}

template<class T>
T _List<T>::get(uint32_t index) const
{
  if (index > (_size - 1))
  {
    return T();
  }

  _Node<T>* result = _first;

  for (uint32_t i = 0; i < index; i++)
  {
    result = result->_next;
  }

  return result->_item;
}

template<class T>
uint32_t _List<T>::size() const
{
  return _size;
}

template<class T>
bool _List<T>::empty() const
{
  return size() == 0;
}

template<class T>
void _List<T>::copy(const _List<T>& other)
{
  if (other.empty()) {
    _first = 0;
    _last = 0;
    _iterate = 0;
    return;
  }

  //TODO: Doubly linked list
  
  _Node<T> *pp = other._first;
  _Node<T> *pt = new _Node<T>(pp->_item);
  _first = pt;

  while (pp->_next != 0) {
    pp = pp->_next;
    pt->_next = new _Node<T>(pp->_item);
    pt = pt->_next;
  }
}

template<class T>
void _List<T>::clear()
{
  //TODO: Doubly linked list

  _Node<T> *next, *pp(_first);

  while(pp != 0) {
    next = pp->_next;
    pp->_next = 0;
    delete pp;
    pp = next;
  }

  _first = 0;
}

#endif
