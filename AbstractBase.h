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

