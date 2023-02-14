#pragma once
#include<string>
using namespace std;

class Vendedor{
private:
	static int incremento;
	int codigo;
	string* nombre;
	string* apellido;
public:
	Vendedor(string* nombre, string* apellido);

	int getCodigo() const;
	string* getNombre() const;
	string* getApellido() const;

	string toString();

	~Vendedor();
};

