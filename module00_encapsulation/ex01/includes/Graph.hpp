#ifndef __GRAPH_HPP__
# define __GRAPH_HPP__

# define PROMPT ">& "
# include <list>

typedef struct s_Vector2 {
	float	x;
	float	y;
} t_vector2;

class	Graph {
	public:
		Graph();

		void	addVector(float x, float y);
		void	addVector(t_vector2 points);

		void	show();

	private:
		t_vector2				_size;
		std::list<t_vector2>	_points;

		bool	isPointsInList(float x, float y);
};

#endif
