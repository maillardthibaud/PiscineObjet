

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
    Classroom mathRoom(3);
    Classroom geoRoom(4);
    Classroom phyRoom(5);
    std::cout << "|-->Add to list" << std::endl;
    auto& iRoom = RoomList::getInstance();
    iRoom.add(&directorOffice);
    iRoom.add(&cpeOffice);
    iRoom.add(&mathRoom);
    iRoom.add(&geoRoom);
    iRoom.add(&phyRoom);

    std::cout << "-->Staff Creation" << std::endl;
    Headmaster mediator("Director");
    Secretary cpe("Cpe");
    Professor prof("Phd Jacquard", "Maths", &mediator);
    Professor prof2("Phd Jacquy", "Geo", &mediator);
    Professor prof3("Phd Joe", "Physics", &mediator);
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
    Course physic("Physics", 3, 1);
    std::cout << "|-->Add to list" << std::endl;
    auto& iCourse = CourseList::getInstance();
    iCourse.add(&math);
    iCourse.add(&geo);

    std::cout << "-->Student Creation" << std::endl;
    Student boty("Boty", &mediator);
    Student david("David", &mediator);
    Student ludo("Ludo", &mediator);
    std::cout << "|-->Add to list" << std::endl;
    auto& iStud = StudentList::getInstance();
    iStud.add(&boty);
    iStud.add(&ludo);





    std::cout << "-->Init Headmaster/Mediator info" << std::endl;
    mediator.setNbRoom(iRoom.getList().size());
    mediator.setSecretary(&cpe);
    math.addClassroom(&mathRoom);
    geo.addClassroom(&geoRoom);
    physic.addClassroom(&phyRoom);
    mathRoom.assignCourse(&math);
    geoRoom.assignCourse(&geo);
    phyRoom.assignCourse(&physic);
    mediator.addProf(&prof);
    mediator.addProf(&prof2);
    mediator.addProf(&prof3);
    mediator.assignCourseToProf(math, prof);
    mediator.assignCourseToProf(geo, prof2);
    mediator.assignCourseToProf(physic, prof3);
    math.subscribe(&boty);
    geo.subscribe(&ludo);
    physic.subscribe(&david);

    
    std::cout << "-----------SCHOOL READY------------------------" << std::endl;

    mediator.addObserver(&prof);
    mediator.addObserver(&prof2);
    mediator.addObserver(&prof3);
    mediator.addObserver(&boty);
    mediator.addObserver(&ludo);
    mediator.addObserver(&david);

    mediator.launchClass();

    mediator.ringTheBell();
    // mediator.breakTime(5);

    mediator.ringTheBell();
    mediator.ringTheBell();
    mediator.ringTheBell();



    return (0);
}
