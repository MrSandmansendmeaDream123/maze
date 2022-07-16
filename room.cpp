	#include "room.hpp"

	//Static Variable, means it is shared by all members of the class. Very useful so we can have uniqueIDs...
	int Room::count = 0;

	/*==========================DONE==========================
	Should Get the all neighboring rooms, print their names, 
	and directions relative to the current room
	Handles null pointer by checking if the pointer is a nullptr
	*/
	std::array<Room *, NEIGHBORCOUNT> Room::getNeighbors(){
		for(int i = 0; i < m_rooms.size();i++){
			if(m_rooms[i] != nullptr){
				std::cout << m_rooms[i] -> getName() << " is in "<< direction(i)<<std::endl;
			}
			else{
				std::cout <<"There is no room in the "<< direction(i)<<std::endl;
			}
		}
		return m_rooms;
	} 
	

	/*==========================DONE==========================
	Return a string with the current rooms name
	*/
	std::string Room::getName(){
		return m_name;
	}

	void Room::setVisited(){
		m_visited = true;
	}

	bool Room::getVisited(){
		//std::cout<<m_visited<<std::endl;
		return m_visited;
	}



	
	/*==========================IMPLEMENT==========================
	This method sets multiple Neighbors at once! This is basically the same as
	the first constructor. But it can be done post creation of the room.
	NOTE we need to make the other rooms neighbors the current room in the oposite direction...
	*/
	//void Room::setNeighbors(const std::array<Room*, NEIGHBORCOUNT> rooms){ }
  	
  	/*==========================DONE==========================
	This method moves you from the current room, to the room in the direction you specify.
	NOTE: We should not move to a room that does not exist!!!
  	*/
	Room* Room::moveRooms(int dir){ return m_rooms[dir]; }

	/*==========================DONE==========================
	Sets the lock status of the room. IF a room is locked it should tell you that it is locked
	and you should remain in the current room that you are in!
	*/
	void Room::setLockStatus(bool status){ 
		m_lock = status;
	}


	/*==========================DONE==========================
	Gets the lock status of the current room. Useful for seeing if you can move to
	the room. NOTE: If the room is not there and you call this method on it...yeah lol
	*/
	bool Room::getLockStatus(){ return m_lock; }

/*==========================DONE==========================
Sets the Neighbor of the current room in the given direction dir. DONE
We need to make the other rooms neighbors the current room in the oposite direction. DONE
*/
void Room::setNeighbor(int dir, Room* &other) {
 	m_rooms[dir] = * &other;
	other->m_rooms[revDir(dir) ] = this;
}
/*==========================Almost==========================
Gets the Neighbor in the specifed direction dir
*/
Room* Room::getNeighbor(int dir){
	//if the room at dir was null what would happen?
    std::cout << m_rooms[dir] -> getName() <<std::endl;
	return m_rooms[dir];
}

//Return the ID of the current Room 
int Room::getID(){
	return m_id;
}

void Room::changeName(std::string newName){
	m_name = newName;
}



//Should tell what direction the room is N is 0, E is 1, S is 2, W is 3 
std::string direction(int dir){
  
  switch (dir){
    case NORTH:
        return "North";
        break;
    case EAST:
    		return "East";
        break;
    case SOUTH:
      	return "South";
      	break;
    case WEST:
      	return "West";
      	break;
    default:
      	return "You cannot tell what direction";
      	break;
  }
  
}
/*==========================DONE==========================
Should reverse the direction of the passed in direction dir. 
*/
int revDir(int dir){
	switch (dir){
		case NORTH:
			return SOUTH;
			break;
		case EAST:
			return WEST;
			break;
		case SOUTH:
			return NORTH;
			break;
		case WEST:
			return EAST;
			break;
	}
	return 0;
}
  
