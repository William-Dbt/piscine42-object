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

		virtual int	executeWorkday() {
			std::cout << "[TempWorker] Employee " << this->_name << " is working today !" << std::endl;
			this->_hoursMade += HOURS_PER_DAY_WORKED;
			return HOURS_PER_DAY_WORKED;
		}

		// virtual int	calculatePayroll() {
		// 	return (this->_hoursMade * this->_hourlyValue);
		// }

		friend class EmployeeManager;

	protected:
		int	_hoursMade;

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
