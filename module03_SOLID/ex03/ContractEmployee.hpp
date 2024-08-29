#ifndef __CONTRACTEMPLOYEE_HPP__
# define __CONTRACTEMPLOYEE_HPP__

# include "Employee.hpp"

class	ContractEmployee: public Employee {
	public:
		ContractEmployee() {
			this->_workedHours = 0;
			this->_hoursNotWorked = 0;
		}

		ContractEmployee(const std::string& name, const int& hourlyValue = DEFAULT_HOURLY) {
			this->_name = name;
			this->_hourlyValue = hourlyValue;
			this->_workedHours = 0;
			this->_hoursNotWorked = 0;
		}

		virtual int	executeWorkday() {
			std::cout << "[Workday] Employee " << this->_name << " is working today !" << std::endl;
			this->_workedHours += HOURS_PER_DAY_WORKED;

			return HOURS_PER_DAY_WORKED;
		}

		void	requestTimeOff(const std::string& reason, const int& hours) {
			if (hours < 7) {
				std::cerr << "[requestTimeOff] ERROR: the minimum hours to request a time off is 7 hours !" << std::endl;
				return ;
			}
			std::cout << "[requestTimeOff] Employee " << this->_name << " has requested " << hours << " hours of time off for " << reason << " !" << std::endl;
			this->_hoursNotWorked += hours;
		}

	private:
		int	_workedHours;
		int	_hoursNotWorked;
};

#endif
