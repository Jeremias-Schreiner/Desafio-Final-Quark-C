#pragma once
#include<string>
#include "Prenda.h"
#include "TipoPantalon.h"
class Pantalon: public Prenda{
private:
	TipoPantalon* tipo;

public:
	using Prenda::Prenda;

	string getTipo();

	virtual string getTipoPrenda();
	virtual double getPrecio(int cantidad);
	void setTipo(TipoPantalon* tipo);

	virtual string toString();

	~Pantalon();

};

