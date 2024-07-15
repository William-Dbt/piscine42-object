#ifndef __WORKSHOP_HPP__
# define __WORKSHOP_HPP__

# include <string>
# include "Worker.hpp"

class	Workshop {
	public:
		Workshop();
		Workshop(const std::string name);
		~Workshop();

		void	registerWorker(Worker* worker);
		void	releaseWorker(Worker* worker);
		bool	isWorkerRegistred(Worker* worker);

		void	executeWorkDay();

		const std::string&	getName() const;

	private:
		std::string	_name;

		std::list<Worker*>	_workers;
};

#endif
