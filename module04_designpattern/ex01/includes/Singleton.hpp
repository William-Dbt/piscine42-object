#ifndef __SINGLETON_HPP__
# define __SINGLETON_HPP__

# include <mutex>

template<typename T>
class	Singleton {
	public:
		Singleton(const Singleton&) {}
		Singleton&	operator=(const Singleton&) {}

		static T*	getInstance() {
			if (!_instance) {
				_mutex.lock();
				if (!_instance)
					_instance = new T();

				_mutex.unlock();
			}
			std::cout << "instance ptr : " << _instance << '\n' << std::endl;
			return _instance;
		}

	protected:
		Singleton() {}

	private:
		static T*			_instance;
		static std::mutex	_mutex;
};

template <typename T>
T* Singleton<T>::_instance = NULL;

template <typename T>
std::mutex Singleton<T>::_mutex;

#endif
