#ifndef __COURSEFINISHEDFORM_HPP__
#define __COURSEFINISHEDFORM_HPP__

#include <iostream>

#include "Form.hpp"
#include "Course.hpp"
#include "Student.hpp"
#include "Singleton.hpp"

class CourseFinishedForm : public Form
{
	private:

		Course* 	_finishedcourse;
		Student*	_studToGrad;

	public:

		CourseFinishedForm();
		~CourseFinishedForm();

		Course*			getFinishedCourse();
		Student*		getStudentToGrad();
		void			setCourseFinished(Course* course);
		void			setStudToGrad(Student* stud);

		void 			execute();



};


#endif