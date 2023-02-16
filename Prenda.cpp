#include "Prenda.h"

Prenda::Prenda(string* calidad, int cantidadStock) {
	this->calidad = calidad;
	this->cantidadStock = cantidadStock;
}

Prenda::Prenda(string* calidad, int cantidadStock, double precioUnitario = 0) {
	this->calidad = calidad;
	this->precioUnitario = precioUnitario;
	this->cantidadStock = cantidadStock;
}