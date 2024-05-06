#include "Bank.hpp"

Bank::Bank(): _liquidity(0) {}

Bank::Bank(const int initialLiquidity): _liquidity(initialLiquidity) {}

Bank::~Bank() {
	std::vector<Account *>::iterator	it = this->_clientAccounts.begin();

	for (; it != this->_clientAccounts.end(); it++)
		delete *it;
}

// lastId refers to the id of the last created account
// We'll use this for each creation of accounts unstead of keeping this in the class
// Because this function is the only way to add an account in the bank
void	Bank::createAccount(const int accountValue) {
	int			bankShare;
	Account*	newAccount;
	static int	lastId = 0;

	bankShare = accountValue * 0.05;
	this->_liquidity += bankShare;

	newAccount = new Account(lastId++, accountValue - bankShare);
	this->_clientAccounts.push_back(newAccount);
}

void	Bank::modifyAccount(const int accountId, const int newValue) {
	Account *accountToModify = this->getClientAccountById(accountId);

	accountToModify->setValue(100);
}

void	Bank::deleteAccount(const int accountId) {
	std::vector<Account *>::iterator	it = this->_clientAccounts.begin();

	for (; it != this->_clientAccounts.end(); it++)
		if ((*it)->getId() == accountId) {
			this->_clientAccounts.erase(it);
			break ;
		}
}

int	Bank::getLiquidity() const {
	return this->_liquidity;
}

Account*	Bank::getClientAccountById(const int accountId) {
	std::vector<Account *>::iterator	it = this->_clientAccounts.begin();

	for (; it != this->_clientAccounts.end(); it++)
		if ((*it)->getId() == accountId)
			return *it;
}

std::vector<Account *>	Bank::getClientAccounts() const {
	return this->_clientAccounts;
}

void	Bank::setLiquidity(const int newLiquidity) {
	this->_liquidity = newLiquidity;
}

std::ostream&	operator<<(std::ostream &stream, const Bank &bank) {
	std::vector<Account*>			clientAccounts = bank.getClientAccounts();
	std::vector<Account*>::iterator	it = clientAccounts.begin();

	stream << "Bank informations : " << std::endl;
	stream << "Liquidity : " << bank.getLiquidity() << std::endl;
	// c++98 version of "for (auto &clientAccount : p_bank.clientAccounts)"
	for (; it != clientAccounts.end(); it++) {
		Account	account = Account((*it)->getId(), (*it)->getValue());

		stream << account << std::endl;
	}
	return stream;
}
