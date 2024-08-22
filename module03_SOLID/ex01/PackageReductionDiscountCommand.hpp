#ifndef __PACKAGEREDUCTIONDISCOUNTCOMMAND_HPP__
# define __PACKAGEREDUCTIONDISCOUNTCOMMAND_HPP__

# include "Command.hpp"

class	PackageReductionDiscountCommand: public Command {
	public:
		PackageReductionDiscountCommand(const std::string& client,
								const std::map<std::string, std::pair<int, int> >&	articles)
		{
			this->_client = client;
			this->_articles = articles;
		}

		int	get_total_price() {
			int	commandTotalPrice = Command::get_total_price();

			if (commandTotalPrice > 150)
				commandTotalPrice -= 10;

			return commandTotalPrice;
		}
};

std::ostream&	operator<<(std::ostream &stream, PackageReductionDiscountCommand &command) {
	stream << "----- COMMAND INFOS -----\n";
	stream << "- Id : " << command.getId() << '\n';
	stream << "- Date : " << command.getStringDate();
	stream << "- Client : " << command.getClient() << '\n';
	stream << "- Total price of the command : " << command.get_total_price() << '\n';
	stream << "-------------------------" << std::endl;
	return stream;
}

#endif
