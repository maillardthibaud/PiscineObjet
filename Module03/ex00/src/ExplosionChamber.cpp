#include <typeinfo>
#include <iostream>

#include "../include/ExplosionChamber.hpp"


ExplosionChamber::ExplosionChamber() : volume(0.0f)
{
    std::cout << "Constructor " << typeid(this).name() << " volume : " << volume << std::endl;
}

ExplosionChamber::~ExplosionChamber()
{
}


float   ExplosionChamber::getVolume()
{
    return (volume);
}

void   ExplosionChamber::setCrank(Crankshaft* crank)
{
    cr = crank;
}

void    ExplosionChamber::setVolume(float vol)
{
    volume = vol;
}

void ExplosionChamber::fill(float p_volume)
{
    std::cout << "Chamber vol was : " << volume  << " fill with " << p_volume << std::endl;
    volume = p_volume;
    cr->receiveForce(volume);

}
