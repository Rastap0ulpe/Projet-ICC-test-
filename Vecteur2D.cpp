#include "Vecteur2D.h"
#include <cmath>
Vecteur2D::Vecteur2D()
{
	x = 0;
	y = 0;
}
 Vecteur2D::Vecteur2D(double a, double b)
{
	x = a;
	y = b;
}
Vecteur2D::Vecteur2D(const Vecteur2D& v2)
{
	x = v2.x;
	y = v2.y;
}
void Vecteur2D::set_coord(int pos, double val)
{
	if (pos == 0) { x = val; }
	if (pos == 1) { y = val; }

}

void Vecteur2D::affiche()
{

	cout << "(" << x << " " << y << ")";

}

bool Vecteur2D::compare(Vecteur2D v2, double precsision)
{
	if (pow(pow((x - v2.x), 2) + pow(x - v2.x, 2), 0.5) < precsision) { return true; }
	else { return false; }
}

Vecteur2D Vecteur2D::addition(Vecteur2D autre) const
{
	Vecteur2D add;

	add.x = x + autre.x;
	add.y = y + autre.y;

	return add;
}

Vecteur2D Vecteur2D::soustraction(Vecteur2D autre) const
{
	Vecteur2D sus;

	sus.x = x - autre.x;
	sus.y = y - autre.y;

	return sus;
}

Vecteur2D Vecteur2D::oppose() const
{
	Vecteur2D opp;

	opp.x = -x ;
	opp.y = -y ;

	return opp;
}

Vecteur2D Vecteur2D::mult(double a) const
{
	Vecteur2D mult;

	mult.x = a*x ;
	mult.y = a*y ;

	return mult;
}

double Vecteur2D::prod_scal(Vecteur2D autre) const
{
	return x*autre.x+y*autre.y;
}

Vecteur2D Vecteur2D::unitaire() const
{
	Vecteur2D unit;

	double norme = sqrt(x * x + y * y);

	unit.x = x / norme;
	unit.y = y / norme;

	return unit;
}

bool Vecteur2D::operator==(Vecteur2D v2)
{

	double precsision(1e-10);

	if (abs(x - v2.x) < precsision and abs(y - v2.y) < precsision) { return true; }

	return false;
}

bool Vecteur2D::operator!=(Vecteur2D v2)
{

	double precsision(1e-10);

	if (abs(x - v2.x) < precsision and abs(y - v2.y) < precsision) { return false; }

	return true;
}

Vecteur2D Vecteur2D::operator+=(Vecteur2D v2)
{
	x += v2.x;
	y += v2.y;
	
	return *this;
}

Vecteur2D Vecteur2D::operator-=(Vecteur2D v2)
{
	x -= v2.x;
	y -= v2.y;
	
	return *this;
}


