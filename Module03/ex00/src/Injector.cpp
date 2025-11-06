
#include <iostream>
#include <typeinfo>

#include "../include/Injector.hpp"
#include "../include/ExplosionChamber.hpp"


Injector::Injector() : pression(0.0f)
{
    std::cout << "Constructor " << typeid(this).name() << " pression : " << pression << std::endl;
}

void Injector::setEc(ExplosionChamber* chamber)
{
    ec = chamber;
}

Injector::~Injector()
{

}

void Injector::execute(float p_pression)
{

    std::cout << "Injector pressure was : " << pression << "bar " << std::endl;
    if (p_pression == 0.0f)
    {
        pression = p_pression;
        std::cout << "Injector pressure is now : " << pression << " bar " << std::endl;
        ec->fill(0);
    }
    else
    {   
        // if 
        pression += p_pression;
        if (pression > 0.0f)
        {
            float volume = pression;
            std::cout << "Injector pressure is now : " << pression << " bar " << std::endl;
            ec->fill(volume);
        }
    }

}
float Injector::getPression()
{
    return(pression);
}


void    Injector::setPression(float SPression)
{
    pression = SPression;
}
