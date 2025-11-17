#include <iostream>
#include "SubscriptionToCourseForm.hpp"


SubscriptionToCourseForm::SubscriptionToCourseForm() : Form(FormType::SubscriptionToCourse, "SubscriptionCourseForm")
{

    std::cout << "STCForm constructor" << std::endl; 
}
SubscriptionToCourseForm::~SubscriptionToCourseForm()
{
    std::cout << "STCForm destructor" << std::endl; 

}

void SubscriptionToCourseForm::execute()
{
    if (_isSigned)
    {
        std::cout << "STCForm execute-> Student subscribe to course" << std::endl; 
        _subCourse->subscribe(_subStudent);
    }
    else
        std::cout << "STCForm is not signed" << std::endl;
}

void	SubscriptionToCourseForm::fillStudentAndCourse(Student* stud, Course* course)
{
    _subStudent = stud;
    _subCourse = course;
}
