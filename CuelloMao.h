#pragma once
#include "CuelloTipo.h"
class CuelloMao :public CuelloTipo{
private:
	const static double descuento;
public:
	double getDescuento();
	string toString();
};

