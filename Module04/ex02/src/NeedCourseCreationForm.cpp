
#include <iostream>
#include "NeedCourseCreationForm.hpp"
#include "Singleton.hpp"
#include "Course.hpp"

NeedCourseCreationForm::NeedCourseCreationForm() : Form(FormType::NeedCourseCreation, "NeedCourseCreationForm")
{
    // std::cout << "NCCForm constructor" << std::endl;
}
NeedCourseCreationForm::~NeedCourseCreationForm()
{

    // std::cout << "NCCForm destructor" << std::endl;

}

void NeedCourseCreationForm::execute()
{


}

bool    NeedCourseCreationForm::checkCourseCreation(Course* course)
{
    std::cout << "Check for add a new course" << std::endl;
    auto& listcourse = CourseList::getInstance();
    std::vector<Course>::iterator it;
    for (it = listcourse.getList().begin(); it != listcourse.getList().end(); it++)
    {
        if (it->getName() == course->getName())
        {
            std::cout << "Course available in courselist" << std::endl;
            std::cout << it->getName() << std::endl;
            std::cout << course->getName() << std::endl;
            if (it->getMaxStud() <= static_cast<int>(it->getStud().size()))
            {
                std::cout << "Max stud reach, ok for add a new course" << std::endl;
                return(true);
            }
            else
            {
                std::cout << "This course has not reach the max stud" << std::endl;
                std::cout << "Max stud : " << (*it).getMaxStud() << ", students register : " << (*it).getStud().size() << std::endl;
                return (false);
            }
                // listcourse.add(Course(course->getName(), course->getNbToGrad(), course->getMaxStud()));
        }
    }
    std::cout << "This course subject is not available"  << std::endl;
    return (false);
}