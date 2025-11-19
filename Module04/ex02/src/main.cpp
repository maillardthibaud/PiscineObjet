

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

void SubCreationForm(Secretary& cpe, Headmaster& director, Student& stud, Course& course)
{
    std::cout << "-->SubToCourseForm Creation" << std::endl;
    Form* formsub = cpe.createForm(FormType::SubscriptionToCourse);
    SubscriptionToCourseForm* sub = dynamic_cast<SubscriptionToCourseForm*>(formsub);
    std::cout << "|-->Fill SubToCourseForm" << std::endl;
    if (sub->inspectFormInfo(&stud, &course))
        director.receiveForm(sub);
}
void    NeedCourseForm(Secretary& cpe, Headmaster& director, Professor& prof)
{
    std::cout << "-->NeedCourseCreationForm" << std::endl;
    Form* formCourseCrea = cpe.createForm(FormType::NeedCourseCreation);
    NeedCourseCreationForm* courseCrea = dynamic_cast<NeedCourseCreationForm*>(formCourseCrea);
    if (courseCrea->inspectFormInfo(&prof))
        director.receiveForm(courseCrea);
}
void NeedMoreClassForm(Secretary& cpe, Headmaster& director, Professor& prof)
{
    std::cout << "-->NeedMoreClassRoomForm" << std::endl;
    Form* formClassroomCrea = cpe.createForm(FormType::NeedMoreClassRoom);
    NeedMoreClassRoomForm* classroomCrea = dynamic_cast<NeedMoreClassRoomForm*>(formClassroomCrea);
    if (classroomCrea->inspectFormInfo(&prof))
        director.receiveForm(classroomCrea);
}


void    CourseFinishForm(Secretary& cpe, Headmaster& director, Course& course, Student& stud)
{
    std::cout << "-->CourseFinishedForm" << std::endl;
    Form* formCourseFinish = cpe.createForm(FormType::CourseFinished);
    CourseFinishedForm* courseFinish = dynamic_cast<CourseFinishedForm*>(formCourseFinish);
    if (courseFinish->inspectFormInfo(&course, &stud))
        director.receiveForm(courseFinish);
    
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
    Secretary cpe("Josephine");
    Headmaster dirlo("Director");
    Professor prof("Mr Jacquard", "Physique");

    std::cout << "|-->Add to list" << std::endl;
    auto& iStaff = StaffList::getInstance();
    iStaff.add(&cpe);
    iStaff.add(&dirlo);
    iStaff.add(&prof);

    // std::cout << "-->Course Creation" << std::endl;
    // Course math("Mathematique", 3, 1);
    // Course geo("Geographie", 3, 1);

    // std::cout << "|-->Add to list" << std::endl;
    // auto& iCourse = CourseList::getInstance();
    // iCourse.add(&math);
    // iCourse.add(&geo);

    std::cout << "-->Classroom Creation" << std::endl;
    Classroom room(5);
    Classroom room2(6);

    std::cout << "|-->Add to list" << std::endl;
    auto& iRoom = RoomList::getInstance();
    iRoom.add(&room);
    iRoom.add(&room2);

    // recute prof before !!!
    // if (prof.hasnocourse)
        NeedCourseForm(cpe, dirlo, prof);
    DirectorValidation(dirlo);

    // std::cout << "-->Display info course" << std::endl;
    // math.displayInfoCourse();
    // geo.displayInfoCourse();

    // std::cout << "-->Display info course" << std::endl;
    // math.displayInfoCourse();
    // geo.displayInfoCourse();


    SubCreationForm(cpe, dirlo, ludo, *prof.getCurrentCourse());
    DirectorValidation(dirlo);

    // SubCreationForm(cpe, dirlo, boty, math);
    // DirectorValidation(dirlo);



    // teaching 
    // if prof has no room
        NeedMoreClassForm(cpe, dirlo, prof);
    DirectorValidation(dirlo);

    std::cout << "-->Display info course" << std::endl;
    prof.getCurrentCourse()->displayInfoCourse();
    // prof.getCurrentCourse().displayInfoCourse();
    // geo.displayInfoCourse();

    
    CourseFinishForm(cpe, dirlo, *prof.getCurrentCourse(), ludo);
    DirectorValidation(dirlo);
    // SubCreationForm(cpe, dirlo, boty, geo);

    
    // displayRoomInfo();
    // std::cout << "|-->Classroom assign Course" << std::endl;
    // room.assignCourse(&math);
    // room2.assignCourse(&geo);

    // displayRoomInfo()


    return (0);
}
