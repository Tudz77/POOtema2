#include "Matrice_patratica.h"

Matrice_patratica::Matrice_patratica()
	: Matrice() 
{
	dim = linii;
	citire();
}

Matrice_patratica::Matrice_patratica(int dim)
	: Matrice(dim, dim)
{
	this->dim = dim;
}


Matrice_patratica::~Matrice_patratica()
{
}

Matrice_patratica& Matrice_patratica::operator=(const Matrice_patratica& other)
{
	if (this->dim != other.dim) throw(dimensiuniDiferite());
	for (int i = 0; i < dim; i++)
	{
		v[i] = other.v[i];
	}
	return *this;
}

bool Matrice_patratica::diagonala() const
{
	bool sup = true, inf = true;
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (v[i].getElement(j) != 0) sup = false;
		}
	}
	for (int i = 0; i < dim; i++)
	{
		for (int j = i+1; j < dim; j++)
		{
			if (v[i].getElement(j) != 0) inf = false;
		}
	}

	if (!sup && !inf) throw(nonTriunghiulara());
	else if (sup && inf) return true;
	else return false;
}

int Matrice_patratica::determinant() const
{
	int matr[4][4];
	for (int i = 0; i < dim; i++)
		for (int j = 0; j < dim; j++)
			matr[i][j] = v[i].getElement(j);
	return calcDet(matr, dim);
}
int Matrice_patratica::calcDet(int matrix[4][4], int n) const
{
	int det = 0;
	int submatrix[4][4];

	if (n == 2)
		return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
	else {
		for (int x = 0; x < n; x++) {
			int subi = 0;
			for (int i = 1; i < n; i++) {
				int subj = 0;
				for (int j = 0; j < n; j++) {
					if (j == x)
						continue;
					submatrix[subi][subj] = matrix[i][j];
					subj++;
				}
				subi++;

			}
			det = det + (pow(-1, x) * matrix[0][x] * calcDet(submatrix, n - 1));
		}
	}
	return det;
}

std::istream& operator>>(std::istream& in, Matrice_patratica& mat)
{
	for (int i = 0; i < mat.dim; i++) { in >> mat.v[i]; }
	return in;
}

std::ostream& operator<<(std::ostream& out, const Matrice_patratica& mat)
{
	for (int i = 0; i < mat.dim; i++) { out << mat.v[i] << std::endl; }
	return out;
}

void Matrice_patratica::citire()
{
	for (int i = 0; i < linii; i++) { std::cin >> v[i]; }
}
void Matrice_patratica::afisare()
{
	std::cout << "Matricea Patratica este:\n";
	for (int i = 0; i < dim; i++) { std::cout << v[i] << std::endl; }
	std::cout << "cu determinantul: " << determinant() << std::endl; 
}