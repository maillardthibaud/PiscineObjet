
#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>

#include "Circle.hpp"

Circle::Circle(float radius) : _radius(radius)
{
}

Circle::~Circle()
{
}


float    Circle::CalculateArea()
{
    float result;
    result = _radius * _radius * M_PI;
    return (result);
}


float    Circle::CalculPerimeter()
{
    float result = 2.0f * M_PI * _radius;
    return (result);

}