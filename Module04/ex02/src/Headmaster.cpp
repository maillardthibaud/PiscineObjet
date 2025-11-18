
#include "Headmaster.hpp"
#include <iostream>
#include "Staff.hpp"
#include "Form.hpp"
#include "Singleton.hpp"

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
    if (p_form && !p_form->getIsSigned())
    {
        if(DEBUG)
            std::cout << _name << " has received form : " << p_form->getName()  << std::endl;
        _formToValidate.push_back(p_form);
    }
}

void    Headmaster::validateForms()
{
    std::vector<Form*>::iterator it;
    for (it = _formToValidate.begin(); it != _formToValidate.end(); it++)
    {
        if (!(*it)->getIsSigned())
        {
            (*it)->signeForm();
            if (DEBUG)
                std::cout << _name << " has signed form : " << (*it)->getName() << std::endl;
            (*it)->execute();
        }
    }
}


