#include "Account.hpp"
#include "Bank.hpp"

Account::Account(int id) : _id(id), _balance(0.0f), _loan(0.0)
{
	std::cout << "Account Constructor" << std::endl;
    std::cout << "Account id : " << _id << " balance : " << _balance << " loan : " << _loan << std::endl; 
}

Account::~Account()
{
	std::cout << "Account Destructor" << std::endl;
}

int Account::getId() const
{
	return (_id);
}
double Account::getBalance() const
{
    return (_balance);
}

double  Account::getLoan()
{
    return (_loan);
}
