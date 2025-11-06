#ifndef __EXPLOSIONCHAMBER_HPP__
#define __EXPLOSIONCHAMBER_HPP__

#include "Crankshaft.hpp"

class ExplosionChamber
{
    private:

        Crankshaft*     cr;
        float           volume;

    public:

        ExplosionChamber();
        ~ExplosionChamber();

        float   getVolume();

        void    setVolume(float vol);
        void    setCrank(Crankshaft* crank);

        void    fill(float p_volume);
};

#endif