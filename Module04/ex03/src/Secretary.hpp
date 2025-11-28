#ifndef __SECRETARY_HPP__
#define __SECRETARY_HPP__

#include <iostream>

#include "Staff.hpp"
#include "Form.hpp"
#include "CourseFinishedForm.hpp"
#include "NeedCourseCreationForm.hpp"
#include "NeedMoreClassRoomForm.hpp"
#include "SubscriptionToCourseForm.hpp"

class Secretary : public Staff
{
	private:

	public:

		Secretary(std::string name);
		~Secretary();
		
		Form* createForm(FormType p_formType);
		void archiveForm();
};

#endif