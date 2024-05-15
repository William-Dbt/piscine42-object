#ifndef __SHOVEL_HPP__
# define __SHOVEL_HPP__

class Worker;

class	Shovel {
	public:
		Shovel();

		void	use();

		void	setWorker(Worker* worker);

		const Worker*	getWorker() const;

	private:
		Worker*	_worker;

		int	_numberOfUses;
};

# include "Worker.hpp"

#endif
