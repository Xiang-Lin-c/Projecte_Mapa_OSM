#pragma once
#include "pch.h"

#if defined(_MSC_VER)  // Aquest arxiu només a WPF Gràfic (no a Caronte)

#include <vector>
#include <string>
#include <iostream>
#include "Common.h"

#include "MapaBase.h"
#include "XML4OSMUtil.h"


class MapaRender {
    private:
        MapaRender();
        static MapaRender* m_singleton;
        XML4OSMUtil* m_xml4osm_util;
        MapaBase* m_mapaBase;

    public:
        static MapaRender* instance();
        MapaRender(MapaRender&) = delete;
        void operator=(const MapaRender&) = delete;
        
        void construeixOSM(const std::string& path_map);

        std::vector<PoiBridge> renderPois();
        std::vector<WayBridge> renderWays();
};

#endif //defined(_MSC_VER)