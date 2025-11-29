
#include "NeedCourseCreationForm.hpp"

NeedCourseCreationForm::NeedCourseCreationForm() : Form(FormType::NeedCourseCreation, "CourseCreationForm"), _professor(nullptr), _course(nullptr)
{
    // std::cout << "NCCForm constructor" << std::endl;
}
NeedCourseCreationForm::~NeedCourseCreationForm()
{
    // std::cout << "NCCForm destructor" << std::endl;
}

Professor* 	NeedCourseCreationForm::getProf()
{
    return (_professor);
}
void           NeedCourseCreationForm::setProf(Professor* prof)
{
    _professor = prof;
}


void			NeedCourseCreationForm::setSubject(std::string subject)
{
    _subject = subject;
}

void NeedCourseCreationForm::execute()
{
    _course = new Course(_professor->getSubject(), 5, 10);
    if(DEBUG)
        std::cout << "Exec : pushback course : " << _course->getName() << " is now available" << std::endl;
    CourseList::getInstance().getList().push_back(_course);
    _professor->assignCourse(_course);
    _course->setResponsable(_professor);
}

bool    NeedCourseCreationForm::inspectFormInfo(Professor* prof)
{
    auto& staffList = StaffList::getInstance().getList();
    std::vector<Staff*>::iterator it;
    for (it = staffList.begin(); it != staffList.end(); it++)
    {
        if ((*it)->getName() == prof->getName())
        {
            if (DEBUG)
                std::cout << "Prof is register is staffList" << std::endl;
            _professor = prof;
            return true;
        }
    }
    return (true);
}