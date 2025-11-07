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
using namespace std;
class MapaSolucio : public MapaBase {
public:
	MapaSolucio();
	~MapaSolucio();
	void getPdis(std::vector<PuntDeInteresBase*>&) override;
	void getCamins(std::vector<CamiBase*>& camins) override;
	void parsejaXmlElements(std::vector<XmlElement>& xmlElements) override;

private:
	void afegirNodes(const XmlElement& xmlElement);
	void afegirPuntInteres(XmlElement xmlElement);
	void afegirCamins(XmlElement xmlElement);
	vector<PuntDeInteresBase*> m_pInteres;
	vector<CamiBase*> m_camins;
	vector<pair <string, Coordinate>> m_nodes;
};