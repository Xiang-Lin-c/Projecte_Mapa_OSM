#pragma once
#include "CamiBase.h"
#include <vector>
#include <string>
using namespace std;
class CamiSolucio : public CamiBase {
private:
    std::string m_id;
    std::vector<Coordinate> m_coords;
    std::string m_tipus;

public:
    CamiSolucio(); 
    ~CamiSolucio();
    CamiSolucio(string id, string tipus) : m_id(id), m_tipus(tipus) {};
    std::vector<Coordinate> getCamiCoords() override; 
    void afegirCoordenada(vector<Coordinate>& c) override;
};