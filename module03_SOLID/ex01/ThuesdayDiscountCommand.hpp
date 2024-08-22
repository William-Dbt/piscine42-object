#ifndef __THUESDAYDISCOUNTCOMMAND_HPP__
# define __THUESDAYDISCOUNTCOMMAND_HPP__

# include "Command.hpp"

class	ThuesdayDiscountCommand: public Command {
	public:
		ThuesdayDiscountCommand(const std::string& client,
								const std::map<std::string, std::pair<int, int> >&	articles)
		{
			this->_client = client;
			this->_articles = articles;
		}

		int	get_total_price() {
			int	totalPrice = Command::get_total_price();

			return (totalPrice - totalPrice * 0.1);
		}
};

std::ostream&	operator<<(std::ostream &stream, ThuesdayDiscountCommand &command) {
	stream << "----- COMMAND INFOS -----\n";
	stream << "- Id : " << command.getId() << '\n';
	stream << "- Date : " << command.getStringDate();
	stream << "- Client : " << command.getClient() << '\n';
	stream << "- Total price of the command : " << command.get_total_price() << '\n';
	stream << "-------------------------" << std::endl;
	return stream;
}

#endif
