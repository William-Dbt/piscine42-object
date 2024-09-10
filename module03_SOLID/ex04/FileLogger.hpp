#ifndef __FILELOGGER_HPP__
# define __FILELOGGER_HPP__

# include <iostream>
# include <fstream>
# include <string>
# include "ILogger.hpp"
# include "getDateTime.hpp"

class	FileLogger: public ILogger {
	public:
		FileLogger(const std::string& filePath, const std::string& header = ""): _header(header) {
			this->_file.open(filePath.c_str());
			if (!this->_file.is_open())
				std::cerr << "[FileLogger] ERROR: cannot open file " << filePath << std::endl;
		}

		~FileLogger() {
			if (this->_file.is_open())
				this->_file.close();
		}

		virtual void	write(std::string content) {
			if (!this->_file.is_open())
				return ;

			if (!this->_header.empty())
				this->_file << getDateTime() << " - " << this->_header << ": ";

			this->_file << content << std::endl;
		}

		void	setHeader(const std::string& header) {
			this->_header = header;
		}

		const std::string&	getHeader() const {
			return this->_header;
		}

	private:
		std::ofstream	_file;
		std::string		_header;
};

#endif
