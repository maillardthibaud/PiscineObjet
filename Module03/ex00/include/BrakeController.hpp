#ifndef __BRAKECONTROLLER_HPP__
#define __BRAKECONTROLLER_HPP__

#include "Brake.hpp"
#include "LinkablePart.hpp"

class BrakeController : public LinkablePart
{
    private:

        Brake       brakeArr[4];

        float       pression;
        bool        isPark;

    public:

        BrakeController();
        ~BrakeController();


        Brake*      getBrake(int idx);
        float       getPression();
        bool        getIsPark();

        void        setPression(float value);
        void        setIsPark(bool value);

        void        switchParkingBrake(bool isActive);

        void        execute(float p_pression);
};

#endif

