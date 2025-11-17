#ifndef __STAFFRESTROOM_HPP__
#define __STAFFRESTROOM_HPP__

#include "Room.hpp"

class StaffRestRoom : public Room
{
    private:

    public:

    StaffRestRoom(int id);
    ~StaffRestRoom();
    
    bool                    canEnter(Person* person);
    std::vector<Person*>    getOccupants();
    int                     getId();

};
#endif