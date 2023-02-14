#pragma once
#include "TipoPantalon.h"
#include <string>

using namespace std;

class PantalonNormal :public TipoPantalon{


public:
	static const double descuento;
	string toString();
	double getDescuento();
};

