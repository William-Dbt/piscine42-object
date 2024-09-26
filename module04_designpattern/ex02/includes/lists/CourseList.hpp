#ifndef __COURSELIST_HPP__
# define __COURSELIST_HPP__

# include "../Singleton.hpp"
# include "../List.hpp"
# include "../Course.hpp"

class	CourseList : public Singleton<CourseList>, public List<Course> {};

#endif
