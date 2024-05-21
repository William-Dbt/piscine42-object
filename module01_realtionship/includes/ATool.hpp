#ifndef __ATOOL_HPP__
# define __ATOOL_HPP__

# include "Worker.hpp"

class	ATool {
	public:
		ATool() {
			std::cout << "[ATool] Constructor called" << std::endl;
			this->_worker = nullptr;
			this->_numberOfUses = 0;
		}

		virtual ~ATool() {
			std::cout << "[ATool] Destructor called" << std::endl;
			if (this->_worker)
				this->_worker->removeTool(*this);
		};

		virtual void	use() = 0;

		void	setWorker(Worker* worker) {
			if (this->_worker != nullptr)
				this->_worker->removeTool(*this);

			this->_worker = worker;
		}

		const Worker*	getWorker() const {
			return this->_worker;
		}

	protected:
		Worker*	_worker;

		int	_numberOfUses;
};

#endif
