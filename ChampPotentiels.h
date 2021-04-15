#pragma once
#include <vector>
#include "Potentiel.h"
#include "Montagne.h"
#include <cmath>
#include "Vecteur3D.h"
class ChampPotentiels
{

private:

	
	

public:

	double lamda;

	double L_x;

	double L_y;

	double L_z;

	int N_x;

	int N_y;

	int N_z;

	vector<vector<vector<Potentiel>>> boite;

	double v_infty;

	Montagne Mont;

	ChampPotentiels(double lx, double ly, double lz, double pas_echantillonage);

	void initialise(double v_inf, Montagne& const M );

	void calcule_laplacien();

	void affiche_potentiel(int i, int j, int k);

	void affiche_laplacien(int i, int j, int k);

	double erreur();

	void iteration(double e = 0.1);

	void resolution(double precision, int max_iteration, bool verbeuse = false);

	Vecteur3D vitesse(int i, int j, int k);

};

