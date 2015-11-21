#pragma once

// Abstract Base class

class AbstractBase {

  public:

    static const uint8_t Red   = 0;
    static const uint8_t Green = 1;
    static const uint8_t Blue  = 2;
    static const uint8_t NumPrimColors = 3;

    AbstractBase(){};
    virtual ~AbstractBase() = 0;

};


// List class

template<typename T>
class List {

  public:

    List();
    List(T array[], uint32_t size);
    ~List(){};

    void add(T item);

    T first() const;
    T last() const;
    T get(uint32_t index) const;

    uint32_t size() const;

  private:

    template<typename N>
    class Node
    {
      public:
        Node(N item)
          : _item(item), _prev(NULL), _next(NULL) {};
        Node(N item, Node<N> *prev, Node<N> *next)
          : _item(item), _prev(prev), _next(next) {};

        N _item;
        Node<N> *_next;
        Node<N> *_prev;
    };

    uint32_t _size;

    Node<T>* _first;
    Node<T>* _last;

};


// Color class

class Color {

  public:

    Color();
    Color(uint32_t color);

    uint32_t toInt();
    
    uint8_t red();
    uint8_t green();
    uint8_t blue();

  private:

    uint32_t _color;
    
};

class ColorGenerator
  : AbstractBase
{

  public:

    using AbstractBase::Red;
    using AbstractBase::Green;
    using AbstractBase::Blue;
    using AbstractBase::NumPrimColors;

    ColorGenerator(uint32_t color);
    ~ColorGenerator() {};

    uint32_t getNextColor();
  
  private:

    List<Color> _colors;
    
    uint32_t _primaryColors[NumPrimColors];

};


// List implementation

template<typename T>
List<T>::List()
{
  _first = NULL;
  _last = NULL;
  _size = 0;
}

template<typename T>
List<T>::List(T array[], uint32_t size)
  : List()
{
  for (uint32_t i = 0; i < size; i++)
  {
    add(array[i]);
  }
}

template<typename T>
void List<T>::add(T item)
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

template<typename T>
T List<T>::first() const
{
  return _first->_item;
}

template<typename T>
T List<T>::last() const
{
  return _last->_item;
}

template<typename T>
T List<T>::get(uint32_t index) const
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

  return result->_item;
}

template<typename T>
uint32_t List<T>::size() const
{
  return _size;
}


// Color implementation

Color::Color()
{
  _color = 0;
}

Color::Color(uint32_t color)
{
  _color = color;
}

uint32_t Color::toInt()
{
  return _color;
}

uint8_t Color::red()
{
  // Todo
  return 0;
}

uint8_t Color::green()
{
  // Todo
  return 0;
}

uint8_t Color::blue()
{
  // Todo
  return 0;
}


// Color Generator implementation

ColorGenerator::ColorGenerator(uint32_t color)
{
  Color c(color);
  _colors.add(c);
  /*
  _primaryColors[LightEffect::Red]   = 255;
  _primaryColors[LightEffect::Green] = 0;
  _primaryColors[LightEffect::Blue]  = 0;
  */
}

uint32_t ColorGenerator::getNextColor()
{
  /*
  _primaryColors[_activePrimaryColor]--;
  _primaryColors[(_activePrimaryColor + 1) % NumPrimColors]++;

  if (_primaryColors[_activePrimaryColor] == 0) {
    _activePrimaryColor = (_activePrimaryColor + 1) % NumPrimColors;
  }

  uint8_t newRed   = _primaryColors[Red]   / _divisor[_activeStep];
  uint8_t newGreen = _primaryColors[Green] / _divisor[_activeStep];
  uint8_t newBlue  = _primaryColors[Blue]  / _divisor[_activeStep];

  _activeStep = (_activeStep + 1) % sizeof(_divisor);

  _color = _stripe.Color(newRed, newGreen, newBlue);
  */

  return _colors.get(0).toInt();
}
