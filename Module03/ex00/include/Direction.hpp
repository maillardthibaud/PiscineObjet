#ifndef __DIRECTION_HPP__
#define __DIRECTION_HPP__

#include "Wheel.hpp"
#include "iMovable.hpp"
#include "iTurnable.hpp"
#include "Transmission.hpp"

class Direction
{
    private:

        static const int    NBWHEEL = 4;
        float               directionAngle;

    public:

        Direction();
        ~Direction();

        Wheel   wheel[NBWHEEL];

        void    manageWheels();

        void    turn(float p_angle);
};


#endif
