#ifndef __ELECTRONIC_HPP__
#define __ELECTRONIC_HPP__

#include "DAE.hpp"

class Electronics
{
    private:

            DAE dae;
    
    public:

        Electronics();
        ~Electronics();

        DAE*     getDae();
};

#endif