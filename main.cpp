#include "room.hpp"
#include "graph.hpp"
#include "stringhandle.hpp"

using namespace std;




int main(){
	Room * r;
	
	//Room start("Start", rooms);

	r = Graph().game();
	cout<< "Your journey begins in room " << r -> getName()<<endl;
	r -> getNeighbors();
    Room * temp = r;
	bool gameState = true;
	
	
	string f;   //maybe something over here
	string command;
	while(gameState){
		cout<<"What would you like to do ? "<<endl;
		cin >> command;
		//lower
		StringHandle::toLowerString(command);
		printf("\033[41m\n");
		cout<<"Which direction will you travel? "  <<endl;
		printf("\033[0m\n");

		//Read in a string

		cin>> f;
		StringHandle::toLowerString(f);

		cout<<f<<endl;
		//swith case directions
		if (f == "north"){  
			r = r -> moveRooms(NORTH);
		}
		else if ( f == "east"){
			r = r -> moveRooms(EAST);
		}
		else if (f == "south"){
			r = r ->moveRooms(SOUTH); 
		}
		else if (f == "north"){
			r = r -> moveRooms(WEST);
		}
		else { 
			cout << "You attempt to move in an unspecified direction, and fail." << endl; 
			continue;
		}
    // r = r->moveRooms(f);
	cout<<"You moved "<< f << " to room " << r->getName() <<". the rooms available are as follows:"<<endl;
	 r->getNeighbors();
	}
	delete temp;
	
}