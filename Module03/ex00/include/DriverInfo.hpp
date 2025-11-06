
#ifndef __DRIVERINFO_HPP__
#define __DRIVERINFO_HPP__


class Pedal;
class Wheel;
class BrakeController;
class Gear;
class Motor;

class DriverInfo
{
    private:

        Pedal*          lastPedalUse;
        Wheel*          wheel;
        Gear*           currentGear;
        BrakeController* bc;
        Motor*           motor;

        bool            isTurnOn;
        bool            isPark;
        float           directionAngle;
        float           speed;
        float           pedalPressure;
        



    public:

        DriverInfo();
        ~DriverInfo();

        void    displayDriverInfo();
        void    setLastPedal(Pedal* pedal);
        void    setWheelInfo(Wheel* wh);
        void    setBrakeController(BrakeController* p_bc);
        void    setMotor(Motor* p_motor);
        Gear*   getGear();
        void    setGear(Gear* gear);
        void    setIsTurnOn(bool value);

        float     getCurrentSpeed();
};


#endif