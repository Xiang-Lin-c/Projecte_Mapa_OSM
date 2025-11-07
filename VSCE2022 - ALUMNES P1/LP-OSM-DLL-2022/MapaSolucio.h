#pragma once
#include "MapaBase.h"
#include "PuntDeInteresBotigaSolucio.h"
#include "PuntDeInteresRestaurantSolucio.h"
#include "CamiBase.h"
class MapaSolucio : public MapaBase {
public:
	MapaSolucio();
	void getPdis(std::vector<PuntDeInteresBase*>&);
private:
	PuntDeInteresBotigaSolucio* pBotiga;
	PuntDeInteresRestaurantSolucio* pRestaurant;
};