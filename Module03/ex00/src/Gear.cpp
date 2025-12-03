
#include <iostream>
#include <typeinfo>

#include "../include/Gear.hpp"

Gear::Gear()
{
    std::cout << "Constructor "<< typeid(this).name() << " idx : " << idx << std::endl;
}

Gear::~Gear()
{
}

float   Gear::getVmax() const
{
    return (vMax);
}

int Gear::getIdx() const
{
    return (idx);
}
std::string Gear::getName() const
{
    return (name);
}

void            Gear::setVmax(float value)
{
    vMax = value;
}
void Gear::setName(std::string setName)
{
    name = setName;   
}

int Gear::getDemult() const
{
    return (demultiplier);
}