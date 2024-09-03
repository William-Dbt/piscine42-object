#ifndef __STREAMLOGGER_HPP__
# define __STREAMLOGGER_HPP__

# include <iostream>
# include <string>
# include "ILogger.hpp"
# include "getDateTime.hpp"

class	StreamLogger: public ILogger {
	public:
		StreamLogger(std::ostream& stream, const std::string& header = ""): _stream(stream), _header(header) {}

		~StreamLogger() {}

		virtual void	write(std::string content) {
			if (!this->_header.empty())
				this->_stream << getDateTime() << " - " << this->_header << ": ";

			this->_stream << content << std::endl;
		}

		void	setHeader(const std::string& header) {
			this->_header = header;
		}

		const std::string&	getHeader() const {
			return this->_header;
		}

	private:
		std::ostream&	_stream;
		std::string		_header;
};

#endif
