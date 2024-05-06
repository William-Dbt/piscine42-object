#include <iostream>
#include "Account.hpp"

Account::Account(): _id(-1), _value(0) {}

Account::Account(const int id, const int value) : _id(id), _value(value) {}

Account::Account(const Account& ref) {
	if (this != &ref) {
		this->_id = ref.getId();
		this->_value = ref.getValue();
	}
}

void	Account::setId(const int id) {
	this->_id = id;
}

int Account::getId() const {
	return this->_id;
}

void	Account::setValue(const int accountValue) {
	this->_value = accountValue;
}

int	Account::getValue() const {
	return this->_value;
}

std::ostream&	operator<<(std::ostream &stream, const Account &account) {
	stream << "[" << account.getId() << "] - [" << account.getValue() << "]";
	return stream;
}
