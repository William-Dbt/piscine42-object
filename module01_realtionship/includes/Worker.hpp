#ifndef __WORKER_HPP__
# define __WORKER_HPP__

# include <list>
# include "ATool.hpp"

typedef struct	Position {
	int x;
	int y;
	int z;
} t_position;

typedef struct	Statictic {
	int	level;
	int	exp;
} t_statistic;

class	Worker {
	public:
		Worker();
		Worker(int x, int y, int z, int exp);
		~Worker();

		void	takeTool(ATool&	tool);
		void	removeTool(ATool& tool);

		bool	isWorkerHaveTool(ATool& tool);

		void	setPosition(int x, int y, int z);
		void	earnExp(int exp);

		const t_position&	getPosition() const;
		const t_statistic&	getStatistics() const;

	private:
		std::list<ATool*>	_toolsBag;

		t_position	_position;
		t_statistic	_statistics;
};

std::ostream&	operator<<(std::ostream &stream, const Worker &worker);

#endif
