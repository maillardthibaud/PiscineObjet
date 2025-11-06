
#include <typeinfo>
#include <iostream>

#include "../include/Pedal.hpp"

Pedal::Pedal()
{
    std::cout << "Constructor " << typeid(this).name() << std::endl;
}

Pedal::~Pedal()
{
}

void Pedal::setTarget(LinkablePart* p_part)
{
    std::cout << "Set Pedal target : " << typeid(lp).name() << std::endl;
    lp = p_part;
    

}
void Pedal::use(float p_pression)
{
    std::cout << "Peddal use : " << typeid(lp).name() << " at pression : " << p_pression << std::endl;
    lp->execute(p_pression);

}