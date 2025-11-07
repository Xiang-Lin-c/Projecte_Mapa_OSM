#include "pch.h"
#include"MapaSolucio.h"

MapaSolucio::MapaSolucio() {
	Coordinate cBotiga = { 41.4918606, 2.1465411 };
	Coordinate cRestaurant = { 41.4902204, 2.1406477 };
	pBotiga = new PuntDeInteresBotigaSolucio(cBotiga, "La Millor Pastisseria", "bakery", "", "no");
	pRestaurant = new PuntDeInteresRestaurantSolucio(cRestaurant, "El Millor Restaurant", "regional", "si");
	m_camins.push_back(new CamiSolucio());
}

void MapaSolucio::getPdis(std::vector<PuntDeInteresBase*>& pdis) {
	Util::escriuEnMonitor("PDI: " + pBotiga->getName());
	pdis.push_back(pBotiga);
	Util::escriuEnMonitor("PDI: " + pRestaurant->getName());

	pdis.push_back(pRestaurant);

}

void MapaSolucio::getCamins(std::vector<CamiBase*>& camins){
	for (int i = 0; i < m_camins.size(); i++){
		camins.push_back(m_camins[i]);
	}
}

void MapaSolucio::parsejaXmlElements(std::vector<XmlElement>& xmlElements) {

}
