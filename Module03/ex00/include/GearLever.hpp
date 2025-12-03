
#ifndef __GEARLEVER_HPP__
#define __GEARLEVER_HPP__

#include <string>

#pragma once
#include "Singleton.hpp"
#include "Gear.hpp"


class GearLever : public Singleton<GearLever>
{
    
    friend class Singleton<GearLever>;
    private:

        static const int NBGEAR = 7;
        int level;
        
        GearLever();
        ~GearLever();

        static const char* const gearNames[NBGEAR];
        static const float gearVmax[NBGEAR];


    public:

        Gear gearArr[NBGEAR];


        int     getLevel() const;

        void    setLevel(int levelIdx);

        void    increaseLevel();
        void    manageGear();
        void    decreaseLevel();

        Gear*   activeGear();

};


#endif