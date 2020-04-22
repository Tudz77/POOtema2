#pragma once
#include "Matrice.h"

class Matrice_patratica : public Matrice
{
	int dim;
	int calcDet(int matr[4][4], int n) const;
	int determinant() const;
public:
	Matrice_patratica();
	Matrice_patratica(int);
	~Matrice_patratica();
	Matrice_patratica& operator=(const Matrice_patratica&);
	bool diagonala() const;
	friend std::istream& operator>>(std::istream&, Matrice_patratica&);
	friend std::ostream& operator<<(std::ostream&, const Matrice_patratica&);
	void citire();
	void afisare();
};