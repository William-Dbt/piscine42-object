#include <iostream>
#include "Worker.hpp"

#define RED "\033[1;31m"
#define BLUE "\033[1;34m"
#define CLEAR "\033[0m"

int	main() {
	{
		std::cout << "➡️  Composition part\n" << std::endl;

		std::cout << RED;
		std::cout << "Creation of workers by default constructor and with values" << std::endl;
		Worker	jean;

		std::cout << jean << std::endl;

		Worker	paul(18, 458, 17, 4570);

		std::cout << paul << std::endl;

		std::cout << "First worker is moving to join the second one !" << std::endl;
		jean.setPosition(18, 54, 15);

		std::cout << "\nHe found some gems on the road and earned exps !\n" << std::endl;
		jean.earnExp(1020);

		std::cout << jean << CLEAR << std::endl;
	}
	std::cout << "------------------------------\n" << std::endl;
	{
		std::cout << "➡️  Aggregation\n" << std::endl;

		std::cout << BLUE;
		Worker	jacques(428, 872, 480, 34060);

		std::cout << jacques << std::endl;

		std::cout << "Let's create a shovel and give it to our worker" << std::endl;
		Shovel	shovel;

		jacques.takeShovel(shovel);
		std::cout << jacques << std::endl;

		std::cout << "Let's create a second worker who will stole the shovel of the first one" << std::endl;
		Worker*	chirac = new Worker(427, 872, 480, 24990);

		chirac->takeShovel(shovel);
		std::cout << jacques << std::endl;
		std::cout << *chirac << std::endl;

		std::cout << "Second worker has done working, first one needs the shovel" << std::endl;
		delete chirac;
		jacques.takeShovel(shovel);

		std::cout << jacques << std::endl;
	}
	return 0;
}
