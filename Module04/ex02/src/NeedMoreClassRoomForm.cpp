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
    if (!_newRoom && DEBUG) {
        std::cout << "Error on newRoom" << std::endl;
        return;}
    std::cout << "Exec : push back classromm, assign course" << std::endl;
    RoomList::getInstance().getList().push_back(_newRoom);
    _newRoom->assignCourse(_course);
}
        
bool    NeedMoreClassRoomForm::inspectFormInfo(Course* course)
{
    auto& listcourse = CourseList::getInstance();
    std::vector<Course*>::iterator it;
    for (it = listcourse.getList().begin(); it != listcourse.getList().end(); it++)
    {
        if ((*it)->getName() == course->getName())
        {
            if (DEBUG)
                std::cout << "Course available in courselist" << std::endl;
            if ((*it)->getMaxStud() <= static_cast<int>((*it)->getStud().size()))
            {
                if (DEBUG)
                    std::cout << "Max stud reach. -> add new classroom for this course" << std::endl;
                _newRoom = new Classroom(4 + listcourse.getList().size());
                return(true);
            }
            else
            {
                std::cout << "! This course has not reach the max stud" << std::endl;
                std::cout << "|->Max stud : " << (*it)->getMaxStud() << ", students register : " << (*it)->getStud().size() << std::endl;
                return (false);
            }
        }
    }
    std::cout << "! This course subject is not available"  << std::endl;
    return (false);
}
