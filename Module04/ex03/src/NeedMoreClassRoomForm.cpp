#include <iostream>
#include "NeedMoreClassRoomForm.hpp"
#include "Singleton.hpp"
#include "Professor.hpp"


NeedMoreClassRoomForm::NeedMoreClassRoomForm() : Form(FormType::NeedMoreClassRoom, "NeedMoreClassRoomFrom"), _newRoom(nullptr)
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
        
bool    NeedMoreClassRoomForm::inspectFormInfo(Professor* prof)
{

    auto& staffList = StaffList::getInstance().getList();
    std::vector<Staff*>::iterator it;
    for (it = staffList.begin(); it != staffList.end(); it++)
    {
        if ((*it)->getName() == prof->getName())
        {
            if (DEBUG)
                std::cout << "Prof is in Stafflist" << std::endl;
            if (prof->getCurrentCourse()->getClassroom())
            {
                std::cout << "you re already have a classroom assign for this course, id : " << prof->getCurrentCourse()->getClassroom()->getId() << std::endl;
                return (false);
            }
            else
            {
                if (DEBUG)
                    std::cout << "new room created for : " << prof->getCurrentCourse()->getName() << std::endl;
                _newRoom = new Classroom(12);
                prof->getCurrentCourse()->addClassroom(_newRoom);
                return (true);
            //     _course = course;
            }

        }
    }
    return (false);
}
void	NeedMoreClassRoomForm::setRequester(Professor* prof)
{
    _requester = prof;
}



void	NeedMoreClassRoomForm::setCourse(Course* course)
{
    _course = course;
}
Course*		NeedMoreClassRoomForm::getCourse()
{
    return (_course);
}
Professor*  NeedMoreClassRoomForm::getRequester()
{
    return (_requester);
}
    // auto& listcourse = CourseList::getInstance().getList();

    // std::vector<Course*>::iterator it;
    // for (it = listcourse.begin(); it != listcourse.end(); it++)
    // {
    //     if ((*it)->getName() == course->getName())
    //     {
    //         if (DEBUG)
    //             std::cout << "Course available in courselist" << std::endl;
    //         if (!(*it)->getResponsable())
    //         {
    //             if (DEBUG)
    //                 std::cout << "This course has no professor -> assign Prof" << std::endl;
    //             (*it)->assign(prof);
    //             return (true);
    //         }
    //         else
    //         {
    //             std::cout << "This coourse already have a professor" << std::endl;
    //             return(false);
    //         }
    //     }
    // }
    // std::cout << "This course doesnt figure in CourseList" << std::endl;
    // return (false);
// }
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
