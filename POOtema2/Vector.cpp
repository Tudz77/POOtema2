#include "Vector.h"

Vector::Vector()
{
	std::cout << "Size: "; std::cin >> dim;
	a = new int[dim];
	std::cout << "Input: ";
	for (int i = 0; i < dim; i++)
	{
		std::cin >> a[i];
	}
}
Vector::Vector(int dim)
{
	this->dim = dim;
	a = new int[dim];
}

Vector::~Vector()
{
	delete[] a;
}

int Vector::getElement(int pos) const { return a[pos]; }
void Vector::setElement(int pos, int elem) { a[pos] = elem; }

Vector& Vector::operator=(const Vector& other)
{
	if (this->dim != other.dim) throw(dimensiuniDiferite());
	dim = other.dim;
	a = new int[dim];
	for (int i = 0; i < dim; i++)
	{
		a[i] = other.a[i];
	}
	return *this;
}

std::istream& operator>>(std::istream& in, Vector& v)
{
	for (int i = 0; i < v.dim; i++) { in >> v.a[i]; }
	return in;
}

std::ostream& operator<<(std::ostream & out, const Vector & v)
{
	for (int i = 0; i < v.dim; i++)
	{
		out << v.a[i] << " ";
	}
	return out;
}