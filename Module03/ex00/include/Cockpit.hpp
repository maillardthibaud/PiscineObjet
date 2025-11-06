
#ifndef __COCKPIT_HPP__
#define __COCKPIT_HPP__

#include "Pedal.hpp"
#include "SteerWheel.hpp"
#include "GearLever.hpp"
#include "DriverInfo.hpp"

class Cockpit
{
    private:

        Pedal           pedal;
        SteerWheel      sw;
        DriverInfo      di;
        GearLever&      gl;

    public:

        Cockpit();
        ~Cockpit();

        Pedal&          getPedal();
        SteerWheel&     getSteer();
        GearLever&      getGearLever();
        DriverInfo&     getDriverInfo();
};

#endif