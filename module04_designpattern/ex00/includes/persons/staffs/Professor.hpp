#ifndef __PROFESSOR_HPP__
# define __PROFESSOR_HPP__

# include "../Staff.hpp"
# include "../../Course.hpp"

class	Professor: public Staff {
	public:
		void	assignCourse(Course* p_course);
		void	doClass();
		void	closeCourse();

	private:
		Course*	_currentCourse;
};

#endif
