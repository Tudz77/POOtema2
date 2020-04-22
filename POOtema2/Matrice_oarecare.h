#pragma once
#include "Matrice.h"

class Matrice_oarecare : public Matrice
{
	int lin;
public:
	Matrice_oarecare();
	Matrice_oarecare(int, int);
	~Matrice_oarecare();
	Matrice_oarecare& operator=(const Matrice_oarecare&);
	friend std::istream& operator>>(std::istream&, Matrice_oarecare&);
	friend std::ostream& operator<<(std::ostream&, const Matrice_oarecare&);
	void citire();
	void afisare();
};