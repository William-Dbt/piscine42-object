#ifndef __BANK_HPP__
# define __BANK_HPP__

# include <vector>
# include "Account.hpp"

class	Bank {
	public:
		Bank();
		Bank(const int initialLiquidity);

		~Bank();

		void	createAccount(const int accountValue);
		void	createAccount(const Account& account);
		void	addValueToAccount(const int accountId, const int value);
		void	removeValueToAccount(const int accountId, const int value);
		void	deleteAccount(const int accountId);

		void	giveLoan(const int accountId, const int value);

		const int&						getLiquidity() const;
		const std::vector<Account *>&	getClientAccounts() const;

	private:
		int	_liquidity;
		int	_lastAccountId;

		std::vector<Account *>	_clientAccounts;

		void	setLiquidity(const int newLiquidity);

		int&					getLiquidity();
		Account*				getClientAccountById(const int accountId);
		std::vector<Account *>&	getClientAccounts();
};

std::ostream&	operator<<(std::ostream &stream, const Bank &bank);

#endif
