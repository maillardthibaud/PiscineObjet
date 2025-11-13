#include "Courtyard.hpp"

#include <iostream>


Courtyard::Courtyard(int id) : Room(id)
{
    std::cout << "Courtyard constructor, id : " << _id << std::endl;
}
Courtyard::~Courtyard()
{
    std::cout << "Courtyard destructor" << std::endl;

}