
#include <iostream>
#include <typeinfo>

#include "../include/DriverInfo.hpp"
#include "../include/Wheel.hpp"
#include "../include/Pedal.hpp"
#include "../include/GearLever.hpp"
#include "../include/Gear.hpp"
#include "../include/BrakeController.hpp"
#include "../include/Motor.hpp"

DriverInfo::DriverInfo() : isTurnOn(false), isPark(true), directionAngle(0.0f), speed(0.0f)
{
    std::cout << "Constructor " << typeid(this).name() << std::endl;
}

DriverInfo::~DriverInfo()
{
}

void    DriverInfo::setIsTurnOn(bool value)
{
    isTurnOn = value;
}

void    DriverInfo::setBrakeController(BrakeController* p_bc)
{
    bc = p_bc;
}

void    DriverInfo::displayDriverInfo()
{
    currentGear = GearLever::getInstance().activeGear();
    isTurnOn = motor->getIsOn();
    isPark = (bc->getIsPark());
    speed = wheel->getSpeed();
    directionAngle = wheel->getDirectAngle();
    std::cout << "The motor is : " << isTurnOn << std::endl;
    std::cout << "The current speedd is : " << speed << " km/h" << std::endl;
    std::cout << "The current gear is : " << currentGear->getName() << std::endl;
    std::cout << "The parking brake is : " <<  isPark << std::endl;
    std::cout << "The angle of the sterring wheel is : " << directionAngle << " degres" << std::endl;
}

void    DriverInfo::setGear(Gear* gear)
{
    currentGear = gear;
}

Gear*   DriverInfo::getGear()
{
    return currentGear;
}


void    DriverInfo::setMotor(Motor* p_motor)
{
    motor = p_motor;
}

void    DriverInfo::setLastPedal(Pedal* pedal)
{
    lastPedalUse = pedal;
}
void    DriverInfo::setWheelInfo(Wheel* wh)
{
    wheel = wh;
    speed = wheel->getSpeed();
    isPark = wheel->getIsPark();
    directionAngle = wheel->getDirectAngle();

}

float    DriverInfo::getCurrentSpeed()
{
    return(speed);
}
