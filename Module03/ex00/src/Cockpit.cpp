#include <iostream>
#include <typeinfo>

#include "../include/Cockpit.hpp"

Cockpit::Cockpit() : gl(GearLever::getInstance())
{
    std::cout << "Constructor " << typeid(this).name() << std::endl;
}

Cockpit::~Cockpit()
{
}
Pedal& Cockpit::getPedal()
{
    return (pedal);
}
SteerWheel& Cockpit::getSteer()
{
    return (sw);
}
GearLever& Cockpit::getGearLever()
{
    return (gl);
}

DriverInfo& Cockpit::getDriverInfo()
{
    return (di);
}