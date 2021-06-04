#include <iostream>
#include <vector>
#include "Vecteur2D.h"
#include "Montagne.h"
#include "ChampPotentiels.h"
#include "MontagneSimple.h"
#include <cmath>
using namespace std;

int main(){
	double a(20.0/29.0);
	double erreur(pow(a,4)*pow(10,-4));
	Montagne_simple M(15,15,15,5,5);
	ChampPotentiels CP(30,30,30,a);
	CP.initialise(20,M);
	CP.calcule_laplacien(M);
	CP.resolution(erreur,3000,M);
	CP.test_affiche();
	return 0;
};
