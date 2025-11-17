#include <iostream>
#include "SecretarialOffice.hpp"


SecretarialOffice::SecretarialOffice(int id) : Room(id)
{
	// std::cout << "Secretary office constructor, id :" << _id << std::endl;
}
SecretarialOffice::~SecretarialOffice()
{
	// std::cout << "Secretary office destructor"  << std::endl;

}

bool SecretarialOffice::canEnter(Person* person)
{
	(void)person;
	return (true);
}

int 						SecretarialOffice::getId()
{
    return (_id);
}

std::vector<Person*>		SecretarialOffice::getOccupants()
{
	return (_occupants);
}