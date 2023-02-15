#include<string>
#include "Cotizacion.h"
#include"Date.h"
#include"stdexcept"
#include <iostream>

using namespace std;

int Cotizacion::incremeto = 0;
vector<Cotizacion*> Cotizacion::cotizaciones = {};

Cotizacion::Cotizacion(Vendedor* vendedor, Prenda* prenda, int cantidadUnidades) {


	this->vendedor = vendedor;
	this->prenda = prenda;
	this->cantidadUnidades = cantidadUnidades;
	Date d;
	this->fecha = d.getCurrentDate();

	if (cantidadUnidades <= 0) {
		throw invalid_argument("Una cotizacion no puede tener valores Negativos ni 0!");
	}
	else if(cantidadUnidades > prenda->getCantidadStock()) {
		cout << "aca?" <<endl;
		throw invalid_argument("No hay suficientes productos en stock!");
	}

	this->calculo = prenda->getPrecio(cantidadUnidades);
	
	incremeto++;
	numeroCotizacion = incremeto;
	cotizaciones.push_back(this);
}

string Cotizacion::formateadorNumerico(int numero) {
	string numeroString = to_string(numero);
	if (numeroString.size() == 1) {
		numeroString = "00" + numeroString;
	}
	else if (numeroString.size() == 2) {
		numeroString = "0" + numeroString;
	}
	return numeroString;
}

string Cotizacion::toMonetaryString(double value) {
	string resultado = "";

	int valueInt = value;
	resultado = to_string(valueInt);

	int decimal = (value - valueInt) *100;
	 
	if (decimal < 10 && decimal > 0) {
		resultado += ".0" + to_string(decimal);
	}
	else if (decimal % 10 == 0 && decimal != 0) {
		resultado += '.' + to_string(decimal);
	}

	return resultado;
}

string Cotizacion::toString() {
	return "Número de identificación: " + formateadorNumerico(numeroCotizacion)+"\n"
		+"Fecha y hora de la cotización: "+fecha+"\n"
		+"Código del Vendedor: " + formateadorNumerico(vendedor->getCodigo()) + "\n"
		+"Prenda cotizada: "+prenda->toString() + "\n"
		+"Precio unitario: $"+ toMonetaryString(prenda->getPrecioUnitario())+"\n"
		+"Cantidad de unidades cotizadas: "+ to_string(cantidadUnidades)+'\n'
		+"Precio Final: $" + toMonetaryString(calculo);
}
