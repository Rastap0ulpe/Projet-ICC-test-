#include <iostream>
#include "Nuages.h"
#include "Montagne.h"
#include "MontagneSimple.h"
#include "ChampPotentiels.h"
#include "constantes.h"
using namespace std;



int main(){
	double a(20.0/29.0);
	double erreur(pow(a,4)*pow(10,-4)); 
	Montagne_simple M(15,15,15,5,5);
	ChampPotentiels champ_p(30,30,30,a);
	champ_p.initialise(20,M);
	champ_p.calcule_laplacien(M);
	champ_p.resolution(erreur,3000,M);
	Ciel ciel(champ_p);
	
	ciel.initialise_enthalpie();
	ciel.affiche_nuage();

	
	return 0;
}
