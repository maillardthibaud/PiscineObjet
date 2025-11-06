#include <iostream>
#include <typeinfo>

#include "../include/LinkablePart.hpp"

LinkablePart::LinkablePart()
{
    std::cout << "Constructor " << typeid(this).name() << std::endl;
}

LinkablePart::~LinkablePart()
{
    // std::cout << "Destructor " << typeid(this).name() << std::endl;
}
