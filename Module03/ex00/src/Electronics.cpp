#include <iostream>
#include <typeinfo>

#include "../include/Electronics.hpp"

Electronics::Electronics()
{
    std::cout << "Constructor " << typeid(this).name() << std::endl;
}

Electronics::~Electronics()
{
}

DAE*     Electronics::getDae()
{
    return (&dae);
}