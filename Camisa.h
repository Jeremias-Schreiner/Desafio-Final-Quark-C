#pragma once
#include"Prenda.h"
#include "MangasTipo.h"
#include "CuelloTipo.h"
class Camisa:Prenda{
private:
	MangasTipo* mangas;
	CuelloTipo* cuello;
public:
	using Prenda::Prenda;

	virtual double getPrecio(int cantidad);
	virtual string getTipoPrenda() const;
	string getMangas() const;
	string getCuello() const;

	void setTipoMangas(MangasTipo* manga);
	void setTipoCuello(CuelloTipo* cuello);

	string toString();

	~Camisa();
};