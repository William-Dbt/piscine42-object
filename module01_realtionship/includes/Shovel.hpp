#ifndef __SHOVEL_HPP__
# define __SHOVEL_HPP__

# include "ATool.hpp"

class Worker;

class	Shovel : ATool {
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
