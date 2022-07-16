#include "room.hpp"
#include "graph.hpp"
#include <string>
#include <stdlib.h> 
Room * Graph::game(){

maze_width = 4;
maze_height = 3;
srand (time(NULL));
wH = maze_width * maze_height;
for(int i = 0; i < wH; i++ )
{
m_maze.push_back(new Room(std::to_string(i)));
}
//static std::stack<std::pair<Room, std::pair<int, int>>> m_stack;
m_stack.push(std::make_pair(m_maze[0],std::make_pair(0,0)));
m_maze[0] -> setVisited();
m_VistedRoomTotal = 1;

auto offset = [&](int x, int y){
    return (m_stack.top().second.second + y) * maze_width 
    + (m_stack.top().second.first + x);
};

while(m_VistedRoomTotal < wH){

//set of unvisted neigbors
std::vector<int> neighbors;

//North 
if(m_stack.top().second.second > 0 && m_maze[offset(0,-1)]->getVisited() == false){
    neighbors.push_back(NORTH);
}
//East 
if(m_stack.top().second.first < maze_width - 1 && m_maze[offset(1,0)]->getVisited() == false){
    neighbors.push_back(EAST);
}
//South 
if(m_stack.top().second.second < maze_height - 1 && m_maze[offset(0,1)] ->getVisited() == false){
    neighbors.push_back(SOUTH);
}
//West
if(m_stack.top().second.first > 0 && m_maze[offset(-1,0)]->getVisited() == false){
    neighbors.push_back(WEST);
}

//if we have pushed items onto the neighbor list
if(!neighbors.empty()){
//Chose at random direction the next path to take
//std::cout<<"=========================================="<<std::endl;
//std::cout<<m_stack.top().first->getName()<<" has "<< neighbors.size()<< " neighbors"<<std::endl;

int randDir = neighbors[rand() % neighbors.size()];
//std::cout<<"Picked " << direction(randDir)<<std::endl;

//Path creation
switch(randDir){
    case(NORTH):
        m_maze[offset(0,0)] ->setNeighbor(NORTH,m_maze[offset(0,-1)]);
        m_stack.push(std::make_pair(m_maze[offset(0,-1)],std::make_pair(m_stack.top().second.first + 0,m_stack.top().second.second - 1)));
        break;
    case(EAST):
        m_maze[offset(0,0)]->setNeighbor(EAST,m_maze[offset(1,0)]);
        m_stack.push(std::make_pair(m_maze[offset(1,0)],std::make_pair(m_stack.top().second.first + 1,m_stack.top().second.second + 0)));
        break;
    case(SOUTH):
        m_maze[offset(0,0)]->setNeighbor(SOUTH,m_maze[offset(0,1)]);
        m_stack.push(std::make_pair(m_maze[offset(0,1)],std::make_pair(m_stack.top().second.first + 0,m_stack.top().second.second + 1)));
        break;
    case(WEST):
        m_maze[offset(0,0)]->setNeighbor(WEST,m_maze[offset(-1,0)]);
        m_stack.push(std::make_pair(m_maze[offset(-1,0)],std::make_pair(m_stack.top().second.first -1,m_stack.top().second.second + 0)));
        break;
}

//m_maze[offset(0,0)]->setVisited();
m_stack.top().first->setVisited();
//std::cout<<"Added "<<m_stack.top().first-> getName()<< std::endl;
m_VistedRoomTotal++;
//std::cout<<"Visited Total: "<<m_VistedRoomTotal<<std::endl;
//std::cout<<"stack size "<<m_stack.size()<<std::endl;
//std::cout<<"=========================================="<<std::endl;

}else{
   // std::cout<<"Popped "<<m_stack.top().first->getName()<< std::endl;
    m_stack.pop();
}


}

return m_maze[0];

}