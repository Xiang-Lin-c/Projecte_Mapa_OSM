#include "Pch.h"
#include "CamiSolucio.h"

CamiSolucio::CamiSolucio() {
    // Inicializamos las coordenadas con los valores predefinidos
    m_coords = {{0,0}};
    m_tipus = "";
}

std::vector<Coordinate> CamiSolucio::getCamiCoords() {
    return m_coords;
}
void CamiSolucio::afegirCoordenada(vector<Coordinate>& c) {
    for (int i = 0; i < c.size(); i++) { 
        m_coords.push_back(c[i]);
    }
}
