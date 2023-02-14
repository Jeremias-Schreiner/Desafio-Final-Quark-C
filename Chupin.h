#pragma once
#include "TipoPantalon.h"
#include<string>

using namespace std;

class Chupin: public TipoPantalon{
private:
	static const double descuento;
public:
	double getDescuento();
	string toString();
};

