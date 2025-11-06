#ifndef __SHAPE_HPP__
#define __SHAPE_HPP__

class Shape
{
    private:

    public:

        Shape();
        virtual ~Shape();

        virtual float  CalculateArea() = 0;
        virtual float  CalculPerimeter() = 0;

};




#endif