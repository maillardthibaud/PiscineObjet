#ifndef __STEERWHEEL_HPP__
#define __STEERWHEEL_HPP__

class DAE;


class SteerWheel
{
    private:

        DAE* dae;

    public:
    
        SteerWheel();
        ~SteerWheel();

        void setDae(DAE* p_dae);

        void turn(float p_angle);
};
#endif