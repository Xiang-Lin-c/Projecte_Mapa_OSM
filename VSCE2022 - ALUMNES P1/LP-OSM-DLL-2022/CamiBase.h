#pragma once
#include "pch.h"
#include "Common.h"
#include <vector>
using namespace std;
class CamiBase 
{
	public:
		virtual std::vector<Coordinate> getCamiCoords() = 0;
		virtual void afegirCoordenada(vector<Coordinate>& c) = 0;
		virtual string getTipus() = 0;
};

