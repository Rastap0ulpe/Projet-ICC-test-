#include <iostream>
#include <cmath>
#include "Vecteur2D.h"
using namespace std;


void Vecteur2D::set_coord(double x,double y){
	x_=x;
	y_=y;
};
double Vecteur2D::get_x(){
	return x_;
}
double Vecteur2D::get_y(){
	return y_;
}


/*Vecteur2D Vecteur2D::addition(const Vecteur2D& autre) const{
	Vecteur2D retour;
	retour.x_=autre.x_+x_;
	retour.y_=autre.y_+y_;
	return retour;
	
};*/


/*Vecteur2D Vecteur2D::soustraction(const Vecteur2D& autre) const{
	
	return addition(autre.oppose());
};*/


Vecteur2D Vecteur2D::oppose() const
{
	Vecteur2D retour;
	retour.x_=-x_;
	retour.y_=-y_;
	return retour;
};

Vecteur2D Vecteur2D::mult(double k) const{
	Vecteur2D retour;
	retour.x_=k*x_;
	retour.y_=k*y_;
	return retour;
};


double Vecteur2D::prod_scal(const Vecteur2D& autre) const{
	return x_*autre.x_+ y_*autre.y_;	
};


double Vecteur2D::norme() const{
	return sqrt(norme2());
};


double Vecteur2D::norme2() const{
	return x_*x_+y_*y_;
};

/*Vecteur2D Vecteur2D::unitaire() const{
	Vecteur2D retour;
	if (norme()!= 0){
		retour.x_=x_/norme();
		retour.y_=y_/norme();
		return retour;
	}
	else{
		retour.x_=0;
		retour.y_=0;
		return retour;
	}
	
}*/
//operateurs
ostream& Vecteur2D::affiche(ostream& out) const{
	out<<x_<<" "<<y_;
	return out;
};

ostream& operator<<(ostream& out, Vecteur2D const& v){
	return v.affiche(out);
};

bool Vecteur2D::operator==(Vecteur2D const& autre) const{
	
	return ((abs(autre.x_-x_)<=1*pow(10,-10)) and (abs(autre.y_-y_)<=1*pow(10,-10)));
}
bool Vecteur2D::operator!=(Vecteur2D const& autre) const{
	return not(operator==(autre));
}

void Vecteur2D::operator+=(Vecteur2D const& autre) {
	x_+=autre.x_;
	y_+=autre.y_;
	
	
};

const Vecteur2D operator+(Vecteur2D v1,Vecteur2D const& v2){
	v1+=v2;
	return v1;
};

void Vecteur2D::operator-=(Vecteur2D const& autre) {
	*this+=autre.oppose();
};

const Vecteur2D operator-(Vecteur2D v1,Vecteur2D const& v2){
	v1+=v2.oppose();
	return v1;
};
/* ~ est operateur norme*/
Vecteur2D Vecteur2D::operator~() const{
	Vecteur2D retour;
	if (norme()!= 0){
		retour.x_=x_/norme();
		retour.y_=y_/norme();
		return retour;
	}
	else{
		return retour;
	}
	
}


/*bool Vecteur2D::compare(const Vecteur2D& v) const {
	return ((abs(v.x_-x_)<=1*pow(10,-10)) and (abs(v.y_-y_)<=1*pow(10,-10)));
};*/
