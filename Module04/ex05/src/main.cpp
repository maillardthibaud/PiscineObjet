

#include "main.hpp"

void DirectorValidation(Headmaster& director)
{
    std::cout << "-->Director Validated Form" << std::endl;
    director.validateForms();
}

void    displayRoomInfo()
{
    auto& classroom = RoomList::getInstance().getList();
    std::vector<Room*>::iterator it;
    for (it = classroom.begin(); it != classroom.end(); it++)
    {
        std::cout << (*it)->getId() << std::endl;
    }
}

int main()
{
    std::cout << "-----------INIT SCHOOL------------------------" << std::endl;
    Headmaster director("Tyler Durden");
    Secretary cpe("Marla Singer");
    auto& iStaff = StaffList::getInstance();
    iStaff.add(&director);
    iStaff.add(&cpe);

    School schoolTest(director, cpe);
    schoolTest.initHeadmaster();
    schoolTest.initCourseAndRoom();
    schoolTest.recruteProfessor();
    schoolTest.recruteStudent();
    
    schoolTest.runDayRoutine();
    schoolTest.getHeadmaster().validateForms();
    schoolTest.graduationCeremony();
    








    // mediator.ringTheBell();
    // mediator.ringTheBell();
    // mediator.ringTheBell();
    // mediator.ringTheBell();




    return (0);
}
