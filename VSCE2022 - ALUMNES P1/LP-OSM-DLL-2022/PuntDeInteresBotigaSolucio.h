#pragma once
#include "PuntDeInteresBase.h"

class PuntDeInteresBotigaSolucio : public PuntDeInteresBase 
{
private:
    std::string m_shop;
    std::string m_openingHours;
    std::string m_wheelchair;

public:
    PuntDeInteresBotigaSolucio(Coordinate coord, std::string name, std::string shop, std::string openingHours = "", std::string wheelchair = "no");

    std::string getName() override;
    unsigned int getColor() override;
};