#pragma once

class Vecteur3D{
	private:
	double x;
	double y;
	double z;
	
	public:
	
	Vecteur3D(double x_=0,double y_=0,double z_=0): x(x_),y(y_),z(z_){};
	
	void affiche(){
		std::cout<<x<<" "<<y<<" "<<z;
	};
	double norme(){
		return sqrt(x*x+y*y+z*z);
	};
	double norme_2(){
		return norme()*norme();
	};
	void set_cord(double x_,double y_,double z_){
		x=x_;
		y=y_;
		z=z_;
	};
	
};
