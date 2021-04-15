#include "Montagne.h"
#include <cmath>

double Montagne::altitude(double x, double y)
{

	double a = H * exp(-pow(x - centre.x, 2) / (2 * pow(etalement.x, 2)) - pow(y - centre.y, 2) / (2 * pow(etalement.y, 2)));
	if (a < 0.5) { a = 0; }

		return a;
}


Montagne::Montagne(double centre_x, double centre_y, double hauteur, double etalement_x, double etalement_y)
{
	centre.x = centre_x;
	centre.y = centre_y;
	H = hauteur;
	etalement.x = etalement_x;
	etalement.y = etalement_y;
}

Montagne::Montagne()
{
}
