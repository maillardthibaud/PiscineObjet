
#ifndef __CAR_HPP__
#define __CAR_HPP__

#include "BrakeController.hpp"
#include "Direction.hpp"
#include "Transmission.hpp"
#include "Motor.hpp"
#include "Electronics.hpp"
#include "Cockpit.hpp"

class Car
{
    private:

            GearLever&              gl;  
            float                   currSpeed;

    public:

            BrakeController         bc;
            Direction               direction;
            Transmission            tr;
            Motor                   motor;
            Electronics             elect;
            Cockpit                 cockpit;

            Car();
            ~Car();


            void    Init();
            void    displayGear();
            void    checkBrakePressure();
            void    activeParkingBrake(bool active);
            bool    checkSpeed(float speed);
            void    checkGearSpeed(float speed);

            void    start();
            void    stop();
            void    accelerate(float speed);
            void    shift_gears_up();
            void    shift_gear_down();
            void    reverse();
            void    turn_whell(float angle);
            void    straighten_wheels();
            void    appply_force_on_brakes(float force);
            void    apply_emergency_brakes();


};

#endif