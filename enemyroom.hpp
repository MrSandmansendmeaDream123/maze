#include "room.hpp"
#include "entitys/ghost.cpp"
#include <vector>

class EnemyRoom: public Room{
public:
    void addEnemy(){
       m_entitylist.push_back(Ghost("Boo"));
    }

    void showEnemy(){
        m_entitylist.front().image();
    }
private:
   std::vector<Entity> m_entitylist;
};