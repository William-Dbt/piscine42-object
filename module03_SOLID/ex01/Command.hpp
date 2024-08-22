#ifndef __COMMAND_HPP__
# define __COMMAND_HPP__

# include <iostream>
# include <ctime>
# include <string>
# include <map>

// _id is the id of the command
// _date is the date when the command is placed
// _clients is the name of the client for the command
// _articles<std::string, std::pair<int, int> > refers to the name of the product, the quantity and the price
class	Command {
	public:
		Command() {
			this->_id = this->_numberOfCommands++;
			this->_client = "Unknown";
			this->_date = time(NULL);
		}

		Command(const std::string& client,
				const std::map<std::string, std::pair<int, int> >&	articles)
		{
			this->_id = this->_numberOfCommands++;
			this->_date = time(NULL);
			this->_client = client;
			this->_articles = articles;
		}

		int	get_total_price() {
			if (this->_articles.size() == 0)
				return 0;

			int	totalPrice = 0,
				articleQuantity,
				articlePrice;

			std::map<std::string, std::pair<int, int> >::iterator	it;
			for (it = this->_articles.begin(); it != this->_articles.end(); it++) {
				articleQuantity = (*it).second.first;
				articlePrice = (*it).second.second;
				totalPrice += articleQuantity * articlePrice;
			}
			return totalPrice;
		}

		const int&	getId() const {
			return this->_id;
		}

		const char*	getStringDate() const {
			return ctime(&this->_date);
		}

		const std::string&	getClient() const {
			return this->_client;
		}

	protected:
		static int	_numberOfCommands;

		int											_id;
		time_t										_date;
		std::string									_client;
		std::map<std::string, std::pair<int, int> >	_articles;
};

// Initialize the number of commands to 0. this variable will be used to set the ids of the commands.
int	Command::_numberOfCommands = 0;

std::ostream&	operator<<(std::ostream &stream, Command &command) {
	stream << "----- COMMAND INFOS -----\n";
	stream << "- Id : " << command.getId() << '\n';
	stream << "- Date : " << command.getStringDate();
	stream << "- Client : " << command.getClient() << '\n';
	stream << "- Total price of the command : " << command.get_total_price() << '\n';
	stream << "-------------------------" << std::endl;
	return stream;
}

#endif
