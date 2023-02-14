#pragma once
#include "MangasTipo.h"

class MangaCorta: public MangasTipo{
private:
	const static double descuento;
public:
	double getDescuento();
	string toString();
};

