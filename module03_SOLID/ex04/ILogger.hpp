#ifndef __ILOGGER_HPP__
# define __ILOGGER_HPP__

# include <string>

class	ILogger {
	public:
		virtual void	write(std::string) = 0;
};

#endif
