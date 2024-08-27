#include "EmployeeManager.hpp"
#include "Employee.hpp"
#include "TempWorker.hpp"

int	main() {
	std::cout << "Create an employee manager named Kevin" << std::endl;

	EmployeeManager	manager("Kevin");

	std::cout << manager;

	Employee*	firstEmployee = new TempWorker();
	Employee*	secondEmployee = new TempWorker("toto", 9);

	manager.addEmployee(firstEmployee);
	manager.addEmployee(secondEmployee);

	std::cout << manager;

	firstEmployee->mobilizeEmployee(5);
}
