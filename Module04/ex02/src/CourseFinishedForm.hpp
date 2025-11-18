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

			Course* 	_Finishedcourse;
			Student*	_StudToGrad;

	public:

		CourseFinishedForm();
		~CourseFinishedForm();

		bool   	inspectFormInfo(Course* course, Student* stud);

		void execute();
};


#endif