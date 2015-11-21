#pragma once

template<typename T>
class List {

  public:

    List()
      : _first(NULL)
      , _last(NULL)
      , _size(0)
    {
    };

    List(T array[], uint32_t size)
      : List()
    {
      for (uint32_t i = 0; i < size; i++)
      {
        add(array[i]);
      }
    };
    
    ~List(){};

    void add(T item)
    {
      Node<T>* prev = _last;
      Node<T>* node = new Node<T>(item, prev, NULL);
      _last = node;
      if (prev != NULL)
      {
        prev->_next = node;
      }
      else
      {
        _first = node;
      }
      _size++;
    }

    T first() const
    {
      return _first->item();
    }

    T last() const
    {
      return _last->item();
    }

    T get(uint32_t index)
    {
      if (index > (_size - 1))
      {
        return T();
      }

      Node<T>* result = _first;

      for (uint32_t i = 0; i < index; i++)
      {
        result = result->_next;
      }

      return result->item();
    }

    uint32_t size() const
    {
      return _size;
    }

  private:

    template<typename N>
    class Node
    {
      public:
        Node(N item)
          : _item(item)
          , _prev(NULL)
          , _next(NULL)
        {};
        Node(N item, Node<N> *prev, Node<N> *next)
          : _item(item)
          , _prev(prev)
          , _next(next)
        {};

        T item() const
        {
          return _item;
        }

        N _item;
        Node<N> *_next;
        Node<N> *_prev;
    };

    uint32_t _size;

    Node<T>* _first;
    Node<T>* _last;

};


