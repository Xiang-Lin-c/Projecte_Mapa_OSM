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
	class MapaSolucio : public MapaBase {
	public:
		MapaSolucio();
		~MapaSolucio() { delete pBotiga; delete pRestaurant; }
		void getPdis(std::vector<PuntDeInteresBase*>&) override;
		void getCamins(std::vector<CamiBase*>& camins) override;
		void parsejaXmlElements(std::vector<XmlElement>& xmlElements) override;

	private:
		PuntDeInteresBotigaSolucio* pBotiga;
		PuntDeInteresRestaurantSolucio* pRestaurant;
		std::vector<CamiBase*> m_camins;
	};