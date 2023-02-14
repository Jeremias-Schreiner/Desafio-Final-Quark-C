#pragma once
#include<string>

using namespace std;

class MangasTipo{
public:
	virtual double getDescuento() = 0;
	virtual string toString() = 0;
};

