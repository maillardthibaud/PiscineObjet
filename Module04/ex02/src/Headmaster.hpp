#ifndef __HEADMASTER_HPP__
#define __HEADMASTER_HPP__

#include <vector>
#include "Staff.hpp"
#include "Form.hpp"

class Headmaster : public Staff
{
	private:

		std::vector<Form*>		_formToValidate;
		
	public:
		
		Headmaster(std::string name);
		~Headmaster();

		void 	receiveForm(Form* p_form);

		void	validateForms();
};

#endif