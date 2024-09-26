#ifndef __LIST_HPP__
# define __LIST_HPP__

# include <vector>

template<typename T>
class	List {
	public:
		List() {}

		void	add(T* item) {
			if (!item || this->isInList(item))
				return ;

			this->_list.push_back(item);
		}

		void	remove(T* item) {
			if (!item)
				return ;

			this->_list.erase(this->getItemIt(item));
		}

		bool	isInList(T* item) {
			if (this->getItemIt(item) != this->_list.end())
				return true;

			return false;
		}

		const std::vector<T*>&	getList() {
			return this->_list;
		}

	protected:
		typename std::vector<T*>::iterator	getItemIt(T* item) {
			if (this->_list.size() == 0)
				return this->_list.end();

			typename std::vector<T*>::iterator it;

			for (it = this->_list.begin(); it != this->_list.end(); it++)
				if ((*it) == item)
					return it;

			return this->_list.end();
		}

		std::vector<T*>	_list;
};

#endif
