#pragma once
#include<string>
#include<vector>

#include"Prenda.h"


using namespace std;

class Tienda{
private:
	string* nombre;
	string* direccion;
	vector<Prenda*> prendas;
public:
	Tienda(string* nombre, string* direccion);

	string* getNombre() const;
	string* getDireccion() const;
	vector<Prenda*> getPrendas() const;

	void setNombre(string* nombre);
	void setDireccion(string* direccion);
	void addPrenda(Prenda* prenda);

	string toString();

	~Tienda();
};

