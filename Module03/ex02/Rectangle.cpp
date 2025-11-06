

#include <iostream>
#include "Rectangle.hpp"

Rectangle::Rectangle(float width, float height) : _width(width), _height(height)
{
}

Rectangle::~Rectangle()
{
}


float Rectangle::CalculateArea()
{
    float result = _height * _width;
    return (result);
}

float Rectangle::CalculPerimeter()
{
    float result = (_height * 2) + (_width * 2);
    return (result);
}