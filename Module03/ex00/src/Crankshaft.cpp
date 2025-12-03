
#include <iostream>
#include <typeinfo>

#include "../include/Crankshaft.hpp"

Crankshaft::Crankshaft() : volume(0.0f)
{
    std::cout << "Constructor " << typeid(this).name() << " volume : " << volume << std::endl;
}

Crankshaft::~Crankshaft()
{
}

void    Crankshaft::setTr(Transmission* t)
{
    tr = t;
}

void Crankshaft::receiveForce(float p_volume)
{
    std::cout << "Crankshaft receiveForce : " << p_volume << std::endl;
    volume = p_volume;
    if (volume == 0.0f)
    {
        tr->setIsActive(false); 
        std::cout <<  "No force appy on Crankshaft, transmission is now inactive" << std::endl;
        std::cout << "The motor is off" << std::endl;
    }
    else if (volume > 0.0f)
    {
        float force = volume;
        tr->activate(force);
    }
}