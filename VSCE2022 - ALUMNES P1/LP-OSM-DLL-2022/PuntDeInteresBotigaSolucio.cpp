#include "pch.h"
#include "PuntDeInteresBotigaSolucio.h"


std::string PuntDeInteresBotigaSolucio::getName() 
{
    return m_name;
}

unsigned int PuntDeInteresBotigaSolucio::getColor() 
{
    if (m_shop == "supermarket") 
    {
        return 0xDFFF00;
    }
    else if (m_shop == "tobacco") 
    {
        return 0xFF7F50;
    }
    else if (m_shop == "bakery") 
    {
        if (m_openingHours.find("06:00-22:00") != std::string::npos && m_wheelchair == "yes") 
        {
            return 0x4CBB17;
        }
        return 0xFA8072;
    }
    else {
        return 0xFFEA00; // Color por defecto para otras tiendas
    }
}