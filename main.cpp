#include "room.hpp"
#include "graph.hpp"
#include "stringhandle.hpp"
#include "entitys/entity.hpp"
#include "entitys/ghost.cpp"
using namespace std;




int main(){
	Room * r;
	

	r = Graph().game();


	
	StringHandle::potion();
	printf("\033[32m\n");
	cout<< "Your journey begins in a seemingly endless forest. You observe your surroundings and notice there are four directions... \nNot knowing what to do, you mark your current location as room 0" <<endl;
	printf("\033[0m\n");
	r -> getNeighbors();
    Room * temp = r;
	bool gameState = true;
	
	
	string f;   //maybe something over here
	string command;

 
	while(gameState){
		cout<<"What would you like to do? "<<endl;
		cin >> command;
		StringHandle::toLowerString(command);
		StringHandle::tokenizer(command);
		//Movement Commands
		
		//Item Commands
	    
		//Specialty Commands
        
  





		printf("\033[1m\n");
		cout<<"Which direction will you travel? "  <<endl;
		printf("\033[0m\n");

		//Read in a string

		cin>> f;
		StringHandle::toLowerString(f);

		//cout<<f<<endl;
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
		else if (f == "west"){
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