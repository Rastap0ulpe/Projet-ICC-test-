#include <iostream>
#include "Systeme.h"
#include "TextViewer.h"
#include <memory>
#include "ChampPotentiels.h"

using namespace std;

ostream& Systeme::affiche(ostream& out) const{
	out<<"une montagne"<<endl;
	M -> montagne_affiche();
	out<< "un champ de potentiels :"<<endl;
	out<<"Nx ="<<champ_p.taille_x()<< " Ny ="<<champ_p.taille_y()<< " Nz="<<champ_p.taille_z()<<endl;
	out<<"Lambda ="<<champ_p.get_lambda()<<endl;
	out<<"valeurs: "<<endl;
	champ_p.affiche_potentiel();
	return out;
};

ostream& operator<<(ostream& out, Systeme const& s){
	return s.affiche(out);
};

void Systeme::evolue(){
	ciel.initialise_enthalpie();
	deplacer_nuages();
	TextViewer text(cout);
	dessine_sur(text);
}


void Systeme::demarre(){
	TextViewer text(cout);
	champ_p.resolution(0.000022621843,3000,*M);
	Ciel c(champ_p);
	ciel=c;
	ciel.initialise_enthalpie();
	dessine_sur(text);
	evolue();
	
	
}
void Systeme::deplacer_nuages(double delta_t /*=0.031 */){
	for(size_t i(1); i< 29;++i){ //changer 29 a N_x avec une method get_Nx
		
		for(size_t j(1); j< 29;++j){
			
			for(size_t k(1); k <29; ++k){
				vector<size_t> C({i,j,k});
				vector<size_t> P(ciel.precedente(delta_t,i,j,k));
				if (C!=P){
					if(ciel.nuage(C[0],C[1],C[2]) and not ciel.nuage(P[0],P[1],P[2]) ){
						ciel.reduit_taux_hum(C[0],C[1],C[2]);
					}
					if (not ciel.nuage(C[0],C[1],C[2]) and ciel.nuage(P[0],P[1],P[2]) ){
						ciel.augmente_taux_hum(C[0],C[1],C[2]);
					}
				}
				
				ciel.pluie(i,j,k);
			}
		}
	}
	
}
