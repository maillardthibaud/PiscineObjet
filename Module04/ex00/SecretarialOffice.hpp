#ifndef __SECRETARIALOFFICE_HPP__
#define __SECRETARIALOFFICE_HPP__

#include <vector>
#include "Room.hpp"
// #include "Form.hpp"
class Form;

class SecretarialOffice: public Room
{
    private:

        std::vector<Form*> _archivedForms;

    public:

        SecretarialOffice(int id);
        ~SecretarialOffice();

};
#endif