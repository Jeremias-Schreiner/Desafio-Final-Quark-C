#include "Cotizacion.h"
#include<string>

using namespace std;

int Cotizacion::incremeto=0;

string Cotizacion::formateadorNumerico(int numero) {
	string numeroString = to_string(numero);
	if (numeroString.size() == 1) {
		numeroString = "00" + numero;
	}
	else if (numeroString.size() == 2) {
		numeroString = "0" + numeroString;
	}
	return numeroString;
}

Cotizacion::Cotizacion(Vendedor* vendedor, Prenda* prenda, int cantidadUnidades) {
	incremeto++;

	numeroCotizacion = incremeto;

	this->vendedor = vendedor;
	this->prenda = prenda;
	this->cantidadUnidades = cantidadUnidades;

	this->calculo = prenda->getPrecio(cantidadUnidades);

	cotizaciones.push_back(this);
}

string Cotizacion::toString() {
	return "Número de identificación: " + formateadorNumerico(numeroCotizacion)+"\n"
		+"Fecha y hora de la cotización: 18/01/2022 15:30"+"\n"
		+"Código del Vendedor: " + formateadorNumerico(vendedor->getCodigo()) + "\n"
		+"Prenda cotizada: "+prenda->toString() + "\n"
		+"Precio unitario: $"+to_string(prenda->getPrecioUnitario())+"\n"
		+"Cantidad de unidades cotizadas: "+ to_string(cantidadUnidades)+'\n'
		+"Precio Final: $" + to_string(calculo);
}


Cotizacion::~Cotizacion() {
	for (Cotizacion* c : cotizaciones) {
		delete c;
	}
}