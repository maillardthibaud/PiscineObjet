#include "Form.hpp"

#include <iostream>

Form::Form(FormType p_formType) : _formType(p_formType)
{
    std::cout << "Form constructor " << std::endl;
}
Form::~Form()
{

}