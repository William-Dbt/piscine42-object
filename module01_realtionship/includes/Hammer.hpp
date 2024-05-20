#ifndef __HAMMER_HPP__
# define __HAMMER_HPP__

# include "ATool.hpp"

class Worker;

class	Hammer : public ATool {
	public:
		Hammer();
		~Hammer();

		void	use();

		void	setWorker(Worker* worker);

		const Worker*	getWorker() const;

	private:
		Worker*	_worker;

		int	_numberOfUses;
};

# include "Worker.hpp"

#endif
