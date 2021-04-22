#include <iostream>
#include <cmath>
#include "Montagne.h"
using namespace std;


double Montagne::altitude(double x, double y) const
{

	double a = H * exp(-pow(x - x_0, 2) / (2 * pow(sigma_x, 2)) - pow(y - y_0, 2) / (2 * pow(sigma_y, 2)));
	if (a < 0.5) { a = 0; }

		return a;
}

