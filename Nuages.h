#pragma once
#include <vector>
#include <cmath>
#include "Vecteur2D.h"
#include "Montagne.h"
#include "constantes.h"
#include "ChampPotentiels.h"


class CubedAir{
	private:
	std::vector<double> vitesse;
	double taux_hum;
	double enthalpie;
	public:
	void set_hum(double t){
		taux_hum=t;
	};
	std::vector<double> set_vitesse(std::vector<double> v){
		vitesse=v;
	};
	
	double norme2(){
		return vitesse[0]*vitesse[0]+vitesse[1]*vitesse[1]+vitesse[2]*vitesse[2];
	}
	double temperature(){
		double t;
		t= enthalpie*(Physique::Mol_air/Physique::R)*(2.0/7.0);
		return t;
	}
	void set_enthalpie(double z){
		enthalpie=const_sys::cte - Physique::g *z -0.5*norme2();
	};
	double get_enthalpie(){
		return enthalpie;
	};
	double pression(){
		return const_sys::P_loin*pow(const_sys::T_loin,(-7.0/2.0))*pow(temperature(),7.0/2.0);
	};
	
	double pression_eau(){
		return (const_sys::taux_hum)/((Physique::Mol_eau/Physique::Mol_air)+const_sys::taux_hum)*pression();
	};
	
	double pression_rosee(){
	 return const_sys::P_ref*exp(13.96-5208.0/temperature());
 };
 bool nuage(){
	 return pression_eau() > pression_rosee();
 };
	
};

typedef std::vector<std::vector<std::vector<CubedAir> > > tableau_air;

class Ciel : public Boite3D{
	private:
	tableau_air air;
	public:
		Ciel(ChampPotentiels Champ_Potentiel);
		Ciel(int x,int y, int z, double l,double vent);
		void initialise_enthalpie();
		void affiche_nuage();
		void affiche_vitesse();
};
