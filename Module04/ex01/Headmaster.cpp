
#include "Headmaster.hpp"
#include <iostream>
#include "Staff.hpp"


Headmaster::Headmaster(std::string name) : Staff(name)
{
    // std::cout << "Headmaster constructor, name : " << _name << std::endl;
}
Headmaster::~Headmaster()
{
    // std::cout << "Headmaster destructor" << std::endl;
}

void Headmaster::receiveForm(Form* p_form)
{
    if (p_form)
    {
        std::cout << _name << " has received form : "  << std::endl;
        _formToValidate.push_back(p_form);
    }
}
