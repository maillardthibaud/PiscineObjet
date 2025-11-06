#ifndef __CIRCLE_HPP__
#define __IRCLE_HPP__

#include "Shape.hpp"

class Circle : public Shape
{
    private:

        float       _radius;

    public:

        Circle(float radius);
        ~Circle();


        float CalculateArea();
        float CalculPerimeter();
};

#endif