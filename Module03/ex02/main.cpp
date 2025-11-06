
#include <iostream>
#include "Shape.hpp"
#include "Rectangle.hpp"
#include "Triangle.hpp"
#include "Circle.hpp"

int main()
{

		
    std::cout << " ---------------------------------------- " << std::endl;
    Shape* rect = new Rectangle(2, 3);
    std::cout << "Area Rectangle = " << rect->CalculateArea() << std::endl;
    std::cout << "Perimeter Rectangle = " << rect->CalculPerimeter() << std::endl;
    std::cout << " ---------------------------------------- " << std::endl;
    Shape* tri = new Triangle(3, 5, 3);
    std::cout << "Area Triangle = " << tri->CalculateArea() << std::endl;
    std::cout << "Perimeter Triangle = " << tri->CalculPerimeter() << std::endl;
    std::cout << " ---------------------------------------- " << std::endl;
    Shape* cir = new Circle(4);
    std::cout << "Area Circle = " << cir->CalculateArea() << std::endl;
    std::cout << "Perimeter Circle = " << cir->CalculPerimeter() << std::endl;
    std::cout << " ---------------------------------------- " << std::endl;


    delete(rect);
    delete(tri);
    delete(cir);
    


    return (0);
}