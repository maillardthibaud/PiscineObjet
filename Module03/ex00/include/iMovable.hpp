#ifndef __IMOVABLE_HPP__
#define __IMOVABLE_HPP__

class iMovable
{
    private:

    protected:

        iMovable();

    public:

        virtual ~iMovable();

        virtual void executeRotation(float p_force) = 0;
};


#endif