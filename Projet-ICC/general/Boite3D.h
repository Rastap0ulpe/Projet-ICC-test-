#pragma once

class Boite3D {
	protected:
	int N_x;
	int N_y;
	int N_z;
	double lambda;
	public:
    Boite3D()=default;
	Boite3D(int x,int y, int z, double l): N_x(x), N_y(y), N_z(z), lambda(l) { }
	unsigned int taille_x() const{
		return N_x;
	};
	unsigned int taille_y() const{
		return N_y;
		
	};
	unsigned int taille_z() const{
		return N_z;
	};
	double get_lambda() const{
		return lambda;
	}
};
