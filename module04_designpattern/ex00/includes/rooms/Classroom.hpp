#ifndef __CLASSROOM_HPP__
# define __CLASSROOM_HPP__

# include "../Room.hpp"
# include "../Course.hpp"

class	Classroom: public Room {
	public:
		Classroom();

		void	assignCourse(Course* p_course) {
			this->_currentRoom = p_course;
		}

		virtual bool	canEnter(Person* person) {
			if (this->_occupants.size() < MAX_NB_STUDENTS_PER_CLASS)
				return true;

			return false;
		}

	private:
		Course*	_currentRoom;
};

#endif
