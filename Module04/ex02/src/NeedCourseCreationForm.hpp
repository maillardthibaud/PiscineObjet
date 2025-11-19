#ifndef __NEEDCOURSECREATIONFORM_HPP__
#define __NEEDCOURSECREATIONFORM_HPP__

#include <string>
#include "Form.hpp"
#include "Staff.hpp"
#include "Professor.hpp"
#include "Course.hpp"

class Course;

class NeedCourseCreationForm : public Form
{
	private:

			Professor* 		_askCourse;
			Course*			_course;

	public:

		NeedCourseCreationForm();
		~NeedCourseCreationForm();

		void execute();

		bool inspectFormInfo(Professor* prof);
};


#endif