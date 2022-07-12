#include <stack>
#include <vector>
#include "room.hpp"
#pragma once

struct Graph{

int m_VistedRoomTotal;

std::stack<std::pair<Room*, std::pair<int, int>>> m_stack;

std::vector<Room*> m_maze;
int maze_width;
int maze_height ;

int wH;

Room * game();

};
