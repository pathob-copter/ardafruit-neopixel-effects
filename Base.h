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


// Node class

template<typename N>
class Node
{
  
  public:
  
    Node(N item) : _item(item), _prev(NULL), _next(NULL) {};
    Node(N item, Node<N> *prev, Node<N> *next) : _item(item), _prev(prev), _next(next) {};

    N _item;
    Node<N> *_next;
    Node<N> *_prev;
    
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

    T iterate();
    T get(uint32_t index) const;

    uint32_t size() const;

  private:

    Node<T>* _first;
    Node<T>* _last;
    Node<T>* _iterate;

    uint32_t _size;

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

    void applyBrightness(uint8_t brightness);

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

    ColorGenerator();
    ColorGenerator(Color color);
    ColorGenerator(uint32_t color);
    ~ColorGenerator() {};

    void addColor(Color color);

    Color getNextColor();
  
  private:

    /** 
     * All colors that has to be gone through 
     */
    List<Color> _colors;

    /**
     * Current (intermediate) color in color generating process
     */
    Color _currentColor;

    // deprecated
    uint32_t _primaryColors[NumPrimColors];

};


// List implementation

template<typename T>
List<T>::List()
{
  _first = NULL;
  _last = NULL;
  _iterate = NULL;
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
T List<T>::iterate()
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
  return (_color >> 16) & 255;
}

uint8_t Color::green()
{
  return (_color >> 8) & 255;
}

uint8_t Color::blue()
{
  return _color & 255;
}

void Color::applyBrightness(uint8_t brightness)
{
  uint8_t r = (red() * brightness) >> 8;
  uint8_t g = (green() * brightness) >> 8;
  uint8_t b = (blue() * brightness) >> 8;

  _color = ((uint32_t)r << 16) | ((uint32_t)g << 8) | b;
}


// Color Generator implementation

ColorGenerator::ColorGenerator()
{
  // Todo
  // Variables are not defined properly with empty constructor
}

ColorGenerator::ColorGenerator(Color color)
{
  _colors.add(color);
  _currentColor = color;
}

ColorGenerator::ColorGenerator(uint32_t colorInt)
{
  Color color(colorInt);
  _colors.add(color);
  _currentColor = color;
}

void ColorGenerator::addColor(Color color)
{
  _colors.add(color);
}

Color ColorGenerator::getNextColor()
{
  Color nextColor;

  // Todo:
  // calculate next color of two generator colors
  // using the actual step between these colors

  return nextColor;
}

