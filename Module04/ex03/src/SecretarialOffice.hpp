#ifndef __SECRETARIALOFFICE_HPP__
#define __SECRETARIALOFFICE_HPP__

#include <vector>
#include "Room.hpp"
class Form;

class SecretarialOffice: public Room
{
    private:

        std::vector<Form*> _archivedForms;

    public:

        SecretarialOffice(int id);
        ~SecretarialOffice();

        bool canEnter(Person* person);
        int     getId();

        std::vector<Person*>		getOccupants();

};
#endif