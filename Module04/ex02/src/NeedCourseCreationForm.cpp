
#include <iostream>
#include "NeedCourseCreationForm.hpp"
#include "Singleton.hpp"
#include "Course.hpp"

NeedCourseCreationForm::NeedCourseCreationForm() : Form(FormType::NeedCourseCreation, "NeedCourseCreationForm"), _course(nullptr)
{
    // std::cout << "NCCForm constructor" << std::endl;
}
NeedCourseCreationForm::~NeedCourseCreationForm()
{

    // std::cout << "NCCForm destructor" << std::endl;

}

void NeedCourseCreationForm::execute()
{
    if (_course)
    {
        if(DEBUG)
            std::cout << "Exec : pushback course : " << _course->getName() << " is now available" << std::endl;
        CourseList::getInstance().getList().push_back(_course);
    }
}

bool    NeedCourseCreationForm::inspectFormInfo(Course* course)
{
    auto& listcourse = CourseList::getInstance();
    std::vector<Course*>::iterator it;
    for (it = listcourse.getList().begin(); it != listcourse.getList().end(); it++)
    {
        if ((*it)->getName() == course->getName())
        {
            if (DEBUG)
                std::cout << "Course available in courselist" << std::endl;
            return (false);
        }
    }
    std::cout << "This course subject is not available -> creation of this course : " << course->getName()  << std::endl;
    _course = course;
    return (true);
}