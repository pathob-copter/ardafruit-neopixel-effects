#pragma once

#ifndef ADAFRUITNEOPIXELEFFECTS_LIST_H
#define ADAFRUITNEOPIXELEFFECTS_LIST_H

#include "Definitions.h"

namespace AdafruitNeopixelEffects
{

  template<typename T>
  class _Node
  {
    public:
      _Node(T item) : _item(item) {};
      _Node(T item, boost::shared_ptr<_Node<T> > prev) : _item(item), _prev(prev) {};
      _Node(T item, boost::shared_ptr<_Node<T> > prev, boost::shared_ptr<_Node<T> > next) : _item(item), _prev(prev), _next(next) {};
  
      T _item;
      boost::shared_ptr<_Node<T> > _next;
      boost::shared_ptr<_Node<T> > _prev;
  };

  // typedef boost::shared_ptr<_Node> Node;
  
  template<typename T>
  class _List
  {
  
    public:
  
      _List();
      _List(T array[], uint32_t size);
      ~_List(){};
  
      void add(T item);
  
      T first() const;
      T last() const;
  
      T iterate();
      T get(uint32_t index) const;
  
      uint32_t size() const;
  
    private:
  
      boost::shared_ptr<_Node<T> > _first;
      boost::shared_ptr<_Node<T> > _last;
      boost::shared_ptr<_Node<T> > _iterate;
  
      uint32_t _size;
  
  };
  
  typedef boost::shared_ptr<_List<Color> > ColorList;
  
}


using namespace AdafruitNeopixelEffects;

template<typename T>
_List<T>::_List()
{
  _size = 0;
}

template<class T>
_List<T>::_List(T array[], uint32_t size)
  : _List()
{
  for (uint32_t i = 0; i < size; i++)
  {
    add(array[i]);
  }
}

template<typename T>
void _List<T>::add(T item)
{
  boost::shared_ptr<_Node<T> > prev = _last;
  // FIXME
  boost::shared_ptr<_Node<T> > node = boost::make_shared<_Node<T> >(item, prev);
  _last = node;
  if (prev)
  {
    prev->_next = node;
  }
  else
  {
    _first = node;
  }
  _size++;
}

template<typename T>
T _List<T>::first() const
{
  return _first->_item;
}

template<typename T>
T _List<T>::last() const
{
  return _last->_item;
}

template<typename T>
T _List<T>::iterate()
{  
  if (_iterate == NULL || _iterate->_next == NULL)
  {
    _iterate = _first;
  }
  else
  {
    _iterate = _iterate->_next;
  }

  return _iterate->_item;
}

template<typename T>
T _List<T>::get(uint32_t index) const
{
  if (index > (_size - 1))
  {
    return T();
  }

  boost::shared_ptr<_Node<T> > result = _first;

  for (uint32_t i = 0; i < index; i++)
  {
    result = result->_next;
  }

  return result->_item;
}

template<typename T>
uint32_t _List<T>::size() const
{
  return _size;
}

#endif
