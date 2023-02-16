#include "Vendedor.h"

int Vendedor::incremento = 0;

Vendedor::Vendedor(string* nombre, string* apellido) {
	incremento++;
	this->codigo = incremento;

	this->nombre = nombre;
	this->apellido = apellido;

}

int Vendedor::getCodigo() const{
	return codigo;
}

string* Vendedor::getNombre() const{
	return nombre;
}

string* Vendedor::getApellido() const{
	return apellido;
}

string Vendedor::toString() {
	return *this->nombre + " " + *this->apellido + " | " + to_string(codigo);
}

Vendedor::~Vendedor() {
	delete nombre;
	delete apellido;
}