#ifndef __PROFESSOR_HPP__
# define __PROFESSOR_HPP__

# include "Staff.hpp"

class	Course;

class	Professor: public Staff {
	public:
		Professor(const std::string& name);

		void	assignCourse(Course* course);
		void	doClass();
		void	closeCourse();

		Course*	getCurrentCourse() const;

	private:
		Course*	_currentCourse;
};

# include "Staff.hpp"
# include "../Course.hpp"

#endif
