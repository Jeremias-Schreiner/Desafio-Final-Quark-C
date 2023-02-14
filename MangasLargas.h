#pragma once
#include "MangasTipo.h"
class MangasLargas:public MangasTipo{
private:
	const static double descuento;
public:
	double getDescuento();
	string toString();
};

