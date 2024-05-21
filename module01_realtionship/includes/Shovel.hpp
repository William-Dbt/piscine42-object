#ifndef __SHOVEL_HPP__
# define __SHOVEL_HPP__

# include "ATool.hpp"

class Worker;

class	Shovel : public ATool {
	public:
		Shovel();
		~Shovel();

		void	use();
};

# include "Worker.hpp"

#endif
