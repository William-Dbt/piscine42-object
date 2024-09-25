#ifndef __COURSE_HPP__
# define __COURSE_HPP__

# define NB_CLASS_TO_GRADUATE		15
# define MAX_NB_STUDENTS_PER_CLASS	24

# include <string>
# include <vector>

class	Student;
class	Professor;
class	CourseFinishedForm;

class	Course {
	public:
		Course(const std::string& p_name);

		void	assign(Professor* p_professor);
		void	subscribe(Student* p_student);

		bool	isStudentInCourse(const Student* student);

		const std::string&	getName() const;
		const Professor*	getResponsable() const;
		const std::vector<Student*>&		getStudentsList() const;

		friend class CourseFinishedForm;

	private:
		std::string				_name;
		Professor*				_responsable;
		std::vector<Student*>	_students;

		int	_numberOfClassToGraduate;
		int	_maximumNumberOfStudents;
};

# include "persons/Student.hpp"
# include "persons/staffs/Professor.hpp"
# include "forms/CourseFinishedForm.hpp"

#endif
