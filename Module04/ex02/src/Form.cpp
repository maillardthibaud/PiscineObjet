#include "Form.hpp"

#include <iostream>

Form::Form(FormType p_formType, std::string name) : _formType(p_formType), _name(name), _isSigned(false)
{
    // std::cout << "Form constructor" << std::endl;
}
Form::~Form()
{
    // std::cout << "Form destructor" << std::endl;
}

FormType	Form::getFormType()
{
    return(_formType);
}

void	Form::signeForm()
{
    _isSigned = true;
}
std::string 	Form::getName()
{
    return(_name);
}
void			Form::setName(std::string name)
{
    _name = name;
}