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

		const unsigned int&	getSchoolHours() const {
			return this->_schoolHours;
		}

		friend class	EmployeeManager;

	private:
		unsigned int	_schoolHours;

		virtual int	executeWorkday() {
			std::cout << "[Apprentice] Employee " << this->_name << " is working today !" << std::endl;
			return HOURS_IN_SINGLE_DAY;
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
