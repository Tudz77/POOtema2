#include "Matrice_oarecare.h"

Matrice_oarecare::Matrice_oarecare()
	: Matrice() 
{
	citire();
}

Matrice_oarecare::Matrice_oarecare(int lin, int col)
	: Matrice(lin, col)
{
	this->lin = lin;
}

Matrice_oarecare::~Matrice_oarecare()
{
}

Matrice_oarecare& Matrice_oarecare::operator=(const Matrice_oarecare& other)
{
	if (this->lin != other.lin) throw(dimensiuniDiferite());
	for (int i = 0; i < other.lin; i++)
	{
		v[i] = other.v[i];
	}
	return *this;
}

std::istream& operator>>(std::istream& in, Matrice_oarecare& mat)
{
	for (int i = 0; i < mat.linii; i++) { in >> mat.v[i]; }
	return in;
}

std::ostream& operator<<(std::ostream& out, const Matrice_oarecare& mat)
{
	for (int i = 0; i < mat.linii; i++) { out << mat.v[i] << std::endl; }
	return out;
}

void Matrice_oarecare::citire()
{
	for (int i = 0; i < linii; i++) { std::cin >> v[i]; }
}
void Matrice_oarecare::afisare()
{
	std::cout << "Matricea Oarecare este:\n";
	for (int i = 0; i < linii; i++) { std::cout << v[i] << std::endl; }
}