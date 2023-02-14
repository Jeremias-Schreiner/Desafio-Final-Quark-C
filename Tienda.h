#pragma once
#include<string>
#include<vector>

//#include"Prenda.h"
#include"Vendedor.h"
#include "Camisa.h"
#include "Pantalon.h"


using namespace std;

class Tienda{
private:
	string* nombre;
	string* direccion;
	vector<Prenda*> prendas;
	Vendedor* vendedor;
public:
	Tienda(string* nombre, string* direccion, Vendedor* vendedor);

	string* getNombre() const;
	string* getDireccion() const;
	Camisa* getCamisa(string* mangas, string* cuello) const;
	Pantalon* getPantalon(string* tipo) const;

	void setNombre(string* nombre);
	void setDireccion(string* direccion);
	void addPrenda(Prenda* prenda);

	string toString();

	~Tienda();
};

