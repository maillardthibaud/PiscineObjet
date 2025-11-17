#include "Secretary.hpp"
#include <iostream>
#include "Form.hpp"
#include "CourseFinishedForm.hpp"
#include "NeedCourseCreationForm.hpp"
#include "NeedMoreClassRoomForm.hpp"
#include "SubscriptionToCourseForm.hpp"

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
    switch (p_formType)
    {
        case (FormType::CourseFinished): return new CourseFinishedForm();
        case (FormType::NeedCourseCreation): return new NeedCourseCreationForm();
        case (FormType::NeedMoreClassRoom): return new NeedMoreClassRoomForm();
        case (FormType::SubscriptionToCourse): return new SubscriptionToCourseForm();
        default: break;
    }
    return(nullptr);

}
void Secretary::archiveForm()
{

}
