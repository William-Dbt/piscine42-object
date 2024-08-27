#ifndef __EMPLOYEE_HPP__
# define __EMPLOYEE_HPP__

# include <iostream>
# include <string>

# define DEFAULT_HOURLY 11

class	Employee {
	public:
		Employee() {
			this->_name = "Unknown";
			this->_hourlyValue = DEFAULT_HOURLY;
		}

		Employee(const std::string& name, const int& hourlyValue) {
			this->_name = name;
			this->_hourlyValue = hourlyValue;
		}

		virtual ~Employee() {}

		// We make this method pure svirtual for the classes that will inherit from Employee class
		// and that will managed in their way the executeWorkday() function
		virtual int	executeWorkday() = 0;

		// Special method for TempWorker class
		// virtual void	mobilizeEmployee(const int& hours) = 0;

		// Special method for ContractEmployee class
		// virtual void	requestTimeOff(const std::string& reason, const int& hours) = 0;

		const std::string&	getName() const {
			return this->_name;
		}

		const int&	getHourlyValue() const {
			return this->_hourlyValue;
		}

	protected:
		std::string	_name;
		int			_hourlyValue;
};

#endif
