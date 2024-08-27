#ifndef __TEMPWORKER_HPP__
# define __TEMPWORKER_HPP__

# include "Employee.hpp"

class	TempWorker: public Employee {
	public:
		TempWorker() {
			this->_hoursMade = 0;
		}

		TempWorker(const std::string& name, const int& hourlyValue = DEFAULT_HOURLY) {
			this->_name = name;
			this->_hourlyValue = hourlyValue;
			this->_hoursMade = 0;
		}

		virtual int	executeWorkday() {
			std::cout << "[Workday] Employee " << this->_name << " is working today !" << std::endl;
			this->_hoursMade += 7;
			return 7;
		}

		virtual void mobilizeEmployee(const int& hours) {
			if (hours <= 0) {
				std::cerr << "[mobilizeEmployee] ERROR: Employee " << this->_name << " can't work less than 1 hour !" << std::endl;
				return ;
			}
			std::cout << "[mobilizeEmployee] Employee " << this->_name << " is working today for " << hours << " hours !" << std::endl;
			this->_hoursMade += hours;
		}

	private:
		int	_hoursMade;
};

#endif
