

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
    std::cout << "-->Room Creation" << std::endl;
    HeadmasterOffice directorOffice(1);
    SecretarialOffice cpeOffice(2);
    Classroom room(3);
    std::cout << "|-->Add to list" << std::endl;
    auto& iRoom = RoomList::getInstance();
    iRoom.add(&directorOffice);
    iRoom.add(&cpeOffice);
    iRoom.add(&room);

    std::cout << "-->Staff Creation" << std::endl;
    Headmaster mediator("Director");
    Secretary cpe("Cpe");
    Professor prof("Phd Jacquard", "Maths");
    Professor prof2("Phd Jacquy", "Geo");
    Professor prof3("Phd Joe", "Physics");
    std::cout << "|-->Add to list" << std::endl;
    auto& iStaff = StaffList::getInstance();
    iStaff.add(&mediator);
    iStaff.add(&cpe);
    iStaff.add(&prof);
    iStaff.add(&prof2);
    iStaff.add(&prof3);

    std::cout << "-->Course Creation" << std::endl;
    Course math("Maths", 3, 1);
    Course geo("Geo", 3, 1);
    std::cout << "|-->Add to list" << std::endl;
    auto& iCourse = CourseList::getInstance();
    iCourse.add(&math);
    iCourse.add(&geo);

    std::cout << "-->Student Creation" << std::endl;
    Student boty("Boty");
    Student ludo("Ludo");
    std::cout << "|-->Add to list" << std::endl;
    auto& iStud = StudentList::getInstance();
    iStud.add(&boty);
    iStud.add(&ludo);

    std::cout << "-->Init Headmaster/Mediator info" << std::endl;
    mediator.setNbRoom(iRoom.getList().size());
    mediator.setSecretary(&cpe);
    mediator.addProf(&prof);
    mediator.addProf(&prof2);
    mediator.addProf(&prof3);
    mediator.assignCourseToProf(math, prof);
    mediator.assignCourseToProf(geo, prof2);
    boty.setHeadmaster(&mediator);
    ludo.setHeadmaster(&mediator);
    prof.setHeadmaster(&mediator);
    prof2.setHeadmaster(&mediator);
    prof3.setHeadmaster(&mediator);
    
    std::cout << "-----------SCHOOL READY------------------------" << std::endl;

    std::cout << "Lauch Class 1" << std::endl;
    mediator.launchClass();
    mediator.validateForms();
    std::cout << "Lauch Class 2" << std::endl;
    mediator.launchClass();
    boty.askForSubscriptionForm("Maths");
    boty.askForSubscriptionForm("Geo");
    ludo.askForSubscriptionForm("Maths");
    ludo.askForSubscriptionForm("Physics");
    mediator.validateForms();
    std::cout << "Lauch Class 3" << std::endl;
    mediator.launchClass();
    std::cout << "Lauch Class 4" << std::endl;
    mediator.launchClass();
    std::cout << "Lauch Class 5" << std::endl;
    mediator.launchClass();
    std::cout << "Lauch Class 6" << std::endl;
    mediator.launchClass();
    std::cout << "Lauch Class 7" << std::endl;
    mediator.launchClass();
    std::cout << "----" << std::endl;

    boty.askForGraduation(&math);
    ludo.askForGraduation(&math);
    boty.askForGraduation(&geo);

    mediator.validateForms();


    return (0);
}
