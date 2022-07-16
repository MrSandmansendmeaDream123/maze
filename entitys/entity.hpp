#include "../items.hpp"
#include <vector>
#include "../stringhandle.hpp"

#pragma once

class Entity{

public:
    virtual int getHealth() = 0;
    virtual std::string getName() = 0;
    virtual std::string checkInv() = 0;
    virtual void image() = 0;
    
virtual void attack(Entity &other) = 0; 
 void setHealth(int x){
     m_health -= x;
 }
protected:
    int m_health;
    std::vector<Items> m_inventory;
    std::string m_name;
    int id;
};