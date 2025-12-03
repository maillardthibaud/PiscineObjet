#ifndef __BRAKE_HPP__
#define __BRAKE_HPP__

#include "Wheel.hpp"

class Brake
{
    private:

        Wheel*      wheel;
        float       force;

    public:

        Brake();
        ~Brake();

        
        Wheel*      getWheel() const;
        float       getForce() const;

        void        setWheel(Wheel* wh);

        void        execute(float p_force);
        void        attackWheel(Wheel* p_wheel);
};


#endif
