#include <iostream>
#include <cmath>
#include "Montagne.h"
using namespace std;

double Montagne::altitude(double x, double y)  {
	double retour;
	retour = dist_2(x_0,x,sigma_x)+dist_2(y_0,y,sigma_y);
	retour=exp(retour);
	retour*=h;
	if (retour < 0.5){
		return 0;
	}
	else{
		return retour;
	}
}

double dist_2(double x_0,double x, double sigma_x){
	double retour;
	retour=-((x-x_0)*(x-x_0))/(2*sigma_x*sigma_x);
	return retour;
}
