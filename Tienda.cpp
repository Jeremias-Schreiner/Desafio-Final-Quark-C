#include "Tienda.h"
Tienda::Tienda(string* nombre, string* direccion) {
	this->nombre = nombre;
	this->direccion = direccion;
	this->prendas = {};
}

//getters

string* Tienda:: getNombre() const{
	return this->nombre;
}

string* Tienda::getDireccion() const{
	return this->direccion;
}

vector<Prenda*> Tienda::getPrendas() const{
	return this->prendas;
}

//setters

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

}