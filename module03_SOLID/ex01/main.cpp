#include "Command.hpp"

int	main() {
	Command	cmd1("toto", std::map<std::string, std::pair<int, int> >());
	Command	cmd2("titi", std::map<std::string, std::pair<int, int> >());

	std::cout << cmd1 << std::endl;
	std::cout << cmd2;
}
