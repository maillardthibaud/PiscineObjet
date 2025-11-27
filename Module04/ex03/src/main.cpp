

#include "Room.hpp"
#include "Classroom.hpp"
#include "SecretarialOffice.hpp"
#include "HeadmasterOffice.hpp"
#include "StaffRestRoom.hpp"

#include "Courtyard.hpp"
#include "Course.hpp"
#include "Person.hpp"
#include "Staff.hpp"
#include "Student.hpp"
#include "Secretary.hpp"
#include "Headmaster.hpp"
#include "Professor.hpp"
#include "Form.hpp"
#include "Singleton.hpp"

#include "SubscriptionToCourseForm.hpp"
#include "NeedCourseCreationForm.hpp"
#include "NeedMoreClassRoomForm.hpp"
#include "CourseFinishedForm.hpp"

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
    std::cout << "-->Student Creation" << std::endl;
    Student boty("Boty");
    Student ludo("Ludo");

    std::cout << "|-->Add to list" << std::endl;
    auto& iStud = StudentList::getInstance();
    iStud.add(&boty);
    iStud.add(&ludo);

    std::cout << "-->Staff Creation" << std::endl;
    Headmaster mediator("Director");
    Secretary cpe("Cpe");
    Professor prof("Mr Jacquard", "Mathematique");
    Professor prof2("Mr Jacquy", "Geographie");
    Professor prof3("Mr Jerome", "Physics");

    std::cout << "|-->Add to list" << std::endl;
    auto& iStaff = StaffList::getInstance();
    iStaff.add(&mediator);
    iStaff.add(&cpe);
    iStaff.add(&prof);
    iStaff.add(&prof2);
    iStaff.add(&prof3);

    std::cout << "-->Course Creation" << std::endl;
    Course math("Mathematique", 3, 1);
    Course geo("Geographie", 3, 1);

    std::cout << "|-->Add to list" << std::endl;
    auto& iCourse = CourseList::getInstance();
    iCourse.add(&math);
    iCourse.add(&geo);

    std::cout << "-->Classroom Creation" << std::endl;
    Classroom room(5);
    Classroom room2(6);

    std::cout << "|-->Add to list" << std::endl;
    auto& iRoom = RoomList::getInstance();
    iRoom.add(&room);
    iRoom.add(&room2);

    mediator.setSecretary(&cpe);
    mediator.assignCourseToProf(math, prof);
    mediator.assignCourseToProf(geo, prof2);

    // cpe
    boty.setHeadmaster(&mediator);
    prof.setHeadmaster(&mediator);
    prof2.setHeadmaster(&mediator);
    prof3.setHeadmaster(&mediator);


    prof.doClass();
    prof2.doClass();    
    prof3.doClass();
    prof3.doClass();

    boty.askForSubscriptionForm("Mathematique");
    // mediator.

    // math.subscribe(&boty);
    // mediator.needGraduationForm(prof, boty);



    return (0);
}
