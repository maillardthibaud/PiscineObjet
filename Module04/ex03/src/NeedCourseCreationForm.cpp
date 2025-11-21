
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
    _course = new Course(_askCourse->getSubject(), 5, 10);
    if(DEBUG)
        std::cout << "Exec : pushback course : " << _course->getName() << " is now available" << std::endl;
    CourseList::getInstance().getList().push_back(_course);
    _askCourse->assignCourse(_course);
}

bool    NeedCourseCreationForm::inspectFormInfo(Professor* prof)
{
    // auto& listcourse = CourseList::getInstance();
    // std::vector<Course*>::iterator it;
    // for (it = listcourse.getList().begin(); it != listcourse.getList().end(); it++)
    // {
    //     if ((*it)->getName() == course->getName())
    //     {
    //         if (DEBUG)
    //             std::cout << "Course available in courselist" << std::endl;
    //         return (false);
    //     }
    // }
    // std::cout << "This course subject is not available -> creation of this course : " << course->getName()  << std::endl;
    auto& staffList = StaffList::getInstance().getList();
    std::vector<Staff*>::iterator it;
    for (it = staffList.begin(); it != staffList.end(); it++)
    {
        if ((*it)->getName() == prof->getName())
        {
            if (DEBUG)
                std::cout << "Prof is register is staffList" << std::endl;
            _askCourse = prof;
            return true;
        }
    }
    return (true);
}