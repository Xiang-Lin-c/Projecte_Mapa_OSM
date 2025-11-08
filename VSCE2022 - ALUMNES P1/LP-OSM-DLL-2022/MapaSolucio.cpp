#include "pch.h"
#include "Util.h"
#include "PuntDeInteresBotigaSolucio.h"
#include "PuntDeInteresRestaurantSolucio.h"
#include "CamiSolucio.h"
#include <iostream>
#include"MapaSolucio.h"


MapaSolucio::MapaSolucio() {
    Coordinate cBotiga = { 41.4918606, 2.1465411 };
    Coordinate cRestaurant = { 41.4902204, 2.1406477 };

    // Crear instancias específicas y añadirlas a m_pdis
    m_pdis.push_back(new PuntDeInteresBotigaSolucio(cBotiga, "La Millor Pastisseria", "bakery", "", "no"));
    m_pdis.push_back(new PuntDeInteresRestaurantSolucio(cRestaurant, "El Millor Restaurant", "regional", "si"));

    // Inicializar un camino de ejemplo
    m_camins.push_back(new CamiSolucio());
}

MapaSolucio::~MapaSolucio() {
    // Liberar memoria de los puntos de interés y caminos
    for (auto it = m_pdis.begin(); it != m_pdis.end(); ++it) {
        delete* it;
    }
    for (auto it = m_camins.begin(); it != m_camins.end(); ++it) {
        delete* it;
    }
}

void MapaSolucio::getPdis(std::vector<PuntDeInteresBase*>& pdis) {
    // Recorrer todos los puntos de interés almacenados en m_pdis
    for (auto it = m_pdis.begin(); it != m_pdis.end(); ++it) {
        PuntDeInteresBase* pdi = *it;
        pdis.push_back(pdi);

        // Escribir en el monitor el nombre y el color del punto de interés
        std::string logMessage = "PDI: " + pdi->getName() + ", Color: " + std::to_string(pdi->getColor());
        Util::escriuEnMonitor(logMessage);
    }
}

void MapaSolucio::parsejaXmlElements(std::vector<XmlElement>& xmlElements)
{
    for (auto itElem = xmlElements.begin(); itElem != xmlElements.end(); ++itElem) {
        const XmlElement& element = *itElem;

        if (element.id_element == "node") {
            // Parsear puntos de interés
            std::string id, name, shop, openingHours, wheelchair, cuisine;
            double lat = 0.0, lon = 0.0;

            for (auto itAtr = element.atributs.begin(); itAtr != element.atributs.end(); ++itAtr) {
                const auto& atribut = *itAtr;
                if (atribut.first == "id") id = atribut.second;
                else if (atribut.first == "lat") lat = std::stod(atribut.second);
                else if (atribut.first == "lon") lon = std::stod(atribut.second);
            }

            for (auto itFill = element.fills.begin(); itFill != element.fills.end(); ++itFill)
            {
                auto fill = *itFill;
                if (fill.first == "tag") {
                    auto tag = Util::kvDeTag(fill.second);
                    if (tag.first == "name") name = tag.second;
                    else if (tag.first == "shop") shop = tag.second;
                    else if (tag.first == "opening_hours") openingHours = tag.second;
                    else if (tag.first == "wheelchair") wheelchair = tag.second;
                    else if (tag.first == "cuisine") cuisine = tag.second;
                }
            }

            if (!name.empty()) {
                PuntDeInteresBase* punt = nullptr;

                // Crear instancias específicas según el tipo de punto de interés
                if (!shop.empty()) {
                    punt = new PuntDeInteresBotigaSolucio({ lat, lon }, name, shop, openingHours, wheelchair);
                }
                else if (!cuisine.empty()) {
                    punt = new PuntDeInteresRestaurantSolucio({ lat, lon }, name, cuisine, wheelchair);
                }
                else {
                    punt = new PuntDeInteresBase({ lat, lon }, name);
                }

                if (punt) {
                    m_pdis.push_back(punt);
                }
            }
        }
        else if (element.id_element == "way") {
            // Parsear caminos
            std::vector<Coordinate> coords;
            std::string highwayValue;

            for (auto itFill = element.fills.begin(); itFill != element.fills.end(); ++itFill) {
                auto fill = *itFill;

                if (fill.first == "nd") {
                    for (auto itRef = fill.second.begin(); itRef != fill.second.end(); ++itRef) {
                        auto ref = *itRef;
                        if (ref.first == "ref") {
                            coords.push_back({ 0.0, 0.0 }); // Placeholder para coordenadas
                        }
                    }
                }
                else if (fill.first == "tag") {
                    auto tag = Util::kvDeTag(fill.second);
                    if (tag.first == "highway") highwayValue = tag.second;
                }
            }

            if (!highwayValue.empty()) {
                auto cami = new CamiSolucio();
                cami->setCoords(coords);
                m_camins.push_back(cami);
            }
        }
    }
}
void MapaSolucio::getCamins(std::vector<CamiBase*>& camins) {
    // Recorrer todos los caminos almacenados en m_camins
    for (auto it = m_camins.begin(); it != m_camins.end(); ++it) {
        CamiBase* cami = *it;
        camins.push_back(cami);

        // Escribir en el monitor información sobre el camino
        std::string logMessage = "Camí amb " + std::to_string(cami->getCamiCoords().size()) + " coordenades.";
        Util::escriuEnMonitor(logMessage);
    }
}
