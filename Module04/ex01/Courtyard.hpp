#ifndef __COURTYARD_HPP__
#define __COURTYARD_HPP__

#include "Room.hpp"

class Courtyard : public Room
{
private:

public:

        Courtyard(int id);
        ~Courtyard();
        
        bool                        canEnter(Person* person);
        std::vector<Person*>        getOccupants();
        int                         getId();
};
#endif