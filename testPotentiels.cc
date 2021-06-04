#include <iostream>
#include <vector>
#include "Vecteur2D.h"
#include "Montagne.h"
#include "ChampPotentiels.h"
#include "MontagneSimple.h"
using namespace std;

int main(){
	double L(20.0/29.0);
	
	Montagne_simple M(15,15,15,5,5);
	ChampPotentiels CP(30,30,30,L);
	CP.initialise(20,M);
	CP.affiche_potentiel();
	return 0;
};
