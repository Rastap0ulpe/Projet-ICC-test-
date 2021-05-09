#include <iostream>
#include <cmath>
#include "MontagneSimple.h"
#include "Montagne.h"
using namespace std;


double Montagne_simple::altitude(double x, double y) const 
{

	double a = H * exp(-pow(x - i_0, 2) / (2 * pow(sigma_i, 2)) - pow(y - j_0, 2) / (2 * pow(sigma_j, 2)));
	if (a < 0.5) { a = 0; }

		return a;
}

void  Montagne_simple::montagne_affiche() const {

	cout<<"gaussienne de parametre :"<<endl;
	cout<<"i0 = "<< i_0<<endl;
	cout<<"i0 = "<<j_0<<endl;
	cout<<"Si0 = "<< sigma_i<<endl;
	cout<<"Sj0 = "<< sigma_j<<endl;
	cout<<endl;
}
