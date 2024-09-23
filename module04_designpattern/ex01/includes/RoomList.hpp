#ifndef __ROOMLIST_HPP__
# define __ROOMLIST_HPP__

# include "Singleton.hpp"
# include "List.hpp"
# include "Room.hpp"

class	RoomList : public Singleton<RoomList>, public List<Room> {};

#endif
