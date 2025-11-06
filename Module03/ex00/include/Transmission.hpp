#ifndef __TRANSMISSION_HPP__
#define __TRANSMISSION_HPP__

#include <vector>
#include "Direction.hpp"

class Wheel;
class Direction;
class Car;

class Transmission
{
    private:

        float   forceGiven;
        Car*    car;
        bool    isVMax;
        bool    isActive;

    public:

        std::vector<Wheel*> wheelVector;

        Transmission();
        ~Transmission();

        float   getForce();
        bool    getIsActive();

        void    setCar(Car* car);
        void    setVmax(bool value);
        void    setIsActive(bool value);

        void    addWheel(Direction* d);
        bool    isEmpty();
        bool    checkWheel();
        bool    checkForceReceive(float force);

        void    activate(float p_force);
};


#endif