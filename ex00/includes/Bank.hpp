#ifndef __BANK_HPP__
# define __BANK_HPP__

# include <vector>
# include "Account.hpp"

// TODO: Try to encapsulate Account class in Bank class

class	Bank {
	public:
		Bank();
		Bank(const int initialLiquidity);

		~Bank();

		void	createAccount(const int accountValue);
		void	modifyAccount(const int accountId, const int newValue);
		void	deleteAccount(const int accountId);

		int						getLiquidity() const;
		Account*				getClientAccountById(const int accountId);
		std::vector<Account *>	getClientAccounts() const;

	private:
		int	_liquidity;

		std::vector<Account *>	_clientAccounts;

		void	setLiquidity(const int newLiquidity);
};

std::ostream&	operator<<(std::ostream &stream, const Bank &bank);

#endif
