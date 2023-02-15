#include "Tienda.h"
#include<iostream>

using namespace std;

Tienda::Tienda(string* nombre, string* direccion, Vendedor* vendedor) {
	this->nombre = nombre;
	this->direccion = direccion;
	this->prendas = {};
	this->vendedor = vendedor;
}

//getters

string* Tienda:: getNombre() const{
	return this->nombre;
}

string* Tienda::getDireccion() const{
	return this->direccion;
}

Camisa* Tienda::getCamisa(string* mangas, string* cuello, string* calidad) const{
	for (Prenda* prenda : prendas) {
		if (prenda->getTipoPrenda().compare("Camisa") == 0) {
			Camisa* camisa = (Camisa*)prenda;
			cout << camisa->toString() << endl;
			if (mangas->compare(camisa->getMangas()) == 0) {
				if (cuello->compare(camisa->getCuello()) == 0){
					if (calidad->compare(camisa->getCaliad()) == 0) {
						delete mangas;
						delete cuello;
						delete calidad;
						return camisa;
					}
				}
			}
		}
	}
	delete mangas;
	delete cuello;
	return NULL;
}

Pantalon* Tienda::getPantalon(string* tipo, string* calidad) const {
	for (Prenda* prenda : prendas) {

		if (prenda->getTipoPrenda().compare("Pantalon") == 0) {
			Pantalon* pantalon = (Pantalon*)prenda;
			if (tipo->compare(pantalon->getTipo()) == 0) {
				if (calidad->compare(pantalon->getCaliad()) == 0) {
					delete tipo;
					delete calidad;
					return pantalon;
				}
			}
		}

	}
	delete tipo;
	delete calidad;
	return NULL;
}

//setters

Vendedor* Tienda::getVendedor() const{
	return vendedor;
}

void Tienda::setNombre(string* nombre) {
	this->nombre = nombre;
}

void Tienda::setDireccion(string* direccion) {
	this->direccion = direccion;
}

void Tienda::addPrenda(Prenda* prenda) {
	this->prendas.push_back(prenda);
}


string Tienda::toString() {

	

	return *this->nombre + " | " + *this->direccion;
}


Tienda::~Tienda() {

	delete this->nombre;
	delete this->direccion;

	for (Prenda* prenda : prendas) {
		delete prenda;
	}
	delete vendedor;
}