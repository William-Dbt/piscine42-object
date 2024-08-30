#ifndef __APPRENTICE_HPP__
# define __APPRENTICE_HPP__

# include "Employee.hpp"

class	EmployeeManager;

class	Apprentice: public Employee, public HoursNotWorked {
	public:
		Apprentice() {
			this->_schoolHours = 0;
		}

		Apprentice(const std::string& name, const int& hourlyValue = DEFAULT_HOURLY) {
			this->_name = name;
			this->_hourlyValue = hourlyValue;
			this->_schoolHours = 0;
		}

		friend class	EmployeeManager;

	private:
		unsigned int	_schoolHours;

		virtual int	executeWorkDay() {
			std::cout << "[Apprentice] Employee " << this->_name << " is working today !" << std::endl;
			return HOURS_IN_SINGLE_DAY;
		}

		virtual unsigned int	calculatePayroll() {
			return 3;
		}

		void	registerSchoolHours(const int& hours) {
			if (hours < 0) {
				std::cerr << "[Apprentice] ERROR(registerSchoolHours): hours must be greated than 0." << std::endl;
				return ;
			}
			this->_schoolHours += hours;
		}
};

# include "EmployeeManager.hpp"

#endif
