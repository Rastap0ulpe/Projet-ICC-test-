#include <iostream>
#include <vector>
#include "Vecteur2D.h"
#include "Montagne.h"
#include "ChampPotentiels.h"
using namespace std;

int main(){
	double a(20.0/29.0);
	
	Montagne M(15,15,15,5,5);
	ChampPotentiels CP(30,30,30,a);
	CP.initialise(20,M);
	//CP.affiche_potentiel();
	CP.calcule_laplacien();
	CP.affiche_laplacien();
	return 0;
};
