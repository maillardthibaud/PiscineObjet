#ifndef __NEEDCOURSECREATIONFORM_HPP__
#define __NEEDCOURSECREATIONFORM_HPP__

#include <string>
#include "Form.hpp"

class NeedCourseCreationForm : public Form
{
	private:

		// std::string 	_name;

	public:

		NeedCourseCreationForm();
		~NeedCourseCreationForm();

		void execute();
};


#endif