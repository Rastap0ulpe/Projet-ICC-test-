#pragma once

class Boite3D {
	protected:
	unsigned int N_x;
	unsigned int N_y;
	unsigned int N_z;
	double lambda;
	public:
	Boite3D(unsigned int x, unsigned int y, unsigned int z, double l): N_x(x), N_y(y), N_z(z), lambda(l) { }
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
