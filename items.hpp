#include <iostream>

#pragma once
class Items{
public:
    virtual std::string  getDescription() = 0;
    virtual ~Items();
    virtual int  getDur() = 0;
    virtual int attack() = 0;


protected:
    std::string m_description;
    int m_durability;
};