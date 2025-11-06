#include "Bank.hpp"
#include "Account.hpp"

Bank::Bank(double liquidity) : _funds(liquidity)
{
    std::cout << "Bank constructor, funds : " << _funds << std::endl;
    _nextId = 1;
}

Bank::~Bank()
{
    std::cout << "Bank destructor" << std::endl;
    std::vector<Account*>::iterator it;
    for (it = _account.begin(); it != _account.end(); it++)
    {
        delete *it;
    }
    _account.clear();
}


void    Bank::ShowLiquidityAvailable()
{
    std::cout << "Bank liquidity available : " << _funds << std::endl;
}


Account* Bank::CreateAccount()
{
    Account* newAccount = new Account(_nextId);
    _account.push_back(newAccount);
    _nextId++;
    return (newAccount);
}

void   Bank::DeleteAccount(Account* account)
{
    std::cout << "Search for account, idx : " << account->getId() << std::endl;
    std::vector<Account*>::iterator it;
    for (it = _account.begin(); it != _account.end(); it++)
    {
        if ((*it)->getId() == account->getId())
        {
            if (account->_loan > 0)
            {
                std::cout << " You cannot delete your account, you must repay yopur loan first ! -> loan : " << account->_loan << std::endl;
                return ; 
            }
            std::cout << "Erase account !" << std::endl;
            delete *it;
            _account.erase(it);
            return;
        }
    }
    std::cout << "Dont find account idx = " << account->getId() << std::endl;

}
void    Bank::ShowAccount()
{
    std::vector<Account*>::iterator it;
    for (it = _account.begin(); it != _account.end(); it++)
    {
        std::cout << (*it) << " id : " << (*it)->getId() << " balance : " << (*it)->getBalance() << std::endl;
        if ((*it)->getLoan() > 0)
        {
            std::cout << " and have a loan, amount : " << (*it)->_loan << std::endl;
        }
    }

}

void    Bank::Deposit(Account* account, double amount)
{
    if (FindAccount(account))
    {
        std::cout << "Account find" << std::endl;
        _funds += (amount * 0.05);
        account->_balance += (amount * 0.95);
        std::cout << "Bank fund : " << _funds << ", Account id : " << account->_id << " balance : " << account->_balance << std::endl;
        return ;
    }
}

void    Bank::ApplyLoan(Account* account, double amount)
{
    if (amount > _funds - 100)
    {
        std::cout << "The bank dont have anought liquidity for your loan." << std::endl;
        return;
    }
    if (FindAccount(account))
    {
        std::cout << "Account find" << std::endl;
        _funds -= amount;
        account->_balance += amount;
        account->_loan = amount + (amount * 0.1);
        std::cout << "Bank fund : " << _funds << ", Account id : " << account->_id << " balance : " << account->_balance << " loan : " << account->_loan << std::endl;
    }
}

Account*    Bank::FindAccount(Account* account)
{
    std::vector<Account*>::iterator it;
    for (it = _account.begin(); it != _account.end(); it++)
    {
        if ((*it)->getId() == account->getId())
            return (account);
    }
    return (NULL);
}

void    Bank::RepayLoan(Account* account, double amount)
{
    if (FindAccount(account))
    {
        if (amount < account->getBalance())
        {
            std::cout << "Before RepayLoan Account id : " << account->getId() << " balance : " << account->_balance << ", loan : " << account->_loan << std::endl;
            if (account->_loan < amount)
            {
                double over = amount - account->_loan;
                account->_loan = 0;
                account->_balance += over;
                _funds += over;
                std::cout << "Congrat Account id : " << account->getId() << " you've entirely repay your loan" << std::endl;
            }
            else
            {
                account->_loan -= amount;
                _funds += amount;
            }
            account->_balance -= amount;
            
            std::cout << "After RepayLoan Account id : " << account->getId() << " balance : " << account->_balance << ", loan : " << account->_loan << std::endl;
            
            
        }
    }
}
