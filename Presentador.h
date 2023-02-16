#pragma once
#include"string";
#include"Tienda.h"
#include"Prenda.h"
#include"Camisa.h"
#include"Cotizacion.h"

class Presentador {
private:
	Tienda* tienda;
	void baseDeDatosVolatil();
	Prenda* prendaActual;

public:
	Presentador();

	string getTiendaInfo() const;
	string getVendedorInfo() const;
	string getCotizacionesHistorial() const;
	double getStock(string prendaNombre, string tipo, string calidad, double precio, string cuello);
	string cotizar(int unidades);

	~Presentador();

};

