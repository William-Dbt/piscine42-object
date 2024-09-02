#ifndef __EMPLOYEE_HPP__
# define __EMPLOYEE_HPP__

# include <iostream>
# include <string>

# define DEFAULT_HOURLY 11
# define HOURS_IN_SINGLE_DAY 7

class	EmployeeManager;

class	HoursNotWorked {
	public:
		HoursNotWorked() {
			this->_hoursNotWorked = 0;
		}

		const unsigned int&	getHoursNotWorked() const {
			return this->_hoursNotWorked;
		}

	protected:
		unsigned int	_hoursNotWorked;

		void	takeTimeOff(const int& hours) {
			if (hours < HOURS_IN_SINGLE_DAY) {
				std::cerr << "[takeTimeOff] ERROR: the minimum hours to request a time off is " << HOURS_IN_SINGLE_DAY << " hours !" << std::endl;
				return ;
			}
			std::cout << "[takeTimeOff] An employee has requested " << hours << " hours of time off." << std::endl;
			this->_hoursNotWorked += hours;
		}
};

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

		const std::string&	getName() const {
			return this->_name;
		}

		const unsigned int&	getHourlyValue() const {
			return this->_hourlyValue;
		}

		friend class	EmployeeManager;

	protected:
		std::string		_name;
		unsigned int	_hourlyValue;

		virtual int	executeWorkday() = 0;
};

# include "EmployeeManager.hpp"

#endif
