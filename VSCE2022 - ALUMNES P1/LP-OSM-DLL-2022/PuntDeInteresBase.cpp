#include "pch.h"
#include "PuntDeInteresBase.h"


PuntDeInteresBase::PuntDeInteresBase() {
	m_coord = Coordinate{ 0.0, 0.0 };
	m_name = "Hola";
}

PuntDeInteresBase::PuntDeInteresBase(Coordinate coord, std::string name) {
	m_name = name;
	m_coord = coord;
}

Coordinate PuntDeInteresBase::getCoord() {
	return m_coord;
}

std::string PuntDeInteresBase::getName() {
	return m_name;
}

unsigned int PuntDeInteresBase::getColor() {
	return 0xFFA500;
}


