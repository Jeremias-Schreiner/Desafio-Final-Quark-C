#pragma once
#include<string>
#include<stdlib.h>

#include "IView.h"
#include "Presentador.h"

using namespace std;

class ConsoleView : public IView {

private:
	string currentMenu;

	void menuPrincipal();
	void historialMenu();

	void cotizacionPrendaMenu();

	void cotizacionCamisa();
	void cotizacionCamisaCuello(string manga);
	void cotizacionCamisaCalidad(string manga, string cuello);
	void cotizacionCamisaPrecioUnitario(string manga, string cuello, string calidad);
	void cotizacionCamisaUnidades(string manga, string cuello,string calidad, double precioUnitario);

	void cotizacionPantalon();
	void cotizacionPantalonCalidad(string prendaNombre, string tipo);
	void cotizacionPantalonPrecioUnitario(string prendaNombre, string tipo, string calidad);
	void cotizacionUnidades(string prendaNombre, string tipo, string calidad, double precio);

	void cotizacionMenuFinal(string cotizacion);
	void errorMenu();

	void limpiarPantalla() const;
	string separador() const;
	string backButton() const;
	string cotizadorExpress() const;
	
	Presentador* presentador;

public:
	ConsoleView();
	void display();
	~ConsoleView();
};

