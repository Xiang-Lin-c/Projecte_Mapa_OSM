#pragma once
#include "pch.h"

#if defined(_MSC_VER)  // Aquest arxiu només a WPF Gràfic (no a Caronte)

#include <xercesc/dom/DOM.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>

#include <string>
#include <vector>
#include "Common.h"

class XML4OSMUtil {

public:
    XML4OSMUtil();
    ~XML4OSMUtil();

    std::vector<XmlElement> parseXML(const char* file);

private:
    xercesc::XercesDOMParser* m_parser;
    xercesc::DOMDocument* m_xmlDoc;
};

#endif //defined(_MSC_VER)