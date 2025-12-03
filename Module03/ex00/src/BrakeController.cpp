// #include "Brake.cpp"
// #include "LinkablePart.cpp"
// #include <iostream>
// #include <typeinfo>


#include <iostream>
#include <typeinfo>

#include "../include/BrakeController.hpp"
#include "../include/LinkablePart.hpp"

BrakeController::BrakeController() : pression(1.0f), isPark(true)
{
    std::cout << "Constructor " << typeid(this).name() << std::endl;
}

BrakeController::~BrakeController()
{
}

void BrakeController::execute(float p_pression)
{
    std::cout << "->Brake controller execute at : " << p_pression << " bars." << std::endl;
    for (int i = 0; i < 4; i++)
        brakeArr[i].execute(p_pression);
    pression = p_pression;
}

Brake*  BrakeController::getBrake(int idx)
{
    return(&(brakeArr[idx]));
}

float BrakeController::getPression() const
{
    return(pression);
}
bool BrakeController::getIsPark() const
{
    return(isPark);
}
void    BrakeController::setPression(float pres)
{
    pression = pres;
}

void    BrakeController::setIsPark(bool isP)
{
    isPark = isP;
}
void    BrakeController::switchParkingBrake(bool isActive)
{
    if (!isActive)
        pression = 0.0f;
        
    else
        pression = 1.0f;
    setIsPark(isActive);
    execute(pression);
}
