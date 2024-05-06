#include <iostream>
#include "Account.hpp"
#include "Bank.hpp"

int	main() {
	Bank	bank = Bank(1000);

	bank.createAccount(100);
	bank.createAccount(150);

	std::cout << bank << std::endl;

	bank.deleteAccount(0);

	std::cout << bank << std::endl;

	bank.createAccount(1050);

	std::cout << bank << std::endl;
	return 0;
}
