#include "EmployeeManager.hpp"
#include "Employee.hpp"
#include "TempWorker.hpp"
#include "ContractEmployee.hpp"
#include "Apprentice.hpp"

int	main() {
	std::cout << "Create an employee manager named Kevin" << std::endl;

	EmployeeManager	manager("Kevin");

	std::cout << "\nCreate one tempWorker, one ContractEmployee and one Apprentice then assign them to Kevin\n";

	Employee*	toto = new TempWorker("Toto", 14);
	Employee*	titi = new ContractEmployee("Titi");
	Employee*	tutu = new Apprentice("Tutu", 9);

	manager.addEmployee(toto);
	manager.addEmployee(titi);
	manager.addEmployee(tutu);

	std::cout << manager << std::endl;

	std::cout << "Let's execute a month of work (4 weeks of 5 days)\n";
	for (int i = 0; i < 20; i++)
		manager.executeWorkday();

	std::cout << "\nTiti and Tutu have to take 14 hours of time off for them\n";

	manager.giveTimeOffToEmployee(titi, 14);
	manager.giveTimeOffToEmployee(tutu, 14);

	std::cout << "Tutu is declaring 40 hours of school this month\n\n";

	manager.registerSchoolHoursForApprentice(tutu, 40);

	manager.calculatePayroll();

	std::cout << "\nToto asked to be mobilized for 10 hours to get more cash\n";

	manager.mobilizeEmployee(toto, 10);

	manager.calculatePayroll();
}
