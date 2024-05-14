#ifndef __WORKER_HPP__
# define __WORKER_HPP__

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
		Worker(int x, int y, int z, int level, int exp);

		const t_position&	getPosition() const;
		const t_statistic&	getStatistics() const;

	private:
		t_position	_position;
		t_statistic	_statistics;
};

#endif
