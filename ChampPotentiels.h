#pragma once
#include <vector>
#include <cmath>
#include "Vecteur2D.h"
#include "Montagne.h"
#include "Boite3D.h"
constexpr double epsilon(0.1);
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
	
	Vecteur2D get_potentiel(){
		return potentiel;
	};	
	Vecteur2D get_laplacien(){
		return laplacien;
	};
	
	
};

typedef std::vector<std::vector<std::vector<Potentiel> > > champ_potentiel;
typedef std::vector<double> V_vent;

class ChampPotentiels : public Boite3D{
	private:
	champ_potentiel champ_p;
	public:
	ChampPotentiels(int x,int y, int z, double l): Boite3D(x,y,z,l), champ_p(N_x,std::vector<std::vector<Potentiel>>(N_y,std::vector<Potentiel>(N_z))){};
	void initialise(double v_loin,Montagne M );
	void calcule_laplacien(Montagne M);
	void affiche_potentiel();
	void affiche_laplacien();
	double erreur() ;
	void iteration();
	void resolution(double error, unsigned int max, Montagne M , bool affiche=false); 
	V_vent vitesse(unsigned int i, unsigned int j, unsigned int k);
	void affiche_vitesse(V_vent vent_vit);
	double V2(V_vent vent_vit);
	//void test_affiche();

	
};
