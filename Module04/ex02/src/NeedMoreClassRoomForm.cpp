#include <iostream>
#include "NeedMoreClassRoomForm.hpp"
#include "Singleton.hpp"


NeedMoreClassRoomForm::NeedMoreClassRoomForm() : Form(FormType::NeedMoreClassRoom, "NeedMoreClassRoomFrom"), _course(nullptr), _newRoom(nullptr)
{
    // std::cout << "NMCRForm constructor" << std::endl;
}
NeedMoreClassRoomForm::~NeedMoreClassRoomForm()
{

    // std::cout << "NMCRForm destructor" << std::endl;
}
void NeedMoreClassRoomForm::execute()
{
    if (!_newRoom) 
        return;
    if (DEBUG)
        std::cout << "Exec : push back classromm, assign course" << std::endl;
    // _course->addClassroom(_newRoom);
    // _newRoom->assignCourse(_course);
    RoomList::getInstance().getList().push_back(_newRoom);
}
        
bool    NeedMoreClassRoomForm::inspectFormInfo(Course* course, Professor* prof)
{
    auto& listcourse = CourseList::getInstance().getList();
    std::vector<Course*>::iterator it;
    for (it = listcourse.begin(); it != listcourse.end(); it++)
    {
        if ((*it)->getName() == course->getName())
        {
            if (DEBUG)
                std::cout << "Course available in courselist" << std::endl;
            if (course->getClassroom())
            if (!(*it)->getResponsable())
            {
                std::cout << "This course has no professor -> assign Prof" << std::endl;
                (*it)->assign(prof);
            }
        }
            // if ((*it)->getMaxStud() <= static_cast<int>((*it)->getStud().size()))
            // {
            //     if (DEBUG)
            //         std::cout << "Max stud reach : " << (*it)->getStud().size() << " -> add new classroom for this course" << std::endl;
            //     _newRoom = new Classroom(5 + listcourse.size());
            //     (*it)->addClassroom(_newRoom);
            //     _course = course;
            //     return(true);
            // }
            // else
            // {
            //     std::cout << "! This course has not reach the max stud" << std::endl;
            //     std::cout << "|->Max stud : " << (*it)->getMaxStud() << ", students register : " << (*it)->getStud().size() << std::endl;
            //     return (false);
            // }
    }
    std::cout << "! This course subject is not available"  << std::endl;
    return (false);
}
