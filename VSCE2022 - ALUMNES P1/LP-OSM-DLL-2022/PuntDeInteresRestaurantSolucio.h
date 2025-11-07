#pragma once
#include "PuntDeInteresBase.h"

class PuntDeInteresRestaurantSolucio : public PuntDeInteresBase 
{
private:
    std::string m_cuisine;
    std::string m_wheelchair;

public:
    PuntDeInteresRestaurantSolucio(Coordinate coord, std::string name, std::string cuisine, std::string wheelchair = "no");

    std::string getName() override;
    unsigned int getColor() override;
};