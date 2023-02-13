#include<iostream>
#include<locale.h>

#include "Tienda.h"	
using namespace std;

int main() {
	setlocale(LC_ALL, "");
	Tienda* tienda = new Tienda(new string("Tu Ropa"), new string("San Martín 123"));

	cout << tienda->toString() << endl;

	return 0;
}