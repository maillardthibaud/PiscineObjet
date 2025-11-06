
#ifndef __CRANKSHAFT_HPP__
#define __CRANKSHAFT_HPP__

#include "Transmission.hpp"

class Crankshaft
{
    private:

        Transmission*   tr;
        float           volume;

    public:

        Crankshaft();
        ~Crankshaft();


        Transmission*   getTr();

        void            setTr(Transmission* tr);

        void            receiveForce(float p_volume);
};

#endif