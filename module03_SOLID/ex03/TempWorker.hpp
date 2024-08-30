#ifndef __TEMPWORKER_HPP__
# define __TEMPWORKER_HPP__

# include "Employee.hpp"

class	EmployeeManager;

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

		friend class EmployeeManager;

	protected:
		unsigned int	_hoursMade;

		virtual int	executeWorkday() {
			std::cout << "[TempWorker] Employee " << this->_name << " is working today !" << std::endl;
			this->_hoursMade += HOURS_IN_SINGLE_DAY;
			return HOURS_IN_SINGLE_DAY;
		}

		virtual unsigned int	calculatePayroll() {
			return 2;
		}

		void mobilizeEmployee(const int& hours) {
			if (hours <= 0) {
				std::cerr << "[TempWorker] ERROR(mobilizeEmployee): employee " << this->_name << " can't work less than 1 hour !" << std::endl;
				return ;
			}
			std::cout << "[TempWorker] Employee " << this->_name << " has been mobilized today for " << hours << " hours !" << std::endl;
			this->_hoursMade += hours;
		}
};

# include "EmployeeManager.hpp"

#endif
