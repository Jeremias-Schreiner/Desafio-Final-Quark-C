#include "Pantalon.h"
#include<iostream>

using namespace std;

string Pantalon::getTipo() {
	return tipo->toString();
}

string Pantalon::getTipoPrenda() {
	return "Pantalon";
}

double Pantalon::getPrecio(int cantidad) {
	double precio = precioUnitario + precioUnitario * tipo->getDescuento();
	if ( calidad->compare("Premium") == 0) {
		precio = precio + precio * 0.3;
	}
	return precio * cantidad;
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