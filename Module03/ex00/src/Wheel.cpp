#include <iostream>
#include <typeinfo>

#include "../include/iTurnable.hpp"
#include "../include/iMovable.hpp"
#include "../include/Wheel.hpp"

Wheel::Wheel() : force(0.0f), speed(0.0f), direction_angle(0.0f), brakeForceReceived(0.0f), isPark(true)
{
    std::cout << "Constructor " << typeid(this).name() << std::endl;
}

Wheel::~Wheel()
{
}
bool    Wheel::isParkActive()
{
    if (brakeForceReceived > 0.99f)
    {
        force = 0.0f;
        speed = 0.0f;
        std::cout << "Heavy Brake detected ! ForceBrake Received : " << brakeForceReceived << " force, Wheel Force : " << force << std::endl;
        return true;
    }
    return false;
}

DriverInfo* Wheel::getDriverInfo()
{
    return (di);
}
void Wheel::manageBrakeForce()
{
    if (brakeForceReceived > 0.0f)
        std::cout << "  Force brake received : " << brakeForceReceived << ", the force rotation was : " << force << " is now : " << force - brakeForceReceived << std::endl;
}
void Wheel::executeRotation(float p_force)
{
    if (isParkActive())
        return ;
    std::cout << "  executeRotation, wheel force was : " << force << " new force : " << p_force << std::endl;
    force = p_force;
    manageBrakeForce();
    if (force > 0.0f)
    {
        speed = (((force - brakeForceReceived )- 0.1) * 100);
        std::cout << "Wheel go at : " << speed << " km/h, angle direction : " << direction_angle << std::endl;
    }
    else if (force < -0.1f)
    {
        speed = (((force + 0.1) * -1) * 100);
        if (speed > 61.0f)
            speed = 61.0f;
        std::cout << "Wheel go backward at : " << speed << " km/h, angle direction : " << direction_angle<< std::endl;
    }
}

void    Wheel::setDriverInfo(DriverInfo* p_di)
{
    di = p_di;
}

float   Wheel::getBrakeForce() const
{
    return (brakeForceReceived);
}

void    Wheel::setBrakeForce(float value)
{
    std::cout << "  Set brake force received by wheel : " << value << std::endl;
    brakeForceReceived = value;
    executeRotation(force);
}

float   Wheel::getSpeed() const
{
    return (speed);
}

void    Wheel::turnWheel(float p_angle)
{
    if (wt == FrontWheel)
    {
        direction_angle = p_angle;
        std::cout << "Apply turn on Front wheel with an angle : " << direction_angle << " degres" << std::endl;
    }
}
float   Wheel::getDirectAngle() const
{
    return (direction_angle);
}

bool    Wheel::getIsPark() const
{
    return (isPark);
}
