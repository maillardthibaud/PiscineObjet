#include <iostream>
#include "Staff.hpp"

Staff::Staff(std::string name) : Person(name)
{
}

Staff::~Staff()
{
}
std::string Staff::getName()
{
    return (_name);
}