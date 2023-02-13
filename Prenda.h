#pragma once
#include<string>

using namespace std;

class Prenda {
private:
	string* calidad;
	double precioUnitario;
	int cantidadStock;
public:
	Prenda(string* calidad, double precioUnitario, int cantidadStock);
	virtual double getPrenda() = 0;
	virtual ~Prenda();
};

