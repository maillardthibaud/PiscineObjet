#ifndef __STAFF_HPP__
#define __STAFF_HPP__

#include "Person.hpp"
#include "Form.hpp"

class Staff : public Person
{
    private:


    public:

        Staff(std::string name);
        ~Staff();


        std::string getName(); 
        void sign(Form* p_form);

};

#endif
