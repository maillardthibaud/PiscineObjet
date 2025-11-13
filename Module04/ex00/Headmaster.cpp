
#include "Headmaster.hpp"
#include <iostream>
#include "Staff.hpp"


Headmaster::Headmaster(std::string name) : Staff(name)
{
    std::cout << "Headmaster constructor, name : " << _name << std::endl;
}
Headmaster::~Headmaster()
{
    std::cout << "Headmaster destructor" << std::endl;

}

void Headmaster::receiveForm(Form* p_form)
{
    (void)p_form;

}