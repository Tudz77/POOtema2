#pragma once
#include "Vector.h"
class Matrice
{
protected:
	Vector* v;
	int linii;
public:
	Matrice();
	Matrice(int, int);
	~Matrice();
	virtual void citire() = 0;
	virtual void afisare() = 0;
};