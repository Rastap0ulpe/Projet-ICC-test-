#pragma once
#include <vector>
#include <cmath>
#include "Vecteur2D.h"
#include "Boite3D.h"
#include "Montagne.h"


class Potentiel{
	private:
	Vecteur2D potentiel;
	Vecteur2D laplacien;
	public:
	void set_potentiel(Vecteur2D v){
	potentiel = v;
	};
	void set_laplacien(Vecteur2D v){
	laplacien=v;
	};
	
	Vecteur2D get_potentiel() const{
		return potentiel;
	};	
	Vecteur2D get_laplacien() const{
		return laplacien;
	};
	
	
};

typedef std::vector<std::vector<std::vector<Potentiel> > > champ_potentiel;
typedef std::vector<double> V_vent;

class ChampPotentiels : public Boite3D{
	private:
	champ_potentiel champ_p;
	void iteration();
	public:
	ChampPotentiels(int x,int y, int z, double l): Boite3D(x,y,z,l), champ_p(N_x,std::vector<std::vector<Potentiel>>(N_y,std::vector<Potentiel>(N_z))){};
	void initialise(double v_loin,Montagne const& M );
	void calcule_laplacien(Montagne const& M);
	void affiche_potentiel() const;
	void affiche_laplacien() const;
	double erreur() const;
	void resolution(double error, unsigned int max, Montagne const& M , bool affiche=false); 
	V_vent vitesse(unsigned int i, unsigned int j, unsigned int k) const;
	void affiche_vitesse(V_vent vent_vit) const;
	double V2(V_vent vent_vit) const;
	void test_affiche() const;

	
};
