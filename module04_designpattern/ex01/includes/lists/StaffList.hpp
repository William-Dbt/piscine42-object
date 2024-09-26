#ifndef __STAFFLIST_HPP__
# define __STAFFLIST_HPP__

# include "../Singleton.hpp"
# include "../List.hpp"
# include "../persons/Staff.hpp"

class	StaffList : public Singleton<StaffList>, public List<Staff> {};

#endif
