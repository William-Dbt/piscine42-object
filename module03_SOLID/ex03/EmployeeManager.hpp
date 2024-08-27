#ifndef __EMPLOYEEMANAGER_HPP__
# define __EMPLOYEEMANAGER_HPP__

# include <iostream>
# include <set>
# include "Employee.hpp"

class	EmployeeManager {
	public:
		void	addEmployee(Employee* employee) {
			if (!employee) {
				std::cerr << "[EmployeeManager] ERROR(addEmployee): an error occured with the employee." << std::endl;
				return ;
			}
			std::pair<std::set<Employee*>::iterator, bool>	isEmployeeAdded;

			isEmployeeAdded = this->_managedEmployeesList.insert(employee);
			if (!isEmployeeAdded.second)
				std::cerr << "[EmployeeManager] ERROR(addEmployee): employee already added in the list of the manager." << std::endl;
		}

		void	removeEmployee(Employee* employee) {
			if (!employee) {
				std::cerr << "[EmployeeManager] ERROR(removeEmployee): an error occured with the employee." << std::endl;
				return ;
			}
			this->_managedEmployeesList.erase(employee);
		}

		void	executeWorkday() {
			std::set<Employee*>::iterator	it;

			for (it = this->_managedEmployeesList.begin(); it != this->_managedEmployeesList.end(); it++) {
				if ((*it) != NULL)
					(*it)->executeWorkday();
				else
					this->_managedEmployeesList.erase(it);
			}
		}

		// void	calculatePayroll() {
		// 	std::set<Employee*>::iterator	it;

		// 	std::cout << "----- Payroll for the month -----\n";
		// 	for (it = this->_managedEmployeesList.begin(); it != this->_managedEmployeesList.end(); it++) {
		// 		std::cout << (*it)->getName()
		// 	}
		// }

	private:
		std::set<Employee*>	_managedEmployeesList;
};

#endif
