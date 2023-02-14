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
	virtual ~Prenda() {
		delete calidad;
	};
};

