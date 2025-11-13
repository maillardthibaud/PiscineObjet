#include <iostream>
#include "SecretarialOffice.hpp"


SecretarialOffice::SecretarialOffice(int id) : Room(id)
{
	std::cout << "Secretary office constructor, id :" << _id << std::endl;
}
SecretarialOffice::~SecretarialOffice()
{
	std::cout << "Secretary office destructor"  << std::endl;

}
