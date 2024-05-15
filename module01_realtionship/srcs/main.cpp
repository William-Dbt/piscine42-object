#include <iostream>
#include "Worker.hpp"

#define RED "\033[1;31m"
#define CLEAR "\033[0m"

int	main() {
	{
		std::cout << "➡️  Composition part\n" << std::endl;

		std::cout << RED;
		std::cout << "Creation of workes by default constructor and with values" << std::endl;
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
		std::cout << "toto" << std::endl;
	}
	return 0;
}
