#include <iostream>
#include "Systeme.h"
#include <memory>



using namespace std;

ostream& Systeme::affiche(ostream& out) const{
	out<<"une montagne"<<endl;
    M->montagne_affiche();
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

void Systeme::evolue(double delta_t){
    //ciel.initialise_enthalpie();
    deplacer_nuages(delta_t);
    //TextViewer text(cout);
    //dessine_sur(text);
}


void Systeme::demarre(){
    //TextViewer text(cout);
    champ_p.resolution(0.000022621843,3000,*M);
	Ciel c(champ_p);
	ciel=c;
	ciel.initialise_enthalpie();
	//dessine_sur(text);
    	//evolue();
	
	
}
void Systeme::deplacer_nuages(double delta_t /*=0.031 */){
    oui=not oui;
    Ciel ciel_nouveau(ciel);
    vector<size_t> non_nuage({55,55,55}); //code non nuageux et indice qui sort du boite
    for(size_t i(0); i< ciel.taille_x()-1;++i){
		
        for(size_t j(0); j< ciel.taille_y()-1;++j){
			
            for(size_t k(0); k <ciel.taille_z()-1; ++k){
				vector<size_t> C({i,j,k});
				vector<size_t> P(ciel.precedente(i,j,k,delta_t));

				if (P==non_nuage and ciel.nuage(C[0],C[1],C[2])){
						ciel_nouveau.reduit_taux_hum(C[0],C[1],C[2]);
				}
				else if (C!=P){
					if(ciel.nuage(C[0],C[1],C[2]) and not ciel.nuage(P[0],P[1],P[2]) ){
						ciel_nouveau.reduit_taux_hum(C[0],C[1],C[2]);
					}
					else if (not ciel.nuage(C[0],C[1],C[2]) and ciel.nuage(P[0],P[1],P[2]) ){
						ciel_nouveau.augmente_taux_hum(C[0],C[1],C[2]);
					}
				}
				
                ciel_nouveau.pluie(i,j,k);
			}
		}
	}
	ciel=ciel_nouveau;
	
}

void Systeme::initialise_systeme(Montagne* mont, int N_x, int N_y, int N_z, double lambda){

    champ_p.reset(N_x,N_y,N_z,lambda);

    M.reset(mont);
    champ_p.initialise(20,*M);
    champ_p.calcule_laplacien(*M);
    champ_p.resolution(0.000022621843,5000,*M);
    ciel.reset(champ_p);

}
