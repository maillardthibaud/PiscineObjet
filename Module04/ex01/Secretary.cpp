#include "Secretary.hpp"
#include <iostream>
#include "Form.hpp"

Secretary::Secretary(std::string name) : Staff(name)
{
    // std::cout << "Secretary constructor, name : " << _name << std::endl;
}
Secretary::~Secretary()
{
    // std::cout << "Secretary destructor" << std::endl;
}

		
Form* Secretary::createForm(FormType p_formType)
{
    (void)p_formType;
    return(nullptr);

}
void Secretary::archiveForm()
{

}
