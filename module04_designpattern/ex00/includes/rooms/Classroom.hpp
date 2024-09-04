#ifndef __CLASSROOM_HPP__
# define __CLASSROOM_HPP__

# include "../Room.hpp"
# include "../Course.hpp"

class	Classroom: public Room {
	public:
		Classroom();

		void	assignCourse(Course* p_course);

	private:
		Course*	_currentRoom;
};

#endif
