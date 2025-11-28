#ifndef __SUBSCRIPTIONTOCOURSEFORM_HPP__
#define __SUBSCRIPTIONTOCOURSEFORM_HPP__

#include <iostream>
#include <algorithm>

#include "Form.hpp"
#include "Student.hpp"
#include "Course.hpp"
#include "Singleton.hpp"

class SubscriptionToCourseForm : public Form
{
	private:

		Student*		_subStudent;
		Course*			_subCourse;
		std::string 	_subSubject;

	public:

		SubscriptionToCourseForm();
		~SubscriptionToCourseForm();

		Student*		getStud();
		std::string		getSubject();

		void			setSubStud(Student* stud);
		void			setSubCourse(Course* course);
		void			setSubjectSub(std::string subject);

		void 			execute();

		bool			inspectFormInfo(Student* stud, Course* course);
		bool    		inspectCourseAndStud(Student* stud, Course* course);

};


#endif