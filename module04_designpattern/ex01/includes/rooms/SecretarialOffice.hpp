#ifndef __SECRETARIALOFFICE_HPP__
# define __SECRETARIALOFFICE_HPP__

# include <vector>
# include "../Room.hpp"
# include "../Form.hpp"

class	SecretarialOffice: public Room {
	public:
		void	archiveForm(Form* form) {
			if (!form)
				return ;

			this->_archivedForms.push_back(form);
		}

		bool	isScretarialOffice() {
			return true;
		}

	private:
		std::vector<Form*>	_archivedForms;
};

#endif
