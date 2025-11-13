#ifndef __SECRETARY_HPP__
#define __SECRETARY_HPP__

#include "Staff.hpp"
#include "Form.hpp"

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