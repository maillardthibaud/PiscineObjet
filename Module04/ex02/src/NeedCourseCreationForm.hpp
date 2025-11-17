#ifndef __NEEDCOURSECREATIONFORM_HPP__
#define __NEEDCOURSECREATIONFORM_HPP__

#include <string>
#include "Form.hpp"

class Course;

class NeedCourseCreationForm : public Form
{
	private:

			Course*			_course;

	public:

		NeedCourseCreationForm();
		~NeedCourseCreationForm();

		void execute();

		bool checkCourseCreation(Course* course);
};


#endif