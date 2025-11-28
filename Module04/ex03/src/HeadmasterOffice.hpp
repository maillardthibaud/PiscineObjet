#ifndef __HEADMASTEROFFICE_HPP__
#define __HEADMASTEROFFICE_HPP__

#include <iostream>

#include "Room.hpp"
#include "Person.hpp"

class HeadmasterOffice : public Room
{
    private:


    public:

        HeadmasterOffice(int id);
        ~HeadmasterOffice();

        bool                        canEnter(Person* person);

        int 						getId();
        std::vector<Person*>        getOccupants();

        void                        printOccupant();
};

#endif