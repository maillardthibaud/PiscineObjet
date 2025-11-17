#ifndef __FORM_HPP__
#define __FORM_HPP__

#include <string>

enum class FormType
{
	CourseFinished,
	NeedMoreClassRoom,
	NeedCourseCreation,
	SubscriptionToCourse
};

class Form
{
	private:

		FormType 		_formType;
		std::string 	_name;

	protected:
	
		bool			_isSigned;

	public:

		Form(FormType p_formType, std::string name);
		virtual ~Form();

		virtual void execute() = 0;
		FormType	getFormType();

		std::string 	getName();
		void			setName(std::string name);		

		void			signeForm();


};

#endif