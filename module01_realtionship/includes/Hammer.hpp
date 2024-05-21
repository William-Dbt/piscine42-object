#ifndef __HAMMER_HPP__
# define __HAMMER_HPP__

# include "ATool.hpp"

class Worker;

class	Hammer : public ATool {
	public:
		Hammer();
		~Hammer();

		void	use();
};

# include "Worker.hpp"

#endif
