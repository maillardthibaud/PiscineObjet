#ifndef __COURSEFINISHEDFORM_HPP__
#define __COURSEFINISHEDFORM_HPP__

#include <iostream>
#include "Form.hpp"
#include "Course.hpp"
#include "Student.hpp"

class CourseFinishedForm : public Form
{
	private:

			Course* 	_Finishedcourse;
			Student*	_StudToGrad;

	public:

		CourseFinishedForm();
		~CourseFinishedForm();

		void	checkCourseForStudent(Course* course, Student* stud);

		void execute();
};


#endif