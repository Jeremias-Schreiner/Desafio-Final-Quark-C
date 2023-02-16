#include "Presentador.h"
#include "MangaCorta.h"
#include "CuelloMao.h"
#include "CuelloComun.h"
#include "MangasLargas.h"
#include "Chupin.h"
#include "PantalonNormal.h"
#include <iostream>

Presentador::Presentador() {
	tienda = new Tienda(
		new string("Luxo"), 
		new string("Calle Siempre vivia 123"),
		new Vendedor(
			new string("Jeremaias"),
			new string("Schreiner")
		)
	);
	baseDeDatosVolatil();
}
 
void Presentador::baseDeDatosVolatil() {
	Camisa* camisa = new Camisa(new string("Premium"), 100);
	camisa->setTipoMangas(new MangaCorta());
	camisa->setTipoCuello(new CuelloMao());

	Prenda* p = camisa;
	tienda->addPrenda(p);

	camisa = new Camisa(new string("Standar"), 100);
	camisa->setTipoMangas(new MangaCorta());
	camisa->setTipoCuello(new CuelloMao());

	p = camisa;
	tienda->addPrenda(p);

	camisa = new Camisa(new string("Premium"), 150);
	camisa->setTipoMangas(new MangaCorta());
	camisa->setTipoCuello(new CuelloComun());

	p = camisa;
	tienda->addPrenda(p);

	camisa = new Camisa(new string("Standar"), 150);
	camisa->setTipoMangas(new MangaCorta());
	camisa->setTipoCuello(new CuelloComun());

	p = camisa;
	tienda->addPrenda(p);

	camisa = new Camisa(new string("Standar"), 75);
	camisa->setTipoMangas(new MangasLargas());
	camisa->setTipoCuello(new CuelloMao());

	p = camisa;
	tienda->addPrenda(p);

	camisa = new Camisa(new string("Premium"), 75);
	camisa->setTipoMangas(new MangasLargas());
	camisa->setTipoCuello(new CuelloMao());

	p = camisa;
	tienda->addPrenda(p);

	camisa = new Camisa(new string("Standar"), 175);
	camisa->setTipoMangas(new MangasLargas());
	camisa->setTipoCuello(new CuelloComun());

	p = camisa;
	tienda->addPrenda(p);

	camisa = new Camisa(new string("Premium"), 175);
	camisa->setTipoMangas(new MangasLargas());
	camisa->setTipoCuello(new CuelloComun());

	p = camisa;
	tienda->addPrenda(p);


	Pantalon* pantalon = new Pantalon(new string("Standar"), 750);
	pantalon->setTipo(new Chupin());

	p = pantalon;
	tienda->addPrenda(p);

	pantalon = new Pantalon(new string("Premium"), 750);
	pantalon->setTipo(new Chupin());

	p = pantalon;
	tienda->addPrenda(p);

	pantalon = new Pantalon(new string("Standar"), 250);
	pantalon->setTipo(new PantalonNormal());

	p = pantalon;
	tienda->addPrenda(p);

	pantalon = new Pantalon(new string("Premium"), 250);
	pantalon->setTipo(new PantalonNormal());

	p = pantalon;
	cout << p->getCalidad();
	tienda->addPrenda(p);
 
}

string Presentador::getTiendaInfo() const{
	return tienda->toString();
}

string Presentador::getVendedorInfo() const {
	return tienda->getVendedor()->toString();
}

string Presentador::getCotizacionesHistorial() const{
	string resultado = "";
	if (Cotizacion::getCotizaciones().empty()) {
		resultado = "NO SE ENCUENTRAN DISPONIBLES COTIZACIONES";
	}
	else {
		for (Cotizacion* c : Cotizacion::getCotizaciones()) {
			resultado += c->toString() +'\n'+'\n';
		}
	}

	return resultado;
}

double Presentador::getStock(string prendaNombre, string tipo, string calidad, double precio, string cuello) {
	if (prendaNombre.compare("Pantalon") == 0) {
		this->prendaActual = tienda->getPantalon(new string(tipo), new string(calidad));
	}
	else {
		//Mangas, cuello, calidad
		this->prendaActual = tienda->getCamisa(new string(tipo),new string(cuello), new string(calidad));
	}
	if (prendaActual == NULL) {
		return -1;
	}
	prendaActual->setPrecioUnitario(precio);
	return prendaActual->getCantidadStock();
}

string Presentador::cotizar(int unidades) {
	Cotizacion* c = new Cotizacion(tienda->getVendedor(), prendaActual, unidades);
	return c->toString();
}

Presentador::~Presentador() {
	Cotizacion::staticDestructor();
	delete tienda;
}