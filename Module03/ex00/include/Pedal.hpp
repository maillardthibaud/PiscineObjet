
#ifndef __PEDAL_HPP__
#define __PEDAL_HPP__

#include "LinkablePart.hpp"

class Pedal
{
    private:
        LinkablePart* lp;

    public:

        Pedal();
        ~Pedal();

        void setTarget(LinkablePart* p_part);
        void use(float p_pression);
};

#endif