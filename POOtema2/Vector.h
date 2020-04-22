#pragma once
#include <iostream>
#include "exc.h"


class Vector
{
	int dim;
	int* a;
public:
	Vector();
	Vector(int dim);
	virtual ~Vector();
	int getElement(int) const;
	void setElement(int, int);
	Vector& operator=(const Vector&);
	friend std::istream& operator>>(std::istream&, Vector&);
	friend std::ostream& operator<<(std::ostream&, const Vector&);
};
