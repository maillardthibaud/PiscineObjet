
#include "NeedMoreClassRoomForm.hpp"

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
    _course->addClassroom(_newRoom);
    _newRoom->assignCourse(_course);
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
void	NeedMoreClassRoomForm::setNewRoom(Classroom* classroom)
{
    _newRoom = classroom;
}