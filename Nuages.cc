#include <iostream>
#include "Nuages.h"
#include <vector>
using namespace std;


Ciel::Ciel(ChampPotentiels Champ_Potentiel):Boite3D(Champ_Potentiel.taille_x(),Champ_Potentiel.taille_y(),Champ_Potentiel.taille_z(),Champ_Potentiel.get_lambda()),air(N_x,vector<vector<CubedAir>>(N_y,vector<CubedAir>(N_z))){
	for(size_t i(0); i< N_x;++i){
		for(size_t j(0); j< N_y;++j){
			for(size_t k(0); k <N_z; ++k){
				air[i][j][k].set_vitesse(Champ_Potentiel.vitesse(i,j,k));
			}
		}
	}
			
};
Ciel::Ciel(int x,int y, int z, double l,double vent): Boite3D(x,y,z,l), air(N_x,vector<vector<CubedAir>>(N_y,vector<CubedAir>(N_z))){
	vector<double> v({vent,0,0});
	for(size_t i(0); i< N_x;++i){
		for(size_t j(0); j< N_y;++j){
			for(size_t k(0); k <N_z; ++k){
				air[i][j][k].set_vitesse(v);
			}
		}
	}
}


void Ciel::initialise_enthalpie(){
	double l(lambda);
	for(size_t i(0); i< N_x;++i){
		
		for(size_t j(0); j< N_y;++j){
			
			for(size_t k(0); k <N_z; ++k){
				air[i][j][k].set_enthalpie(k*l);
			
				
			}
		}
	}
}

void Ciel::affiche_nuage() const{
	for(size_t i(1); i< N_x-1;++i){
		
		for(size_t j(1); j< N_y-1;++j){
			
			for(size_t k(1); k <N_z-1; ++k){
				
				cout<<i<<" "<<j<<" "<<k<<" "<<air[i][j][k].norme2()<< " "<<air[i][j][k].get_enthalpie()<<" "<<air[i][j][k].temperature()<<" "<<air[i][j][k].pression()<<" "<<air[i][j][k].pression_eau()<< " "<< air[i][j][k].pression_rosee() << " "<< air[i][j][k].nuage()<<endl;
				
			}
		}
	}
	
}

vector<int> Ciel::precedente(double delta_t, int i,int j , int k) const{
	vector<int> deplacement({i,j,k});
	for (size_t n(0); n < 3; ++n){
		deplacement[n]= deplacement[n]+trunc((air[i][j][k].get_vitesse[n]*(-delta_t))/lambda);
	}
	
	if (deplacement[0] >= N_x or deplacement[0]<0 or deplacement[1] >= N_y or deplacement[1]<0 or deplacement[2] >= N_z or deplacement[2]<0){
		deplacement={0,0,0};
		return deplacement;
	}
	else{
		return deplacement;
	}
	
}

bool Ciel::nuage() const{
	return air[i][j][k].nuage();
}


void Ciel::reduit_taux_hum(int i, int j, int k){
	air.[i][j][k].reduit_taux_hum();
}
void Ciel::augmente_taux_hum(int i, int j, int k){
	air.[i][j][k].augmente_taux_hum();
}
void Ciel::Pluie(int i, int j, int k){
	if (air[i][j][k].pluie()){
		air[i][j][k].reduit_taux_hum(0.95);
		int n(0);
		for (size_t t(k) ; t >=0; --t){
			if(air[i][j][t].pluie){
				++n;
			}
		}
		cout<<"le quantite de pluie au sol est: "<<n<<endl;
	}
}
	
