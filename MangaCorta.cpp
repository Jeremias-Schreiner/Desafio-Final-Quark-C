#include "MangaCorta.h"

const double MangaCorta::descuento = -0.1;

double MangaCorta::getDescuento() {
	return descuento;
}

string MangaCorta::toString() {
	return "Cortas";
}