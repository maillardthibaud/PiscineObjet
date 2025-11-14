#include <iostream>
#include "Staff.hpp"

Staff::Staff(std::string name) : Person(name)
{
    std::cout << "staff constructor , name : " << _name << std::endl;
}

Staff::~Staff()
{
    std::cout << "Staff destructor" << std::endl;
}