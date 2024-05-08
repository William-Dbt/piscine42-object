#ifndef __ACCOUNT_HPP__
# define __ACCOUNT_HPP__

# include <iostream>

class Account {
	public:
		Account();
		Account(const int id, const int value);
		Account(const Account& ref);

		const int&	getId() const;
		const int&	getValue() const;

	private:
		int	_id;
		int	_value;

		void	setId(const int id);
		void	setValue(const int value);

		int&		getId();
		int&		getValue();

		friend class Bank;
};

std::ostream&	operator<<(std::ostream &stream, const Account &account);

class Bank;

#endif