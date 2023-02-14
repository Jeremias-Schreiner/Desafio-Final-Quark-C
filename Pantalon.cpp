#include "Pantalon.h"
#include<iostream>

using namespace std;

double Pantalon::getPrecio(int cantidad) {
	
	if (cantidad <= cantidadStock) {
		double precio = precioUnitario + precioUnitario * tipo->getDescuento();
		if ( calidad->compare("Premium") == 0) {
			precio = precio + precio * 0.3;
			return precio * cantidad;
		}
		return precio * cantidad;
	}
	else {
		return 0;
	}
}

void Pantalon::setTipo(TipoPantalon* tipo) {
	this->tipo = tipo;
}

string Pantalon::toString() {
	return "Pantalon - " + tipo->toString() + " - " + *calidad;
}

Pantalon::~Pantalon() {
	delete tipo;
}