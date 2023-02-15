#include "Camisa.h"

double Camisa::getPrecio(int cantidad) {
	double precio = precioUnitario + precioUnitario * mangas->getDescuento();
	precio = precio + precio * cuello->getDescuento();

	if (calidad->compare("Premium") == 0) {
		precio = precio + precio * 0.3;
	}
	return precio * cantidad;
}

string Camisa::getTipoPrenda(){
	return "Camisa";
}

string Camisa::getMangas() const{
	return mangas->toString();
}

string Camisa::getCuello() const {
	return cuello->toString();
}

void Camisa::setTipoCuello(CuelloTipo* cuello) {
	this->cuello = cuello;
}

void Camisa::setTipoMangas(MangasTipo* mangas) {
	this->mangas = mangas;
}

string Camisa::toString() {
	return "Camisa - Mangas " + mangas->toString() + " - " + "Cuello " + cuello->toString() + " - "+ *this->calidad;
}

Camisa::~Camisa() {
	delete mangas;
	delete cuello;
}