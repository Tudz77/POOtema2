#include "Matrice.h"

Matrice::Matrice()
{
	std::cout << "Lin: "; std::cin >> linii;
	std::cout << "Col: "; int col;  std::cin >> col;
	v = reinterpret_cast<Vector*>(new char[sizeof(Vector) * linii]);
	for (int i = 0; i < linii; i++)
	{
		new (v + i) Vector(col);
	}
}

Matrice::Matrice(int lin, int col)
{
	linii = lin;
	v = reinterpret_cast<Vector*>(new char[sizeof(Vector) * linii]);
	for (int i = 0; i < linii; i++)
	{
		new (v + i) Vector(col);
	}
}

Matrice::~Matrice()
{
	for(int i = 0; i < linii; i++)
		(v+i) -> ~Vector();
}
