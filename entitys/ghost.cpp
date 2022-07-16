#include "entity.hpp"
#include "../knife.cpp"


class Ghost : public Entity{
public:
    Ghost(std::string name) {
        m_health = 10;
        m_name = name;
        //m_inventory.push_back(Knife());
        id = 0;
    }

    int getHealth() override{
        return m_health;
    }
    std::string getName() override{
        return m_name;
    }

    std::string checkInv() override{
        m_inventory[0].getDescription();
    }
    
    void attack(Entity &other) override{
        other.setHealth(m_inventory[0].attack());
    }

    void image() override{
        StringHandle::ghost();
    }
    
};
    //Ghost s = Ghost("Mr Booo");
	//s.image();