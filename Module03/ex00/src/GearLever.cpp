#include <typeinfo>
#include <iostream>
#include <sstream>

#include "../include/GearLever.hpp"

GearLever::GearLever()
{
    std::cout << "Constructor " << typeid(this).name() << " " << this << " gear init to " << level << std::endl;
    manageGear();
}

GearLever::~GearLever()
{
}

Gear* GearLever::activeGear()
{
    for(int i = 0; i < 7; i++)
    {
        if (gearArr[i].getIdx() == level)
        {
            return (&gearArr[i]);
        }
    }
    return (NULL);

}
const char* const   GearLever::gearNames[GearLever::NBGEAR] = {
"Reverse", "Neutral", "1er", "2eme", "3eme", "4eme", "5eme"
};

const float GearLever::gearVmax[GearLever::NBGEAR] = {
    61.0f, 0.0f, 61.0f, 84.0f, 110.0f, 140.0f, 198.0f
};

void GearLever::manageGear()
{
    std::cout << "|-> manage gear" << std::endl;
    for (int i = 0; i < 7; i++)
    {
        gearArr[i].idx = i - 1;
        gearArr[i].setName(gearNames[i]);
        gearArr[i].setVmax(gearVmax[i]);
        std::cout << "Gear name  : " << gearArr[i].getName() << std::endl;
    }
}

int     GearLever::getLevel() const
{
    return (level);
}

void     GearLever::increaseLevel()
{
    level++;
}
void     GearLever::decreaseLevel()
{
    level--;
}
void    GearLever::setLevel(int levelIdx)
{
    level = levelIdx;

}

template class Singleton<GearLever>;