#ifndef __GETDATETIME_HPP__
# define __GETDATETIME_HPP__

# include <string>
# include <ctime>

std::string	getDateTime() {
	time_t		currentTime;
	struct tm*	timeInfo;
	char		buffer[80];

	time(&currentTime);
	timeInfo = localtime(&currentTime);
	strftime(buffer, sizeof(buffer), "%F %r", timeInfo);

	return buffer;
}

#endif
