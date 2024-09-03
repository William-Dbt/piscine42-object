#include <vector>
#include "FileLogger.hpp"
#include "StreamLogger.hpp"

int	main() {
	ILogger*	firstFileLogger = new FileLogger("logs/toto.log");
	ILogger*	secondFileLogger = new FileLogger("logs/toto_header.log", "** TOTO LOGS **");
	ILogger*	firstStreamLogger = new StreamLogger(std::cout);
	ILogger*	secondStreamLogger = new StreamLogger(std::cout, "** OUTPUT **");

	std::vector<ILogger*>	loggers;

	loggers.push_back(firstFileLogger);
	loggers.push_back(secondFileLogger);
	loggers.push_back(firstStreamLogger);
	loggers.push_back(secondStreamLogger);

	std::vector<std::string>	logMessages;

	logMessages.push_back("Hello");
	logMessages.push_back("from");
	logMessages.push_back("logger");
	logMessages.push_back("!");

	std::vector<ILogger*>::iterator		itLoggers;
	std::vector<std::string>::iterator	itMessages;

	for (itLoggers = loggers.begin(); itLoggers != loggers.end(); itLoggers++)
		for (itMessages = logMessages.begin(); itMessages != logMessages.end(); itMessages++)
			(*itLoggers)->write((*itMessages));

	return 0;
}
