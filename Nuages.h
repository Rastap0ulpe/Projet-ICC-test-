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
	std::vector<double> get_vitesse(){
		return vitesse;
	};
	double norme2() const{
		return vitesse[0]*vitesse[0]+vitesse[1]*vitesse[1]+vitesse[2]*vitesse[2];
	}
	double temperature() const{
		double t;
		t= enthalpie*(Physique::Mol_air/Physique::R)*(2.0/7.0);
		return t;
	}
	void set_enthalpie(double z){
		enthalpie=const_sys::cte - Physique::g *z -0.5*norme2();
	};
	double get_enthalpie() const{
		return enthalpie;
	};
	double pression() const{
		return const_sys::P_loin*pow(const_sys::T_loin,(-7.0/2.0))*pow(temperature(),7.0/2.0);
	};
	
	double pression_eau() const{
		return (const_sys::taux_hum)/((Physique::Mol_eau/Physique::Mol_air)+const_sys::taux_hum)*pression();
	};
	
	double pression_rosee() const{
	 return const_sys::P_ref*exp(13.96-5208.0/temperature());
 };
 bool nuage() const{
	 return pression_eau() > pression_rosee();
 };
 
 void reduit_taux_hum(unsigned double c){
	 taux_hum *= c;
 };
 
  void augmente_taux_hum(unsigned double c){
	 taux_hum *= c;
 };
 
 bool pluie(){
	return (pression_eau() - const_sys::P_ref) > 100)
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
		void affiche_nuage() const;
		std::vector<int> precedente(double delta_t, int i,int j , int k) const;
		bool nuage(int i, int j,int k) const;
		void reduit_taux_hum(int i, int j, int k, unsigned double c = 0.983);
		void augmente_taux_hum(int i, int j, int k, unsigned double c = 1.05) ;
		void pluie(int i, int j, int k);
		
};
