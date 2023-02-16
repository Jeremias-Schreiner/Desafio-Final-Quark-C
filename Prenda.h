#pragma once
#include<string>

using namespace std;

class Prenda {
protected:
	string* calidad;
	double precioUnitario;
	int cantidadStock;
public:
	Prenda(string* calidad, int cantidadStock);
	Prenda(string* calidad, int cantidadStock,double precioUnitario);
	virtual double getPrecio(int cantidad) = 0;
	virtual string toString() = 0;
	virtual string getTipoPrenda() = 0;
	virtual double getPrecioUnitario() {
		return precioUnitario;
	}
	virtual int getCantidadStock() {
		return cantidadStock;
	}
	virtual string getCalidad() {
		return *calidad;
	}
	virtual ~Prenda() {
		delete calidad;
	};
	void setPrecioUnitario(double precio) {
		this->precioUnitario = precio;
	}
};

