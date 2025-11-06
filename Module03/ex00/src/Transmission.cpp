#include <iostream>
#include <typeinfo>

#include "../include/Transmission.hpp"
#include "../include/Wheel.hpp"
#include "../include/GearLever.hpp"


Transmission::Transmission() : forceGiven(0.0f), isVMax(false), isActive(false)
{
    std::cout << "Constructor " << typeid(this).name() << std::endl;
}
void Transmission::addWheel(Direction* d)
{
    for (int i = 0; i < 4; i++) 
    {
        wheelVector.push_back(&(d->wheel[i]));
    }
}

bool Transmission::isEmpty()
{
    if (wheelVector.empty())
    {
        // std::cout << "wheelvector is empty " << std::endl;
        return (true);
    }
    else
    {
        // std::cout << "Wheelvector is not empty, size : " << wheelVector.size() << std::endl;
        return(false);
    }
}

Transmission::~Transmission()
{
}

bool Transmission::checkWheel()
{
    // wheelVector = new Vec
    return (true);
}

void Transmission::activate(float p_force)
{
    if(checkForceReceive(p_force))
    {
        std::vector<Wheel*>::iterator it;
        for (it = wheelVector.begin(); it != wheelVector.end(); it++)
        {
            if (isVMax)
            {
                std::cout << "  Gear on rupton, you reach the max speed for the gear, recalculate transmission force" << std::endl;
                float CheckForce = (((GearLever::getInstance().activeGear()->getVmax()) / 100) + 0.1);
                p_force = CheckForce;
            }
            std::cout << "  Transmission activate rotation on wheel with force : "  << p_force << std::endl;
            (*it)->executeRotation(p_force);
            
        }
    }

}


bool    Transmission::getIsActive()
{
    return (isActive);
}

void    Transmission::setIsActive(bool value)
{
    isActive = value;
}

void    Transmission::setVmax(bool value)
{
    isVMax = value;
}

void    Transmission::setCar(Car* p_car)
{
    car = p_car;
}

bool        Transmission::checkForceReceive(float force)
{
    isActive = true;
    std::cout << "->Transmission is active : " << isActive << " with force : " << forceGiven << " new force give = " << force <<std::endl;
    forceGiven = force;
    GearLever& gl = GearLever::getInstance();
    if (gl.getLevel() == -1)
        forceGiven *= -1;
    if (forceGiven == 0.1f)
    {
        std::cout << "The motor is ready : Injector->Chamber->Crankshaft->Transmision: OK" << std::endl;
        return false;
    }
    return (true);

}

float Transmission::getForce()
{
    return (forceGiven);
}