#include<iostream>
#include "ConsoleView.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "");

	ConsoleView* view = new ConsoleView();
	view->display();

	//Implementar interfaz

	delete view;
	return 0;
}