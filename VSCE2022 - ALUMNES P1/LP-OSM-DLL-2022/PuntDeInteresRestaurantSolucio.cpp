#include "pch.h"
#include "PuntDeInteresRestaurantSolucio.h"

PuntDeInteresRestaurantSolucio::PuntDeInteresRestaurantSolucio(Coordinate coord, std::string name, std::string cuisine, std::string wheelchair):PuntDeInteresBase(coord, name), m_cuisine(cuisine), m_wheelchair(wheelchair) {}


unsigned int PuntDeInteresRestaurantSolucio::getColor() 
{
    if (m_cuisine == "pizza" && m_wheelchair == "yes") 
    {
        return 0x7FFFD4;
    }
    else if (m_cuisine == "chinese") 
    {
        return 0x00FFFF;
    }
    else if (m_wheelchair == "yes") 
    {
        return 0x5D3FD3;
    }
    else 
    {
        return PuntDeInteresBase::getColor(); // Color por defecto definido en la clase base
    }
}