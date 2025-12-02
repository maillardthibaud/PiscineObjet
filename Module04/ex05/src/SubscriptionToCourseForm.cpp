#include "SubscriptionToCourseForm.hpp"

SubscriptionToCourseForm::SubscriptionToCourseForm() : Form(FormType::SubscriptionToCourse, "SubscriptionCourseForm"), _subStudent(nullptr), _subCourse(nullptr)
{
    // std::cout << "STCForm constructor" << std::endl; 
}
SubscriptionToCourseForm::~SubscriptionToCourseForm()
{
    // std::cout << "STCForm destructor" << std::endl; 
}

void SubscriptionToCourseForm::execute()
{
    _subCourse->subscribe(_subStudent);
}
Student*		SubscriptionToCourseForm::getStud()
{
    return (_subStudent);
}
std::string		SubscriptionToCourseForm::getSubject()
{
    return (_subSubject);
}

void	SubscriptionToCourseForm::setSubStud(Student* stud)
{
    _subStudent = stud;
}
void	SubscriptionToCourseForm::setSubjectSub(std::string subject)
{
    _subSubject = subject;
}

void	SubscriptionToCourseForm::setSubCourse(Course* course)
{
    _subCourse = course;
}


