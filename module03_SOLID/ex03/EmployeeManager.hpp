#ifndef __EMPLOYEEMANAGER_HPP__
# define __EMPLOYEEMANAGER_HPP__

# include <iostream>
# include <set>
# include "Employee.hpp"
# include "TempWorker.hpp"
# include "ContractEmployee.hpp"
# include "Apprentice.hpp"

class	EmployeeManager {
	public:
		EmployeeManager() {
			this->_workdaysExecuted = 0;
			this->_name = "Unknown";
		}

		EmployeeManager(const std::string& name) {
			this->_workdaysExecuted = 0;
			this->_name = name;
		}

		void	addEmployee(Employee* employee) {
			if (!employee) {
				std::cerr << "[EmployeeManager] ERROR(addEmployee): an error occured with the employee." << std::endl;
				return ;
			}
			std::pair<std::set<Employee*>::iterator, bool>	isEmployeeAdded;

			isEmployeeAdded = this->_employeesList.insert(employee);
			if (!isEmployeeAdded.second)
				std::cerr << "[EmployeeManager] ERROR(addEmployee): employee already added in the list of the manager." << std::endl;
		}

		void	removeEmployee(Employee* employee) {
			if (!employee) {
				std::cerr << "[EmployeeManager] ERROR(removeEmployee): an error occured with the employee." << std::endl;
				return ;
			}
			this->_employeesList.erase(employee);
		}

		void	executeWorkday() {
			std::set<Employee*>::iterator	it;

			for (it = this->_employeesList.begin(); it != this->_employeesList.end(); it++) {
				if ((*it) != NULL)
					(*it)->executeWorkday();
				else
					this->_employeesList.erase(it);
			}
			this->_workdaysExecuted++;
		}

		void	calculatePayroll() {
			std::set<Employee*>::iterator	it;

			std::cout << "----- Payroll for the month for each employee -----\n";
			for (it = this->_employeesList.begin(); it != this->_employeesList.end(); it++)
				std::cout << "- " <<(*it)->getName() << ": " << (*it)->calculatePayroll() << "€ for ";

			std::cout << "---------------------------------------------------" << std::endl;
		}

		void	mobilizeEmployee(Employee* employee, const int& hours) {
			if (!employee) {
				std::cerr << "[EmployeeManager] ERROR(mobilizeEmployee): an error occured with the employee." << std::endl;
				return ;
			}
			if (this->_employeesList.find(employee) == this->_employeesList.end()) {
				std::cerr << "[EmployeeManager] ERROR(mobilizeEmployee): you are not in charge of the employee " << employee->getName() << " !" << std::endl;
				return ;
			}

			TempWorker*	tempEmployee = dynamic_cast<TempWorker*>(employee);

			if (tempEmployee)
				tempEmployee->mobilizeEmployee(hours);
			else
				std::cerr << "[EmployeeManager] ERROR(mobilizeEmployee): employee " << employee->getName() << " is not a tempWorker ! He can't be mobilized." << std::endl;
		}

		void	giveTimeOffToEmployee(Employee* employee, const int& hours) {
			if (!employee) {
				std::cerr << "[EmployeeManager] ERROR(giveTimeOffToEmployee): an error occured with the employee." << std::endl;
				return ;
			}
			if (this->_employeesList.find(employee) == this->_employeesList.end()) {
				std::cerr << "[EmployeeManager] ERROR(giveTimeOffToEmployee): you are not in charge of the employee " << employee->getName() << " !" << std::endl;
				return ;
			}

			ContractEmployee*	ctrEmployee = dynamic_cast<ContractEmployee*>(employee);
			Apprentice*			apprentice = dynamic_cast<Apprentice*>(employee);

			if (ctrEmployee || apprentice) {
				if (ctrEmployee)
					ctrEmployee->takeTimeOff(hours);
				else
					apprentice->takeTimeOff(hours);
			}
			else
				std::cerr << "[EmployeeManager] ERROR(giveTimeOffToEmployee): employee " << employee->getName() << " is not a contractEmployee or an apprentice ! He can't ask for time off." << std::endl;
		}

		void	registerSchoolHoursForApprentice(Employee* employee, const int& hours) {
			if (!employee) {
				std::cerr << "[EmployeeManager] ERROR(registerSchoolHoursForApprentice): an error occured with the employee." << std::endl;
				return ;
			}
			if (this->_employeesList.find(employee) == this->_employeesList.end()) {
				std::cerr << "[EmployeeManager] ERROR(registerSchoolHoursForApprentice): you are not in charge of the employee " << employee->getName() << " !" << std::endl;
				return ;
			}

			Apprentice*	apprentice = dynamic_cast<Apprentice*>(employee);

			if (apprentice)
				apprentice->registerSchoolHours(hours);
			else
				std::cerr << "[EmployeeManager] ERROR(registerSchoolHoursForApprentice): employee " << employee->getName() << " is not an apprentice ! He can't register school hours." << std::endl;
		}

		const std::string&	getName() const {
			return this->_name;
		}

		const std::set<Employee*>&	getManagedEmployees() const {
			return this->_employeesList;
		}

	private:
		unsigned int		_workdaysExecuted;
		std::string			_name;
		std::set<Employee*>	_employeesList;
};

std::ostream&	operator<<(std::ostream &stream, const EmployeeManager &employeeManager) {
	std::set<Employee*>::iterator	it;

	stream << "----- " << employeeManager.getName() << " employee's list -----\n";
	for (it = employeeManager.getManagedEmployees().begin(); it != employeeManager.getManagedEmployees().end(); it++)
		stream << "- " << (*it)->getName() << " (" << (*it)->getHourlyValue() << "€/h)\n";

	stream << "-------------------------------" << std::endl;
	return stream;
}

#endif
