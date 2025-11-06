#include <typeinfo>
#include <iostream>

#include "../include/Motor.hpp"
#include "../include/Transmission.hpp"

Motor::Motor() : isOn(false)
{
    std::cout << "Constructor " << typeid(this).name() << " is on : " << isOn << std::endl;
    injector.setEc(&(ec));
    ec.setCrank(&cr);
}

Motor::~Motor()
{
}


Crankshaft* Motor::getCrank()
{
    return (&cr);
}


bool    Motor::getIsOn()
{
    return (isOn);
}

void Motor::StartMotor()
{
    injector.execute(0.1f);
    isOn = true;
}

void    Motor::stopMotor()
{
    injector.execute(0.0f);
    isOn = false;
}

void Motor::connectToTransmission(Transmission* p_transmission)
{
    cr.setTr(p_transmission);
}

Injector*    Motor::getInjector()
{
    return (&injector);
}

ExplosionChamber*   Motor::getExplosionChamber()
{
    return (&ec);
}