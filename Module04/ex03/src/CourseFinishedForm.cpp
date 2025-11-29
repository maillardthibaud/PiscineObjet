
#include "CourseFinishedForm.hpp"

CourseFinishedForm::CourseFinishedForm() : Form(FormType::CourseFinished, "CourseFinishedForm"), _finishedcourse(nullptr), _studToGrad(nullptr)
{
    // std::cout << "Course finnished constructor" << std::endl;
}
CourseFinishedForm::~CourseFinishedForm()
{
    // std::cout << "Course finnished destructor" << std::endl;
}

void CourseFinishedForm::execute()
{
    std::cout << "|->exec : " << _studToGrad->getName() << " have been graduate in " << _finishedcourse->getName() << " course" << std::endl;
}

bool	CourseFinishedForm::inspectFormInfo(Course* course, Student* stud)
{
    std::vector<Course*>::iterator it;
    for (it = stud->getCourses().begin(); it != stud->getCourses().end(); it++)
    {
        if ((*it) == course)
        {
            if (DEBUG)
                std::cout << "Stud register to this course" << std::endl;
            std::vector<CourseProgress*>::iterator itp;
            for (itp = stud->getProgress().begin(); itp != stud->getProgress().end(); it++)
            {
                if ((*it) == (*itp)->course)
                {
                    if(DEBUG)
                        std::cout << "Check progress course remain : " << (*itp)->courseRemain << std::endl;
                    if ((*itp)->courseRemain == 1)
                    {
                        _studToGrad = stud;
                        _finishedcourse = course;
                        return true;
                    }
                    else
                        return false;
                }
            }
        }
    }
    std::cout << "You re not register to this course" << std::endl;
    return(false);
}
void	CourseFinishedForm::setCourseFinished(Course* course)
{
    _finishedcourse = course;
}
void	CourseFinishedForm::setStudToGrad(Student* stud)
{
    _studToGrad = stud;
}
Course*	CourseFinishedForm::getFinishedCourse()
{
    return(_finishedcourse);
}
Student*	CourseFinishedForm::getStudentToGrad()
{
    return(_studToGrad);
}