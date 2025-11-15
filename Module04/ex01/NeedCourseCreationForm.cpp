
#include <iostream>
#include "NeedCourseCreationForm.hpp"

NeedCourseCreationForm::NeedCourseCreationForm() : Form(FormType::NeedCourseCreation)
{
    // std::cout << "NCCForm constructor" << std::endl;
}
NeedCourseCreationForm::~NeedCourseCreationForm()
{

    // std::cout << "NCCForm destructor" << std::endl;

}

void NeedCourseCreationForm::execute()
{

    std::cout << "Need course creation form execute" << std::endl;

}