#pragma once
#include <cmath>
class Vecteur2D{
	private:
	//attributs
	double x_;
	double y_;
	
	public:
	//constructeur
	Vecteur2D(double x=0, double y=0):x_(x),y_(y){};
	double get_x();
	double get_y();
	void set_coord(double x,double y); 

	//method de class
	std::ostream& affiche(std::ostream& out) const;
	//bool compare(const Vecteur2D& autre) const; (remplacer par operateur ==)
	/*Vecteur2D addition(const Vecteur2D& autre) const; (remplacer par operateur +)*/
	//Vecteur2D soustraction(const Vecteur2D& autre) const; (remplacer par operateur -)
	Vecteur2D oppose() const;
	Vecteur2D mult(double k) const; /* multiplcation par scalaire*/
	double prod_scal(const Vecteur2D& autre) const;
	double norme() const;
	double norme2() const;
	/* Vecteur2D unitaire() const; */
	//operateur
	bool operator==(Vecteur2D const& autre) const;
	bool operator!=(Vecteur2D const& autre) const;
	void operator+=(Vecteur2D const& autre);
	void operator-=(Vecteur2D const& autre);
	/* ~ est operateur norme*/
	Vecteur2D operator~() const;

};

const Vecteur2D operator+(Vecteur2D v1,Vecteur2D const& v2);
const Vecteur2D operator-(Vecteur2D v1,Vecteur2D const& v2);
std::ostream& operator<<(std::ostream& out, Vecteur2D const& v);
