
#ifndef __DAE_HPP__
#define __DAE_HPP__

#include "Direction.hpp"

class DAE
{
    private:


        Direction*  direction;
        float       force;

    public:

        DAE();
        ~DAE();

        void    setDirection(Direction* p_direction);

        void    use(float p_angle);
};



#endif