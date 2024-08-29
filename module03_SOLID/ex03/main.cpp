#include "EmployeeManager.hpp"
#include "Employee.hpp"
#include "TempWorker.hpp"

int	main() {
	std::cout << "Create an employee manager named Kevin" << std::endl;

	EmployeeManager	manager("Kevin");

	std::cout << manager << std::endl;

	std::cout << "Create three TempWorker, one by default and another one named Titi and another one named Toto who will be paid 13€/h.\n" << std::endl;

	Employee*	tmpWorkerUnknown = new TempWorker();
	Employee*	tmpWorkerTiti = new TempWorker("Titi");
	Employee*	tmpWorkerToto = new TempWorker("Toto", 13);

	manager.addEmployee(tmpWorkerUnknown);
	manager.addEmployee(tmpWorkerTiti);
	manager.addEmployee(tmpWorkerToto);

	std::cout << manager << std::endl;

	std::cout << "Let's initiate a workday" << std::endl;
	manager.executeWorkday();

	std::cout << "\nToto need more cash before leaving the company, the manager will mobilize him for 9 more hours" << std::endl;
	manager.mobilizeEmployee(tmpWorkerToto, 9);
}
