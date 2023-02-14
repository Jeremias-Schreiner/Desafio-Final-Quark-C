#pragma once
#include<string>
#include "Prenda.h"
#include "TipoPantalon.h"
class Pantalon: public Prenda{
private:
	TipoPantalon* tipo;

public:
	using Prenda::Prenda;

	virtual double getPrecio(int cantidad);
	void setTipo(TipoPantalon* tipo);

	string toString();

	~Pantalon();

};

