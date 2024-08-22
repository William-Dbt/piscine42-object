#include <unistd.h>
#include "Command.hpp"
#include "ThuesdayDiscountCommand.hpp"
#include "PackageReductionDiscountCommand.hpp"

int	main() {
	std::cout << "The way I does the Command class is to first, create the list of articles in a map<string, pair<int, int> > where the key is the name of the article to add and the pair is the quantity and the price\n";
	std::cout << "Assuming a client named Toto, wanted to buy some clothes in our warehouse for his own store\n";
	std::cout << "Let's create the list of articles he wants to command" << std::endl;

	std::map<std::string, std::pair<int, int> >	articlesList;

	articlesList["T-shirts"] = std::pair<int, int>(20, 14);
	articlesList["Cargo pants"] = std::pair<int, int>(10, 35);
	articlesList["Short pants"] = std::pair<int, int>(15, 17);
	articlesList["Caps"] = std::pair<int, int>(8, 12);
	articlesList["Hats"] = std::pair<int, int>(15, 8);
	articlesList["Custom shoes"] = std::pair<int, int>(5, 79);
	std::cout << "\nHere the list of articles :\n";

	std::map<std::string, std::pair<int, int> >::iterator	it;

	for (it = articlesList.begin(); it != articlesList.end(); it++)
		std::cout << "- " << (*it).first << " x" << (*it).second.first << " (" << (*it).second.second << "€)\n";

	std::cout << std::endl;
	std::cout << "Let's create the command for Toto" << std::endl;

	Command	commandForToto("Toto", articlesList);

	std::cout << commandForToto << std::endl;

	std::cout << "Hector, a rival of Toto wants the same clothes for his store, let's sell him the same command from Toto" << std::endl;

	Command	commandForHector("Hector", articlesList);

	std::cout << commandForHector << std::endl;

	std::cout << "Toto will not be happy but, money first !\n" << std::endl;

	sleep(2);
	std::cout << "------------------------------\n" << std::endl;

	std::cout << "A month passed and Hector has no more items to sell, he wants to fill another command with us to fill his store." << std::endl;
	std::cout << "But today it's tuesday ! It means that the cost his command will be reduced by 10 percent\n" << std::endl;

	ThuesdayDiscountCommand	discountCommandForHector("Hector", articlesList);

	std::cout << discountCommandForHector;

	sleep(2);
	std::cout << "\n------------------------------\n" << std::endl;

	std::cout << "It's a good month for our warehouse and to thank our most valuable clients, will make a discount on their commands, -10€ for every command that exceed 150€" << std::endl;
	std::cout << "Toto is here today to buy some socks in large quantity" << std::endl;

	articlesList.clear();
	articlesList["Blue socks"] = std::pair<int, int>(50, 4);
	articlesList["Red socks"] = std::pair<int, int>(50, 5);
	articlesList["Black socks"] = std::pair<int, int>(50, 2);
	articlesList["White socks"] = std::pair<int, int>(50, 1);

	std::cout << "Here the list of what he's buying:" << std::endl;
	for (it = articlesList.begin(); it != articlesList.end(); it++)
		std::cout << "- " << (*it).first << " x" << (*it).second.first << " (" << (*it).second.second << "€)\n";

	std::cout << "\nThe total amount of his command is 600€ but, it's a regular client, let's make him a reduction" << std::endl;

	PackageReductionDiscountCommand	packageDiscountCommandForToto("Toto", articlesList);

	std::cout << packageDiscountCommandForToto;
}
