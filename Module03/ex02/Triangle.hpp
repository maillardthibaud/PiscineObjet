#ifndef __TRIANGLE_HPP__
#define __TRIANGLE_HPP__

#include "Shape.hpp"

class Triangle : public Shape
{
    private:

            float _size1;
            float _size2;
            float _size3;

    public:


        Triangle(float size1, float size2, float size3);
        ~Triangle();


        float   CalculateArea();
        float   CalculPerimeter();
};



#endif