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

	private:
		int	_hoursMade;
};

#endif
