#ifndef __WHELL_HPP__
#define __WHELL_HPP__

#include "iTurnable.hpp"
#include "iMovable.hpp"

class DriverInfo;

enum WheelType
{
    None = 0,

    FrontWheel = 1,

    BackWheel = 2
};

class Wheel : public iTurnable, public iMovable
{
    

    private:

        DriverInfo*     di;
        float           force;
        float           speed;
        float           direction_angle;
        float           brakeForceReceived;
        bool            isPark;
        
    public:


        Wheel();
        ~Wheel();

        WheelType       wt;

        float           getSpeed() const;
        float           getBrakeForce() const;
        float           getDirectAngle() const;
        bool            getIsPark() const;
        DriverInfo*     getDriverInfo();

        void            setBrakeForce(float value);
        void            setDriverInfo(DriverInfo* p_di);

        bool            isParkActive();
        void            manageBrakeForce();
        void            executeRotation(float p_force);
        void            turnWheel(float p_angle);

    
    
};








#endif