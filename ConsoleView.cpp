#include "ConsoleView.h"
#include<iostream>

using namespace std;

ConsoleView::ConsoleView() {

	presentador = new Presentador();
	currentMenu = "Principal";
}

void ConsoleView::display() {

	if (currentMenu == "Principal") {
		menuPrincipal();
	}

}

void ConsoleView::menuPrincipal() {
	char input;

	cout << "COTIZADOR EXPRESS - MENÚ PRINCIPAL" << endl;
	cout << separador();
	cout << presentador->getTiendaInfo() << endl;
	cout << separador();
	cout << presentador->getVendedorInfo() << endl;
	cout << separador();
	cout << endl;
	cout << "SELECCIONE UNA OPCIÓN DEL MENÚ:" << endl << endl;
	cout << "1) Historial de Cotizaciones" << endl;
	cout << "2) Realizar Cotizaciones" << endl;
	cout << "3) Salir" << endl;
	cin >> input;
	cin.get();
	limpiarPantalla();
	if (input == '1') {
		historialMenu();
	}
	else if (input == '2') {
		cotizacionPrendaMenu();
	}
	else if (input == '3') {
		limpiarPantalla();
		cout << separador();
		cout << "¡Gracias por usar el sistema!" << endl;
		cout << separador();

	}
	else {
		limpiarPantalla();
		errorMenu();
	}
}

void ConsoleView::historialMenu(){
	char input;
	cout << backButton();
	cout << presentador->getCotizacionesHistorial() << endl;
	cout << backButton();
	cin >> input;
	if (input == '3') {
		limpiarPantalla();
		menuPrincipal();
	}
	else {
		limpiarPantalla();
		errorMenu();
	}
}

void ConsoleView::cotizacionPrendaMenu() {
	char input;
	cout << backButton();
	cout << "PASO 1: Seleccione la prenda a cotizar: " << endl;
	cout << "1) Camisa" << endl;
	cout << "2) Pantalón" << endl;
	cout << separador();
	cin >> input;
	cin.get();
	limpiarPantalla();
	if (input == '1') {

	}
	else if (input == '2') {
		cotizacionPantalon();
	}
	else if (input == '3') {
		menuPrincipal();
	}
	else {
		errorMenu();
	}
}

void ConsoleView::cotizacionPantalon() {
	char input;
	cout << cotizadorExpress() << endl;
	cout << backButton();
	cout << "PASO 2: El Panlón a cotizar, ¿Es Chupín?" << endl;
	cout << "1) Sí" << endl;
	cout << "2) No" << endl;
	cout << separador();
	cin >> input;
	limpiarPantalla();
	if (input == '1' || input == '2') {
		if (input == '1') {
			cotizacionPantalonCalidad("Pantalon", "Chupin");
		}
		else {
			cotizacionPantalonCalidad("Pantalon", "Normal");
		}
	}
	else if (input == '3') {
		menuPrincipal();
	}
	else {
		errorMenu();
	}
}

void ConsoleView::cotizacionPantalonCalidad(string prendaNombre, string tipo) {
	char input;
	cout << cotizadorExpress() << endl;
	cout << backButton();
	cout << "PASO 3: Seleccione la calidad de la prenda"<<endl;
	cout << "1)Standar" << endl;
	cout << "2)Premium" << endl;
	cin >> input;
	limpiarPantalla();
	if (input == '1' || input == '2') {
		cotizacionPantalonPrecioUnitario(prendaNombre, tipo, input == '1' ? "Standar" : "Premium");
	}
	else if(input == '3') {
		menuPrincipal();
	}
	else {
		errorMenu();
	}

}
void ConsoleView::cotizacionPantalonPrecioUnitario(string prendaNombre, string tipo, string calidad) {
	double input;
	cout << cotizadorExpress() << endl;
	cout << backButton();
	cout << "PASO 4: Ingrese el precio unitario de la prenda a cotizar" << endl;
	cout << separador();
	if (cin >> input) {
		limpiarPantalla();
		if (input >= 0) {
			if (input == 3) menuPrincipal();
			cotizacionUnidades(prendaNombre, tipo, calidad, input);
		}
		else {
			errorMenu();
		}
	}
	else {
		limpiarPantalla();
		cin.clear();
		cin.get();
		errorMenu();
	}
}

void ConsoleView::cotizacionUnidades(string prendaNombre, string tipo, string calidad, double precio) {
	int valor;
	cout << tipo << endl;
	cout << "Prenda nombre: " << prendaNombre << " Tipo: "<< tipo << " calidad: " << calidad << " Precio: " << precio << endl;

	cout << cotizadorExpress() << endl;
	cout << backButton() << endl;
	cout << "INFORMACIÓN:" << endl;
	cout << "EXISTE " << presentador->getStock(prendaNombre, tipo, calidad, precio, "") << " DE UNIDADES DE LA PRENDA SELECCIONADA" << endl << endl;
	cout << "PASO 5: Ingrese la cantidad de unidades a cotizar" <<endl;
	if (cin >> valor) {
		if (valor == 3) {
			limpiarPantalla();
			menuPrincipal();
		}
		else if (valor >0){
			limpiarPantalla();
			try {
				cotizacionMenuFinal(presentador->cotizar(valor));
			}
			catch (invalid_argument& e) {
				limpiarPantalla();
				cout << backButton() << endl;
				cout << e.what() << endl;
				cin >> valor;
				limpiarPantalla();
				menuPrincipal();
			}
		}
		else {
			errorMenu();
		}
	}
	else {
		cin.clear();
		limpiarPantalla();
		cin.get();
		errorMenu();
	}

}

void ConsoleView::cotizacionMenuFinal(string cotizacion) {
	char input;
	cout << cotizadorExpress() << endl;
	cout << backButton();
	cout << cotizacion << endl;
	cout << backButton();
	cin >> input;
	if (input == '3') {
		limpiarPantalla();
		menuPrincipal();
	}
	else {
		errorMenu();
	}
}

void ConsoleView::errorMenu() {
	char input;
	cout << backButton() << endl;
	cout << "¡Error, opcion incorrecta!" << endl;
	cin >> input;
	limpiarPantalla();
	if (input == '3') {
		menuPrincipal();
	}
	else {
		errorMenu();
	}
}

void ConsoleView::limpiarPantalla() const{
	system("cls");
}

string ConsoleView::separador() const{
	return "---------------------------------------------------------\n";
}

string ConsoleView::backButton() const {

	return separador() + "Presiona 3 para volver al menú principal\n" + separador();
}

string ConsoleView::cotizadorExpress() const{
	return "COTIZADOR EXPRESS -  COTIZAR";
}

ConsoleView::~ConsoleView() {
	delete presentador;
}