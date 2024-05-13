#include <iostream>
#include "Graph.hpp"

int	main() {
	Graph	graph;

	graph.addVector(0, -2);
	graph.addVector(0, 0);
	graph.addVector(2, 2);

	t_vector2	vector;

	vector.x = 4;
	vector.y = 2;
	graph.addVector(vector);
	
	vector.x = 2;
	vector.y = 4;
	graph.addVector(vector);
	graph.show();
	return 0;
}