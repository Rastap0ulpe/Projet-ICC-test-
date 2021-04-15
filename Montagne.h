#pragma once
class Montagne
{
private :

	struct point { 
		double x; 
		double y; 
	};

	point centre ;

	double H;

	point etalement;

public :

	double altitude(double x, double y);
		
	Montagne(double centre_x, double centre_y, double hauteur, double etalement_x, double etalement_y);

	Montagne();

};

