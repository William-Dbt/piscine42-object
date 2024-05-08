#include <iostream>
#include "Account.hpp"
#include "Bank.hpp"

int	main() {
	std::cout << "Create a bank with 1000 of liquidity" << std::endl;
	Bank	bank = Bank(1000);

	std::cout << bank << std::endl;

	std::cout << "Create 3 accounts of 50, 100, 150 on it" << std::endl;

	bank.createAccount(50);
	bank.createAccount(100);
	bank.createAccount(150);

	std::cout << bank << std::endl;

	std::cout << "All clients came with 50, let's fill their accounts" << std::endl;

	for (int i = 0; i <= 2; i++)
		bank.addValueToAccount(i, 50);

	std::cout << bank << std::endl;

	std::cout << "Client 1 wants to take 200" << std::endl;

	bank.removeValueToAccount(1, 200);

	std::cout << bank << std::endl;

	std::cout << "Client 2 wants to take 100" << std::endl;

	bank.removeValueToAccount(2, 100);

	std::cout << bank << std::endl;

	std::cout << "Client 0 needs 800, let's give him a loan" << std::endl;

	bank.giveLoan(0, 800);

	std::cout << bank << std::endl;

	std::cout << "Client 2 needs 800 too, let's try to give a loan" << std::endl;
	
	bank.giveLoan(2, 800);

	std::cout << bank << std::endl;

	std::cout << "--------------------" << std::endl;

	std::cout << "Let's take an account from another bank" << std::endl;

	Account	account = Account(118, 10089);

	std::cout << account << std::endl;

	std::cout << "This client wants to join our bank, let's do this" << std::endl;

	bank.createAccount(account);

	std::cout << bank << std::endl;

	std::cout << "Client 3 wants to fill his account by one in another country with 1000000" << std::endl;

	bank.addValueToAccount(3, 1000000);

	std::cout << bank << std::endl;

	std::cout << "Clients 1 and 2 are too poor for this bank now, let's kick them" << std::endl;

	bank.deleteAccount(1);
	bank.deleteAccount(2);

	std::cout << bank << std::endl;
	return 0;
}
