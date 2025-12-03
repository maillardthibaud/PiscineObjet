#include <iostream>
#include <typeinfo>

#include "../include/Brake.hpp"

Brake::Brake() : force(1.0f)
{
    std::cout << "Constructor " << typeid(this).name() << std::endl;

}
Brake::~Brake()
{
}

Wheel* Brake::getWheel() const 
{
    return(wheel);
}

float    Brake::getForce() const
{
    return (force);
}

void  Brake::setWheel(Wheel* wh)
{
    wheel = wh;
}

void Brake::execute(float p_force)
{
    std::cout << "  Brake execute by " << p_force << " force" << std::endl;
    force = p_force;
    if (p_force == 0.0f)
    {
        std::cout << "  No force apply on brake" << std::endl;
        wheel->setBrakeForce(p_force);
        return;
    }
    else
    {
        std::cout << "  Apply force " << p_force << " on brake" << std::endl;
        wheel->setBrakeForce(p_force);
    }
}

void Brake::attackWheel(Wheel* p_wheel)
{
    wheel = p_wheel;
}