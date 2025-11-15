#include "CourseFinishedForm.hpp"
#include <iostream>


CourseFinishedForm::CourseFinishedForm() : Form(FormType::CourseFinished)
{
    // std::cout << "Course finnished constructor" << std::endl;
}
CourseFinishedForm::~CourseFinishedForm()
{
    // std::cout << "Course finnished destructor" << std::endl;
}

void CourseFinishedForm::execute()
{
    std::cout << "Execute Course Finished Form" << std::endl;

}