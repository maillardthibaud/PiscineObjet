
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