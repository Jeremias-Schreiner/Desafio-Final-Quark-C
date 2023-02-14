#pragma once
#include<vector>
#include"Vendedor.h"
#include"Prenda.h"

using namespace std;

class Cotizacion {
private:
	static vector<Cotizacion*> cotizaciones;
	static int incremeto;

	int numeroCotizacion;
	//fecha
	Vendedor* vendedor;
	Prenda* prenda;
	int cantidadUnidades;
	double calculo;

	string formateadorNumerico(int numero);

public:

	Cotizacion(Vendedor* vendedor, Prenda* prenda, int cantidadUnidades);
	string toString();

	static vector<Cotizacion*> getCotizaciones() {
		return cotizaciones;
	}

	~Cotizacion();
};