#pragma once
#include<string>

using namespace std;

class TipoPantalon {
public:
	virtual string toString() = 0;
	virtual double getDescuento() = 0;
};

