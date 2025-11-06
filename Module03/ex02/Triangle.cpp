#include "Triangle.hpp"
#include <iostream>
#include <math.h>

Triangle::Triangle(float size1, float size2, float size3) : _size1(size1), _size2(size2), _size3(size3)
{
}

Triangle::~Triangle()
{
}

float    Triangle::CalculateArea()
{
    float HalfPeri = CalculPerimeter() / 2;
    float result = sqrt(HalfPeri * (HalfPeri - _size1) * (HalfPeri - _size2) * (HalfPeri - _size3));
    return (result);
}

float    Triangle::CalculPerimeter()
{
    float result = _size1 + _size2 + _size3;
    return (result);
}