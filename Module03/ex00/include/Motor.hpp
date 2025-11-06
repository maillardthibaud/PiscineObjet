
#ifndef __MOTOR_HPP__
#define __MOTOR_HPP__

#include "Injector.hpp"
#include "ExplosionChamber.hpp"
#include "Crankshaft.hpp" 

class Motor
{
    private:

        Injector            injector;
        ExplosionChamber    ec;
        Crankshaft          cr;

        bool                isOn;



    public:

        Motor();
        ~Motor();

        
        Injector*           getInjector();
        Crankshaft*         getCrank();
        ExplosionChamber*   getExplosionChamber();
        
        bool                getIsOn();
        void                StartMotor();
        void                stopMotor();

        void                connectToTransmission(Transmission* p_transmission);

};


#endif