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
	std::vector<double> get_vitesse() const{
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
 
 void reduit_taux_hum(double c){
	 taux_hum *= 1-c;
 };
 
  void augmente_taux_hum(double c){
	 taux_hum *= 1+c;
 };
 
 bool pluie(){
	return pression_eau() - const_sys::P_ref > 100;
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
		std::vector<size_t> precedente(double delta_t, size_t i,size_t j , size_t k) const;
		bool nuage(size_t i, size_t j,size_t k) const;
		void reduit_taux_hum(size_t i, size_t j, size_t k, double c = 0.017);
		void augmente_taux_hum(size_t i, size_t j, size_t k, double c = 0.05) ;
		void pluie(size_t i, size_t j, size_t k);
		
};
