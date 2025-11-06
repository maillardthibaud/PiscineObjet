#ifndef __RECTANGLE_HPP__
#define __RECTANGLE_HPP__

#include "Shape.hpp"

class Rectangle : public Shape
{
    private:

            float   _width;
            float   _height;

    public:

        Rectangle(float width, float height);
        ~Rectangle();

        float    CalculateArea();
        float   CalculPerimeter();
};

#endif