#include "pch.h"
#include "CamiSolucio.h"

CamiSolucio::CamiSolucio() {
    // Inicializamos las coordenadas con los valores predefinidos
    m_coords = 
    {
        {41.4928803, 2.1452381},
        {41.4929072, 2.1452474},
        {41.4933070, 2.1453852},
        {41.4939882, 2.1456419}
    };
}

std::vector<Coordinate> CamiSolucio::getCamiCoords() {
    return m_coords;
}