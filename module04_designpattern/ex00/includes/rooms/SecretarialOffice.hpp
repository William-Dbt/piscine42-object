#ifndef __SECRETARIALOFFICE_HPP__
# define __SECRETARIALOFFICE_HPP__

# include <vector>
# include "../Room.hpp"
# include "../Form.hpp"

class	SecretarialOffice: public Room {
	private:
		std::vector<Form*>	_archivedForms;
};

#endif
