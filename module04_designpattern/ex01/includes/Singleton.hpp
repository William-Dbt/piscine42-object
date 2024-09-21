#ifndef __SINGLETON_HPP__
# define __SINGLETON_HPP__

# include <mutex>

template<class T>
class	Singleton {
	public:
		Singleton*	getInstance() {
			this->_mutex.lock();
			if (!this->_instance)
				this->_instance = new Singleton<T>();

			this->_mutex.unlock();
			return this->_instance;
		}

	private:
		Singleton() {}
		Singleton(const Singleton&) {}

		Singleton&	operator=(const Singleton&) {}

		static Singleton*	_instance = NULL;
		static std::mutex	_mutex;
};

#endif
