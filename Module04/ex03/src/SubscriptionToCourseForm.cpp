#include "SubscriptionToCourseForm.hpp"

SubscriptionToCourseForm::SubscriptionToCourseForm() : Form(FormType::SubscriptionToCourse, "SubscriptionCourseForm"), _subStudent(nullptr), _subCourse(nullptr)
{
    // std::cout << "STCForm constructor" << std::endl; 
}
SubscriptionToCourseForm::~SubscriptionToCourseForm()
{
    // std::cout << "STCForm destructor" << std::endl; 
}

void SubscriptionToCourseForm::execute()
{
    std::cout << "execute -> Student subscribe to course " << std::endl; 
    _subCourse->subscribe(_subStudent);
}
Student*		SubscriptionToCourseForm::getStud()
{
    return (_subStudent);
}
std::string		SubscriptionToCourseForm::getSubject()
{
    return (_subSubject);
}

bool	SubscriptionToCourseForm::inspectFormInfo(Student* stud, Course* course)
{
    if (!inspectCourseAndStud(stud, course))
        return false;
    if (DEBUG)
        std::cout << "Student : " << stud->getName() << " ask to subscribe " << course->getName() << " course." << std::endl;
    _subStudent = stud;
    // _subCourse = course;
    _isSigned = false;
    return true;
}


void	SubscriptionToCourseForm::setSubStud(Student* stud)
{
    _subStudent = stud;
}
void	SubscriptionToCourseForm::setSubjectSub(std::string subject)
{
    _subSubject = subject;
}

void	SubscriptionToCourseForm::setSubCourse(Course* course)
{
    _subCourse = course;
}


bool    SubscriptionToCourseForm::inspectCourseAndStud(Student* stud, Course* course)
{
    auto& studList = StudentList::getInstance().getList();
    auto it = std::find(studList.begin(), studList.end(), stud);
    if (it != studList.end())
    {
        if (DEBUG)
            std::cout << "Student find" << std::endl;
        auto& courList = CourseList::getInstance().getList();
        auto it = std::find(courList.begin(), courList.end(), course);
        if (it != courList.end() && (*it)->countStudent())
        {
            if (DEBUG)
                std::cout << "course find" << std::endl;
            return (true);
        }
        std::cout << "! Course not register or max stud reach" << std::endl;
        return (false);
    }
    std::cout << "! Stud not register" << std::endl;
    return (false);
}


