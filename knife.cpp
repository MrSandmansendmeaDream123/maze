#include "items.hpp"
#include "entitys/entity.hpp"
#include <bits/stdc++.h>


class Knife: public Items{

public:
    Knife() {
         m_description = " A stainless steel combat knife...hopefully I won't need it";  
         m_damage = 5;
         m_durability   =  INT_MAX;   //Knife should never break
    }
    std::string  getDescription() override{
        return m_description;
    }

    int getDur() override{
        return m_durability;
    }

    int attack() override{
       return m_damage;
    }

    private:
        int m_damage; 
   
      
    



};

/*#include <iostream>

class Items{
public:
    virtual std::string  getDescription() = 0;
    
    virtual ~Items();
    virtual std::string  getDur() = 0;
    virtual void useItem() = 0;

protected:
    std::string m_description;
    int m_damage;
    int m_durability;
};*/

