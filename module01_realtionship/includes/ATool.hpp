#ifndef __ATOOL_HPP__
# define __ATOOL_HPP__

class	Worker;

class	ATool {
	public:
		virtual ~ATool() {};

		virtual void	use() = 0;

		// This part is specified as pure method to force new classes to have this methods
		// setWorker is used to save the worker who uses the tool
		virtual void	setWorker(Worker* worker) = 0;

		// getWorker is used to know who's using the tool
		virtual const Worker*	getWorker() const = 0;
};

# include "Worker.hpp"

#endif
