#ifndef __SECRETARIALOFFICE_HPP__
# define __SECRETARIALOFFICE_HPP__

# include <vector>
# include "../Room.hpp"
# include "../Form.hpp"
# include "../persons/staffs/Secretary.hpp"

class	SecretarialOffice: public Room {
	public:
		friend class Secretary;

	protected:
		std::vector<Form*>	_archivedForms;
};

#endif
