
#ifndef __ITURNABLE_HPP__
#define __ITURNABLE_HPP__


class iTurnable
{
    private:

    protected:

        iTurnable();

    public:

        virtual ~iTurnable();
        
        virtual void turnWheel(float p_angle) = 0;
};





#endif