#pragma once
#include"Prenda.h"
#include "MangasTipo.h"
#include "CuelloTipo.h"
class Camisa:public Prenda{
private:
	MangasTipo* mangas;
	CuelloTipo* cuello;
public:
	using Prenda::Prenda;

	virtual double getPrecio(int cantidad);
	virtual string getTipoPrenda();
	string getMangas() const;
	string getCuello() const;

	void setTipoMangas(MangasTipo* manga);
	void setTipoCuello(CuelloTipo* cuello);

	virtual string toString();

	~Camisa();
};