#ifndef __INJECTOR_HPP__
#define __INJECTOR_HPP__

#include "LinkablePart.hpp"
#include "ExplosionChamber.hpp"

class Injector : public LinkablePart
{
    private:

        ExplosionChamber*   ec;

        float               pression;

    public:

        Injector();
        ~Injector();

        float   getPression();

        void    setPression(float s_pression);
        void    setEc(ExplosionChamber* chamber);

        void    execute(float p_pression);
};

#endif