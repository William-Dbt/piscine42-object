#include "Bank.hpp"

Bank::Bank(): _liquidity(0), _lastAccountId(0) {}

Bank::Bank(const int initialLiquidity): _liquidity(initialLiquidity), _lastAccountId(0) {}

Bank::~Bank() {
	std::vector<Account *>::iterator	it = this->_clientAccounts.begin();

	for (; it != this->_clientAccounts.end(); it++)
		if (*it)
			delete *it;
}

// lastId refers to the id of the last created account
// We'll use this for each creation of accounts unstead of keeping this in the class
// Because this function is the only way to add an account in the bank
void	Bank::createAccount(const int accountValue) {
	Account*	newAccount;

	newAccount = new Account(this->_lastAccountId++, accountValue);
	this->_clientAccounts.push_back(newAccount);
}

void	Bank::createAccount(const Account& account) {
	Account*	newAccount;

	newAccount = new Account(account);
	newAccount->setId(this->_lastAccountId++);
	this->_clientAccounts.push_back(newAccount);
}

void	Bank::addValueToAccount(const int accountId, const int value) {
	int bankShare;

	Account *accountToModify = this->getClientAccountById(accountId);

	if (!accountToModify) {
		std::cout << "⚠️  ERROR: Can't find account [" << accountId << "] !" << std::endl;
		return ;
	}
	bankShare = value * 0.05;
	this->_liquidity += bankShare;

	accountToModify->setValue(accountToModify->getValue() + value - bankShare);
}

void	Bank::removeValueToAccount(const int accountId, const int value) {
	Account *accountToModify = this->getClientAccountById(accountId);

	if (!accountToModify) {
		std::cout << "⚠️  ERROR: Can't find account [" << accountId << "] !" << std::endl;
		return ;
	}
	if (accountToModify->getValue() - value < 0) {
		std::cout << "⚠️  ERROR: client " << accountId << " doesn't have enough value to ";
		std::cout << "remove " << value << " from his account ! ⚠️" << std::endl;
		return ;
	}
	accountToModify->setValue(accountToModify->getValue() - value);
}

void	Bank::deleteAccount(const int accountId) {
	std::vector<Account *>::iterator	it = this->_clientAccounts.begin();

	for (; it != this->_clientAccounts.end(); it++) {
		if (!(*it))
			continue ;

		if ((*it)->getId() == accountId) {
			this->_clientAccounts.erase(it);
			break ;
		}
	}
}

void	Bank::giveLoan(const int accountId, const int value) {
	if (value <= 0) {
		std::cout << "⚠️  ERROR: value of loan is invalid ! ⚠️" << std::endl;
		return ;
	}
	if (this->_liquidity - value <= 0) {
		std::cout << "⚠️  ERROR: bank can't give loan to client number " << accountId;
		std::cout << " the loan is too high for the bank ! It risks going bankrupt ⚠️" << std::endl;
		return ;
	}
	Account*	account = this->getClientAccountById(accountId);

	if (!account)
		return ;

	this->_liquidity -= value;
	account->setValue(account->getValue() + value);
}

int&	Bank::getLiquidity() {
	return this->_liquidity;
}

Account*	Bank::getClientAccountById(const int accountId) {
	std::vector<Account *>::iterator	it = this->_clientAccounts.begin();

	for (; it != this->_clientAccounts.end(); it++) {
		if (!(*it))
			continue ;

		if ((*it)->getId() == accountId)
			return *it;
	}
	return NULL;
}

std::vector<Account *>&	Bank::getClientAccounts() {
	return this->_clientAccounts;
}

const int&	Bank::getLiquidity() const {
	return this->_liquidity;
}

const std::vector<Account *>&	Bank::getClientAccounts() const {
	return this->_clientAccounts;
}

void	Bank::setLiquidity(const int newLiquidity) {
	this->_liquidity = newLiquidity;
}

std::ostream&	operator<<(std::ostream &stream, const Bank &bank) {
	std::vector<Account*>	clientAccounts = bank.getClientAccounts();
	std::vector<Account*>::iterator	it = clientAccounts.begin();

	stream << "Bank informations : " << std::endl;
	stream << "Liquidity : " << bank.getLiquidity() << std::endl;
	for (; it != clientAccounts.end(); it++) {
		Account* accountPtr = *it;

		if (accountPtr) {
			Account& account = *accountPtr;

			stream << account << std::endl;
		}
	}
	return stream;
}
