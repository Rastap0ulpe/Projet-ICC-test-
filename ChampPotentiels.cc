#include <iostream>
#include <cmath>
#include <vector>
#include "ChampPotentiels.h"
#include "Montagne.h"
#include "Vecteur2D.h"
using namespace std;


void ChampPotentiels::initialise(double v_loin, Montagne const& M ){
	Vecteur2D v_pot;
	Vecteur2D v_lap(0,0);
	for(size_t i(0); i< N_x;++i){

		for(size_t j(0); j< N_y;++j){
			double y_j(lambda*(j-((N_y-1)*0.5)));
			for(size_t k(0); k <N_z; ++k){
			double z_k(lambda*k);
			/* condition pour le bord*/
			if (j==0 or j==N_y-1 or i==0 or i == N_x-1){
				v_pot.set_coord(-v_loin*0.5*z_k,v_loin*0.5*y_j);
			}
			/* condition pour nullité du potentiel*/
			else if ( M.altitude(i,j) > k){
					v_pot.set_coord(0,0);
				}
				/* potentiel d'un point interieur*/
				else{
					v_pot.set_coord(-v_loin*0.5*z_k,v_loin*0.5*y_j);
				}
					champ_p[i][j][k].set_potentiel(v_pot);
			
					champ_p[i][j][k].set_laplacien(v_lap);
				}
				
				
				
			}
		}
	};
	
	
void ChampPotentiels::calcule_laplacien(Montagne const& M){
	Vecteur2D v(0,0);
	for(size_t i(1); i< N_x-1;++i){
		for(size_t j(1); j< N_y-1;++j){
			for(size_t k(1); k <N_z-1; ++k){
				if (M.altitude(i,j) > k){
					v.set_coord(0,0);
					champ_p[i][j][k].set_laplacien(v);
				}
				else{
				v=champ_p[i-1][j][k].get_potentiel() + champ_p[i][j-1][k].get_potentiel() + champ_p[i][j][k-1].get_potentiel() -(champ_p[i][j][k].get_potentiel().mult(6))+ champ_p[i+1][j][k].get_potentiel() + champ_p[i][j+1][k].get_potentiel() + champ_p[i][j][k+1].get_potentiel();
				champ_p[i][j][k].set_laplacien(v);
			}
				}
				
				
			}
		}
		
	};
	
void ChampPotentiels::affiche_potentiel() const{
	for(size_t i(0); i< N_x;++i){
		
		for(size_t j(0); j< N_y;++j){
			
			for(size_t k(0); k <N_z; ++k){
				cout<<i<<" "<<j<<" "<<k<<" ";
				cout<<champ_p[i][j][k].get_potentiel()<<endl;
			}
		}
	}
	
};

void ChampPotentiels::affiche_laplacien() const{
	for(size_t i(1); i< N_x-1;++i){
		
		for(size_t j(1); j< N_y-1;++j){
			
			for(size_t k(1); k <N_z-1; ++k){
				cout<<i<<" "<<j<<" "<<k<<" ";
				cout<<champ_p[i][j][k].get_laplacien()<<endl;
			}
		}
	}
	
};

double ChampPotentiels::erreur() const {
	double retour(0);
	Vecteur2D v;
	for(size_t i(1); i< N_x-1;++i){
		
		for(size_t j(1); j< N_y-1;++j){
			
			for(size_t k(1); k <N_z-1; ++k){
				retour+=champ_p[i][j][k].get_laplacien().norme2();
				
			}
		
		}
	}
	return retour;
};


void ChampPotentiels::iteration(){
	Vecteur2D v;
	for(size_t i(1); i< N_x-1;++i){
		
		for(size_t j(1); j< N_y-1;++j){
			
			for(size_t k(1); k <N_z-1; ++k){
			
				v = champ_p[i][j][k].get_potentiel() + champ_p[i][j][k].get_laplacien().mult(epsilon);
				champ_p[i][j][k].set_potentiel(v);
		
				
			}
		}
	}
};

 void ChampPotentiels::resolution(double error, unsigned int max, Montagne const& M , bool affiche /*= false*/)  {
	unsigned int i(1);
	while(this->erreur() > error and i < max){
	//cout<<i<<" "<<erreur()<<endl; 
	if (affiche){
		affiche_potentiel();
		affiche_laplacien();
	}
	if (erreur() > error){
	iteration();
	calcule_laplacien(M);
    }
	++i;
};
//cout<<i+1<<" "<<erreur()<<endl;



};

V_vent ChampPotentiels::vitesse(unsigned int i, unsigned int j, unsigned int k) const{ 
	V_vent V={20,0,0};
	if (i==0 or i == N_x-1 or j == 0 or j == N_y-1 or k==0 or k== N_z-1){
		return V;
	}
	
	double x,y,z;
	double c(0.5*(1/lambda));
	x = champ_p[i][j+1][k].get_potentiel().get_y() - champ_p[i][j-1][k].get_potentiel().get_y()-champ_p[i][j][k+1].get_potentiel().get_x() +champ_p[i][j][k-1].get_potentiel().get_x();
	y = -champ_p[i+1][j][k].get_potentiel().get_y() + champ_p[i-1][j][k].get_potentiel().get_y();
	z= champ_p[i+1][j][k].get_potentiel().get_x()-champ_p[i-1][j][k].get_potentiel().get_x();
	V[0]=c*x;
	V[1]=c*y;
	V[2]=c*z;
	return V;
};

void ChampPotentiels::affiche_vitesse(V_vent vent_vit) const{
	cout<<vent_vit[0]<<" "<<vent_vit[1]<<" "<<vent_vit[2];
};

double ChampPotentiels::V2(V_vent vent_vit) const{
	double retour;
	retour= vent_vit[0]*vent_vit[0] + vent_vit[1]*vent_vit[1] + vent_vit[2]*vent_vit[2];
	return retour;
	
};

void ChampPotentiels::test_affiche() const{
	for(size_t i(0); i< N_x;++i){
		
		for(size_t j(0); j< N_y;++j){
			
			for(size_t k(0); k <N_z; ++k){
				cout<<i<<" "<<j<<" "<<k<<" ";
				cout<<champ_p[i][j][k].get_potentiel()<<" ";
				affiche_vitesse(vitesse(i,j,k));
				cout<<" "<<V2(vitesse(i,j,k))<<endl;
			}
		}
	}
};

