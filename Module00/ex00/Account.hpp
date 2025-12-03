#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <iostream>
// #include "Bank.hpp"


class Account
{
    private:

        const int   _id;
        double      _balance;
        double      _loan;

    public:

        Account(int id);
        ~Account();

        int     getId() const;
        double  getBalance() const;
        double  getLoan() const;

        friend class Bank;
    
};



#endif