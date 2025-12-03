#include <iostream>
#include <typeinfo>

#include "../include/DAE.hpp"

DAE::DAE() : force(1.0f)
{
    std::cout << "Constructor " << typeid(this).name() << std::endl;
}

DAE::~DAE()
{
}

void    DAE::setDirection(Direction* p_direction)
{
    direction = p_direction;
}

void DAE::use(float p_angle)
{
    std::cout << "Dae use p_angle " << p_angle << " apply force " << force << " -> Direction.turn " << std::endl;
    float angle = p_angle * force;
    direction->turn(angle);

}