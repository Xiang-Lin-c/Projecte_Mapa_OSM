	#pragma once
	#include "pch.h"

	#include "MapaBase.h"
	#include "PuntDeInteresBase.h"
	#include "PuntDeInteresBotigaSolucio.h"
	#include "PuntDeInteresRestaurantSolucio.h"
	#include "CamiBase.h"
	#include "CamiSolucio.h"
	#include "Util.h"
	#include <vector>
class MapaSolucio : public MapaBase 
{
public:
	MapaSolucio();
	~MapaSolucio();

	void getPdis(std::vector<PuntDeInteresBase*>&) override;
	void getCamins(std::vector<CamiBase*>& camins) override;
	void parsejaXmlElements(std::vector<XmlElement>& xmlElements) override;

private:
	std::vector<PuntDeInteresBase*> m_pdis;
	std::vector<CamiSolucio*> m_camins;
};