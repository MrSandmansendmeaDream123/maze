
#ifndef _room_hpp_
#define _room_hpp_

#define NEIGHBORCOUNT 4
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

#define LOCKED 0 //False
#define UNLOCKED 1//True



#include <string>
#include <array>
#include <iostream>

int revDir(int dir);

class Room{
public:

	/*==========================Constructors==========================
	Two cases:
	First Constructor: it's a room where we know its adjacent rooms.We set them
	with an array of room pointers. as well as providing the current rooms name
	
	Second Constructor: Sets the name of the made room

	The Default Constructor is deleted. This avoids the ability to make a class with
	no name.

	In addition I added the m_id which is the unique id of the room
	*/

	//*****NOTE we need to make the other rooms neighbors the current room in the oposite direction...*****
	//ISSUE!!!!!!   What if null?????      [A ,B ,NULL, D ]  
	// Room(std::string name, const std::array<Room*, NEIGHBORCOUNT> rooms): m_name(name), m_id(count++){ 
	// 	m_lock = UNLOCKED;
	// 	for(int i = 0; i < rooms.size();i++){	
	// 		//Sets the room in the given i direction
	// 		m_rooms[i] = rooms[i];
	// 		//if the other room is not null then set its neighbor too this current room
	// 		//else
	// 		if (rooms[i] != nullptr){
	// 			rooms[i] -> setNeighbor(revDir(i), this);
	// 		}
	// 	}
		
	// }
	Room(std::string name) : m_name(name),m_visited(false),m_id(count++), m_lock(UNLOCKED) {};

	Room() = delete;

    //inline static int count = 0; //Can be used in c++17 and up, but to make more compatable we will use the standard. Ask if you want to know more about

	//Static Variable countaining the counter. Essentially will be incremented in the constructor (when any object made). So we will always know how many
	//Rooms there are, and additionally we can assign this number to them as a ID
	static int count;

	/*
	Should Get the all neighboring rooms, print their names, 
	and directions relative to the current room
	*/
	std::array<Room *, NEIGHBORCOUNT> getNeighbors();
	

	/*
	Return a string with the current rooms name
	*/
	std::string getName();
	

	int getID();

	
	/*
	This method sets multiple Neighbors at once! This is basically the same as
	the first constructor. But it can be done post creation of the room.
	NOTE we need to make the other rooms neighbors the current room in the oposite direction...
	*/
	//void setNeighbors(const std::array<Room*, NEIGHBORCOUNT> rooms);
  	
	/*
	Although mostly done, we need to make sure that the other room knows that
	this room is it's neighbor
	*/
	void setNeighbor(int dir, Room *  &other);
  	//DONE
  	Room* getNeighbor(int dir); 
  
	void setVisited();
	bool getVisited();
  	/*
	This method moves you from the current room, to the room in the direction you specify.
	NOTE: We should not move to a room that does not exist!!!
  	*/
	Room* moveRooms(int dir);

	/*
	Sets the lock status of the room. IF a room is locked it should tell you that it is locked
	and you should remain in the current room that you are in!
	*/
	void setLockStatus(bool status);

	/*
	Gets the lock status of the current room. Useful for seeing if you can move to
	the room. NOTE: If the room is not there and you call this method on it...yeah lol
	*/
	bool getLockStatus();

	
	
std::array<Room*,NEIGHBORCOUNT> m_rooms = {} ; //N:0 E:1 S:2 W:3


private:
	bool m_lock;
	std::string m_name;
	bool m_visited;
	int m_id;
	
	



};


std::string direction(int dir);


#endif
