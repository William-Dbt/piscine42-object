#ifndef __SHOVEL_HPP__
# define __SHOVEL_HPP__

class	Shovel {
	public:
		Shovel();
		Shovel(int numberOfUses);

		void	use();

	private:
		int	_numberOfUses;
};

#endif
