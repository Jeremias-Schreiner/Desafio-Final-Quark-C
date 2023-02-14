#pragma once
#include<string>

using namespace std;

class Prenda {
protected:
	string* calidad;
	double precioUnitario;
	int cantidadStock;
public:
	Prenda(string* calidad, double precioUnitario, int cantidadStock);
	virtual double getPrecio(int cantidad) = 0;
	virtual string toString() = 0;
	virtual string getTipoPrenda() = 0;
	virtual double getPrecioUnitario() {
		return precioUnitario;
	}
	virtual ~Prenda() {
		delete calidad;
	};
};

