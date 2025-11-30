
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