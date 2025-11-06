#include <iostream>
#include <typeinfo>

#include "../include/Direction.hpp"

Direction::Direction() : directionAngle(0.0f)
{
    std::cout << "Constructor " << typeid(this).name() << std::endl;
    manageWheels();
}


void Direction::manageWheels()
{
    std::cout << "|-> manage wheel" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (i < 2)
            wheel[i].wt = FrontWheel;
        else
            wheel[i].wt = BackWheel;
        
        std::cout << "Whell type : " << wheel[i].wt << std::endl;
    }

}

Direction::~Direction()
{

}

void Direction::turn(float p_angle)
{
    std::cout << "Direction angle was before : " << directionAngle << " degres, its now : " << p_angle << " degres" << std::endl;
    directionAngle = p_angle;
    for (int i = 0; i < NBWHEEL; i++)
    {
        if (wheel[i].wt == FrontWheel)
            wheel[i].turnWheel(p_angle);
    }
}

// Wheel* Direction::getFWheel(int idx)
// {
//     (void)idx;
//     return (wheel[idx]);
// }
// Wheel* Direction::getBWheel(int idx)
// {
//     (void)idx;
//     return (wheel[idx]);
// }