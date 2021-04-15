#pragma once
#include <array>
#include <iostream>
using namespace std;

class Vecteur2D
{


public:

	double x;

	double y;

	Vecteur2D();

	explicit Vecteur2D(double a, double b);

	Vecteur2D(const Vecteur2D &v2);

	void set_coord(int pos, double val);

	void affiche();

	bool compare(Vecteur2D v2, double precsision = 1e-10);

	Vecteur2D addition(Vecteur2D autre) const;

	Vecteur2D soustraction(Vecteur2D autre) const;

	Vecteur2D oppose() const;

	Vecteur2D mult(double a) const;

	double prod_scal(Vecteur2D autre) const;

	Vecteur2D unitaire() const;

	bool operator==(Vecteur2D v2);

	bool operator!=(Vecteur2D v2);

	Vecteur2D operator+=(Vecteur2D v2);

	Vecteur2D operator-=(Vecteur2D v2);


};

