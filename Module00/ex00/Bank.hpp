#ifndef BANK_HPP
#define BANK_HPP

#include <iostream>

#include <vector>
#include "Account.hpp"

class Account;

class Bank
{
    private:

        double _funds;
        int _nextId;
        std::vector<Account*> _account;
        void    SetBalance(Account* account, int depot);

    public:

        Bank(double liquidity);
        ~Bank();

    Account*    CreateAccount();
    void        DeleteAccount(Account* account);
    void        Deposit(Account* account, double amount);
    void        ApplyLoan(Account* account, double amount);
    void        RepayLoan(Account* account, double amount);
    Account*    FindAccount(Account* account);

    void        ShowAccount();
    void        ShowLiquidityAvailable();
        

};


#endif


