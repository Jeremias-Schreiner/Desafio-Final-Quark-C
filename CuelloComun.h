#pragma once
#include "CuelloTipo.h"
class CuelloComun: public CuelloTipo{
private:
	const static double descuento;
public:
	double getDescuento();
	string toString();
};

