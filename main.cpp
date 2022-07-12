#include "room.hpp"
#include "graph.hpp"


int main(){
	Room * r;
	
	//Room start("Start", rooms);
	Room start("start");
	r = &start;
	r = Graph().game();
	std::cout<< " Your  journey begins in room: " << r -> getName()<<std::endl;
	r -> getNeighbors();
    Room * temp = r;
	bool gameState = true;
	
	
	int f;
	while(gameState){
		printf("\033[41m\n");
	std::cout<<" Which direction will you travel? "  <<std::endl;
	printf("\033[0m\n");

	std::cin>> f;
     r = r->moveRooms(f);
	std::cout<<" You moved  "<< direction(f) << " to room " << r->getName() <<" the rooms avalibale are now "<<std::endl;
	 r->getNeighbors();

	}
	delete temp;
	//r->getNeighbors();



}