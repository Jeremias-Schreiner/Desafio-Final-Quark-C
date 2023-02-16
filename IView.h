#pragma once
#include<string>

using namespace std;

class IView{
private:
	string* currentMenu;
public:
	virtual void display() = 0;
};

