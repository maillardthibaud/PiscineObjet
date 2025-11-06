
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

float   Gear::getVmax()
{
    return (vMax);
}

int Gear::getIdx()
{
    return (idx);
}
std::string Gear::getName()
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

int Gear::getDemult()
{
    return (demultiplier);
}