#include<iostream>
#include<locale.h>
#include<iomanip>
#include<ctime>


#include "Tienda.h"	
#include "Vendedor.h"
#include "Prenda.h"
#include "Pantalon.h";
#include "PantalonNormal.h"
#include "Chupin.h"
#include "MangaCorta.h"
#include "MangasLargas.h"
#include "CuelloMao.h"
#include "CuelloComun.h"
#include "Pantalon.h"
#include "Cotizacion.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "");
	
	//datos cargados previamente

	Tienda* tienda = new Tienda(
		new string("Luxo"),
		new string("calle siempre viva 123"),
		new Vendedor(
			new string("Ezequiel"), 
			new string("Martinez")
		)
	);

	Camisa* camisa = new Camisa(new string("Premium"), 10000, 100);
	camisa->setTipoMangas(new MangaCorta());
	camisa->setTipoCuello(new CuelloMao());

	Prenda* p = camisa;
	tienda->addPrenda(p);

	camisa = new Camisa(new string("Standar"), 10000, 100);
	camisa->setTipoMangas(new MangaCorta());
	camisa->setTipoCuello(new CuelloMao());
	
	p = camisa;
	tienda->addPrenda(p);

	camisa = new Camisa(new string("Premium"), 10000, 150);
	camisa->setTipoMangas(new MangaCorta());
	camisa->setTipoCuello(new CuelloComun());

	p = camisa;
	tienda->addPrenda(p);

	camisa = new Camisa(new string("Standar"), 10000, 150);
	camisa->setTipoMangas(new MangaCorta());
	camisa->setTipoCuello(new CuelloComun());

	p = camisa;
	tienda->addPrenda(p);

	camisa = new Camisa(new string("Standar"), 10000, 75);
	camisa->setTipoMangas(new MangasLargas());
	camisa->setTipoCuello(new CuelloMao());

	p = camisa;
	tienda->addPrenda(p);

	camisa = new Camisa(new string("Premium"), 10000, 75);
	camisa->setTipoMangas(new MangasLargas());
	camisa->setTipoCuello(new CuelloMao());

	p = camisa;
	tienda->addPrenda(p);

	camisa = new Camisa(new string("Standar"), 10000, 175);
	camisa->setTipoMangas(new MangasLargas());
	camisa->setTipoCuello(new CuelloComun());

	p = camisa;
	tienda->addPrenda(p);

	camisa = new Camisa(new string("Premium"), 10000, 175);
	camisa->setTipoMangas(new MangasLargas());
	camisa->setTipoCuello(new CuelloComun());

	p = camisa;
	tienda->addPrenda(p);


	Pantalon* pantalon = new Pantalon(new string("Standar"), 10000, 750);
	pantalon->setTipo(new Chupin());

	p = pantalon;
	tienda->addPrenda(p);

	pantalon = new Pantalon(new string("Premium"), 10000, 750);
	pantalon->setTipo(new Chupin());

	p = pantalon;
	tienda->addPrenda(p);

	pantalon = new Pantalon(new string("Standar"), 10000, 250);
	pantalon->setTipo(new PantalonNormal());

	p = pantalon;
	tienda->addPrenda(p);

	pantalon = new Pantalon(new string("Premium"), 10000, 250);
	pantalon->setTipo(new PantalonNormal());

	p = pantalon;
	tienda->addPrenda(p);

	//Fin de datos previamente cargados

	
	camisa = tienda->getCamisa(
		new string("Cortas"),
		new string("Mao"),
		new string("Premium")
	);

	pantalon = tienda->getPantalon(new string("Normal"), new string("Premium"));
	cout << pantalon << endl;
	cout << camisa->toString() << endl;
	cout << tienda->toString() << endl;
	cout << pantalon->toString() << endl;
	cout << endl;

	

	Cotizacion* cotizacion = new Cotizacion(tienda->getVendedor(), pantalon, 100);

	Cotizacion* cotizacion2 = new Cotizacion(tienda->getVendedor(), camisa, 24);



	cout << setprecision(2) << fixed<< cotizacion->toString() << endl;
	cout << endl;
	cout << cotizacion2->toString() << endl;

	delete tienda;

	return 0;
}