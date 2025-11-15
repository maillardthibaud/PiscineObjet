#ifndef __HEADMASTEROFFICE_HPP__
#define __HEADMASTEROFFICE_HPP__

#include "Room.hpp"

class HeadmasterOffice : public Room
{
    private:



    public:

            HeadmasterOffice(int id);
            ~HeadmasterOffice();

            bool canEnter(Person* person);

			int 						getId();


        std::vector<Person*>        getOccupants();
};

#endif