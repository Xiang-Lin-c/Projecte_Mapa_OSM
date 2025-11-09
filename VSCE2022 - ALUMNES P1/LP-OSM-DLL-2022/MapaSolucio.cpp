#include "pch.h"
#include"MapaSolucio.h"

MapaSolucio::MapaSolucio() {
}
MapaSolucio::~MapaSolucio() {
	for (auto p : m_camins) delete p;
	for (auto p : m_pInteres) delete p;
}
void MapaSolucio::afegirNodes(const XmlElement& xmlElement) {
	string id = "";
	Coordinate coordenada;
	double lat = 0.0, lon = 0.0;
	id = xmlElement.atributs[0].second	;
	for (int i = 0; i < xmlElement.atributs.size(); i++) {
		if (xmlElement.atributs[i].first == "id")
		{	
			id = xmlElement.atributs[i].second;

		}
		if (xmlElement.atributs[i].first == "lat") {
			lat = stod(xmlElement.atributs[i].second);
		}

		if (xmlElement.atributs[i].first == "lon")
			lon = stod(xmlElement.atributs[i].second);
	}
	coordenada = { lat, lon };
	m_nodes.push_back(make_pair(id, coordenada));
}
void MapaSolucio::afegirPuntInteres( XmlElement xmlElement) {
	string name, wheelchair;
	string shop, openinghour;
	string amenity, cuisine;
	Coordinate coordenada = { 0,0 };
	double lat = 0.0, lon = 0.0;
	bool kindPlace = 0;  // 0 botiga,  1 restaurant
	for (int i = 0; i < xmlElement.fills.size(); i++) {
		if (xmlElement.fills[i].first == "tag") {
			pair<string, string> valorTag = Util::kvDeTag(xmlElement.fills[i].second);
			if (valorTag.first == "shop") {
				shop = valorTag.second;
				kindPlace = 0;
			}
			if (valorTag.first == "amenity") {
				amenity = valorTag.second;
				kindPlace = 1;
			}
			if (valorTag.first == "opening_hours")
				openinghour = valorTag.second;
			if (valorTag.first == "cuisine")
				cuisine = valorTag.second;

			if (valorTag.first == "name")
				name = valorTag.second;
			if (valorTag.first == "wheelchair")
				wheelchair = valorTag.second;

		}
	}
	for (int i = 0; i < xmlElement.atributs.size(); i++) {

		if (xmlElement.atributs[i].first == "lat") {
			lat = stod(xmlElement.atributs[i].second);
		}

		if (xmlElement.atributs[i].first == "lon")
			lon = stod(xmlElement.atributs[i].second);
	}
	coordenada = { lat, lon };
	
	PuntDeInteresBase* p;
	if (kindPlace == 0) {
		p = new PuntDeInteresBotigaSolucio(coordenada, name, shop, openinghour, wheelchair);
	}
	else
		p = new PuntDeInteresRestaurantSolucio(coordenada, name, cuisine, wheelchair);

	m_pInteres.push_back(p);
}

void MapaSolucio::afegirCamins(XmlElement xmlElement) {
	string id = xmlElement.atributs[0].second;
	vector<string> referencies;
	string tipus;
	CamiBase* c;
	for (const auto& fill : xmlElement.fills) {
		if (fill.first == "nd") {
			for (const auto& atributs : fill.second) {
				if (atributs.first == "ref")
					referencies.push_back(atributs.second);
			}
		}
		if (fill.first == "tag") {
			for (const auto& pair : fill.second) {
				if (pair.second == "highway")
					tipus = "highway";
			}
		}
	}

	vector<Coordinate> coordenades;

	for (int i = 0; i < referencies.size(); i++) {
		for (int j = 0; j < m_nodes.size(); j++) {
			if (referencies[i] == m_nodes[j].first) {
				coordenades.push_back(m_nodes[j].second);
			}
		}
	}

	c = new CamiSolucio(id, tipus);
	c->afegirCoordenada(coordenades);
	m_camins.push_back(c);

}

void MapaSolucio::getPdis(std::vector<PuntDeInteresBase*>& pdis) {
	for (int i = 0; i < m_pInteres.size(); i++) {
		pdis.push_back(m_pInteres[i]);
	}

}

void MapaSolucio::getCamins(std::vector<CamiBase*>& camins){
	for (int i = 0; i < m_camins.size(); i++){
		if(m_camins[i]->getTipus() == "highway")
		camins.push_back(m_camins[i]);
	}
}

void MapaSolucio::parsejaXmlElements(std::vector<XmlElement>& xmlElements) {

	for (int i = 0; i < xmlElements.size(); i++) {
		if (xmlElements[i].id_element == "node") {
			afegirNodes(xmlElements[i]);

			for(int j = 0; j < xmlElements[i].fills.size(); j++){
				if (xmlElements[i].fills[j].first == "tag") {
					pair<string, string> valorTag = Util::kvDeTag(xmlElements[i].fills[j].second);
					if (valorTag.first == "name")
						afegirPuntInteres(xmlElements[i]);
				}
			}
		}
		else if(xmlElements[i].id_element == "way") {
			afegirCamins(xmlElements[i]);
		}
	}
}
