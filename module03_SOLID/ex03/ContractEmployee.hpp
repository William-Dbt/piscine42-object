#ifndef __CONTRACTEMPLOYEE_HPP__
# define __CONTRACTEMPLOYEE_HPP__

# include "Employee.hpp"

class	EmployeeManager;

class	ContractEmployee: public Employee, public HoursNotWorked {
	public:
		ContractEmployee() {}

		ContractEmployee(const std::string& name, const int& hourlyValue = DEFAULT_HOURLY) {
			this->_name = name;
			this->_hourlyValue = hourlyValue;
		}

		friend class EmployeeManager;

	private:
		virtual int	executeWorkday() {
			std::cout << "[ContractEmployee] Employee " << this->_name << " is working today !" << std::endl;
			return HOURS_IN_SINGLE_DAY;
		}

		virtual unsigned int	calculatePayroll() {
			return 1;
		}
};

# include "EmployeeManager.hpp"

#endif
