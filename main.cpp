#include<iostream>
#include<locale.h>
#include<iomanip>


#include "Tienda.h"	
#include "Vendedor.h"
#include "Prenda.h"
#include "Pantalon.h";
#include "PantalonNormal.h"
#include "Chupin.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "");
	Tienda* tienda = new Tienda(new string("Tu Ropa"), new string("San Martín 123"));
	Vendedor* vendedor = new Vendedor(new string("Jeremias"), new string("Schreiner"));

	cout << tienda->toString() << endl;
	cout << vendedor->toString() << endl;

	Pantalon* pantalon = new Pantalon(
		new string("Premium"), //"Calidad"
		10000, //Precio unitario
		800 // cantidad stock
	);
	
	pantalon->setTipo(new PantalonNormal());

	cout << pantalon->toString() << endl;
	cout << setprecision(17) << pantalon->getPrecio(800);



	delete pantalon;
	delete tienda;
	return 0;
}