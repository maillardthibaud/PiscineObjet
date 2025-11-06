
#include <iostream>
#include <typeinfo>

#include "../include/SteerWheel.hpp"
#include "../include/DAE.hpp"

SteerWheel::SteerWheel()
{
    std::cout << "Constructor " << typeid(this).name() << std::endl;
    
}

void SteerWheel::setDae(DAE* p_dae)
{
    dae = p_dae;
}
SteerWheel::~SteerWheel()
{
}

void SteerWheel::turn(float p_angle)
{
    std::cout << "SteerWheel turn with angle : " << p_angle << std::endl;
    dae->use(p_angle);
}
