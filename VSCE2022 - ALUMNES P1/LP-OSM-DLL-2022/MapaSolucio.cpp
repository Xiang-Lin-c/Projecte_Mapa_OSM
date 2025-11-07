#include"MapaSolucio.h"

void MapaSolucio::getPdis(std::vector<PuntDeInteresBase*>& pdis) {
	Coordinate cBotiga = { 41.4918606, 2.1465411 };
	Coordinate cRestaurant = { 41.4902204, 2.1406477 };
	pBotiga = new PuntDeInteresBotigaSolucio(cBotiga, "La Millor Pastisseria", "bakery");
	pRestaurant = new PuntDeInteresRestaurantSolucio(cRestaurant, "El Millor Restaurant", "regional", "si");

	pdis.push_back(pBotiga);
	pdis.push_back(pRestaurant);

}
