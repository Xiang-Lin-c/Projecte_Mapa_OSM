#pragma once
#include "PuntDeInteresBase.h"

class PuntDeInteresBotigaSolucio : public PuntDeInteresBase 
{
private:
    std::string m_shop;
    std::string m_openingHours;
    std::string m_wheelchair;

public:

    PuntDeInteresBotigaSolucio(Coordinate coord, std::string name, std::string shop, std::string openingHours, std::string wheelchair) : PuntDeInteresBase(coord, name), m_shop(shop), m_openingHours(openingHours), m_wheelchair(wheelchair) {
    }
    unsigned int getColor() override;
};