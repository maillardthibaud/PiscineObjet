#include <iostream>
#include <vector>
// #include "Account.hpp"
#include "Bank.hpp"

int main()
{
	Bank MainBank = Bank(1000);
	Account *acc = MainBank.CreateAccount();
	Account *acc2 = MainBank.CreateAccount();
	Account *acc3 = MainBank.CreateAccount();


	std::cout << "-------Get id-------" << std::endl;

	std::cout << acc->getId() << std::endl;
	std::cout << acc2->getId() << std::endl;
	std::cout << acc3->getId() << std::endl;

	std::cout << "-----Deposit 100 on 1, 1200 on 2, 130 on 3-------" << std::endl;

    MainBank.Deposit(acc, 100);
    MainBank.Deposit(acc2, 1200);
    MainBank.Deposit(acc3, 130);
	
	std::cout << "-----ShowLiquidity-------" << std::endl;
    MainBank.ShowLiquidityAvailable();

	std::cout << "-----ShowAccount-------" << std::endl;
	MainBank.ShowAccount();

	std::cout << "-----ApplyLoan Account 1 for 100-------" << std::endl;
	MainBank.ApplyLoan(acc, 100);

	std::cout << "-----ApplyLoan Account 2 for 200-------" << std::endl;
	MainBank.ApplyLoan(acc2, 200);

	std::cout << "-----RepayLoan Account 1 for 50-------" << std::endl;
	MainBank.RepayLoan(acc, 50);

	std::cout << "-----ShowLiquidity-------" << std::endl;
    MainBank.ShowLiquidityAvailable();

	std::cout << "-----RepayLoan Account 2 for 150-------" << std::endl;
	MainBank.RepayLoan(acc2, 150);

	std::cout << "-----ShowLiquidity-------" << std::endl;
    MainBank.ShowLiquidityAvailable();

	std::cout << "-----RepayLoan Account 2 for 150-------" << std::endl;
	MainBank.RepayLoan(acc2, 150);

	MainBank.DeleteAccount(acc);
	MainBank.DeleteAccount(acc2);


	std::cout << "-----ShowLiquidity-------" << std::endl;
    MainBank.ShowLiquidityAvailable();

	return (0);
}