#pragma once
#include <vector>
#include <cmath>
#include "Vecteur2D.h"
#include "Montagne.h"
#include "constates.h"
#include ""


class CubedAir{
	private:
	vector<double> vitesse;
	double enthalpie;
	double température;
	double pression;
	double pression_vap_eau;
	double taux_hum;
	bool etat;
	public:
	double set_vitesse(v){
		vitesse=v;
	};
	double enthalpie(double z){
		return (cte-physique::g*z-0.5*v2(v))
	};
	double v2(vector<double> v){
		return v[0]*v[0] + v[1]*v[1] + v[2]*v[2];
	};
	double T(double h){
		return (2/7)*(physique::Mol_air/physique::R)*h
	}
	double pression(double T);
	
	
};

typedef std::vector<std::vector<std::vector<CubedAir> > > tableau_air;

class Ciel : public Boite3D{
	private:
	tableau_air air;
	public:
		Ciel(const ChampPotentiels& Champ_Potentiel);
		Ciel(int x,int y, int z, double l,double vent): Boite3D(x,y,z,l), air(N_x,std::vector<std::vector<CubedAir>>(N_y,std::vector<CubedAir>(N_z)));
};
