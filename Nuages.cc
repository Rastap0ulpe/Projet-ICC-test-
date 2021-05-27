#include <iostream>
#include "Nuages.h"
#include <vector>
using namespace std;


Ciel::Ciel(ChampPotentiels Champ_Potentiel):Boite3D(Champ_Potentiel.taille_x(),Champ_Potentiel.taille_y(),Champ_Potentiel.taille_z(),Champ_Potentiel.get_lambda()),air(N_x,vector<vector<CubedAir>>(N_y,vector<CubedAir>(N_z))){
	for(size_t i(0); i< N_x;++i){
		for(size_t j(0); j< N_y;++j){
			for(size_t k(0); k <N_z; ++k){
				air[i][j][k].set_vitesse(Champ_Potentiel.vitesse(i,j,k));
				air[i][j][k].initialise_taux_hum();
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
				air[i][j][k].initialise_taux_hum();
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
				
				affiche_cube(i,j,k);
			}
		}
	}
	
}

vector<size_t> Ciel::precedente(size_t i,size_t j , size_t k, double delta_t /*=0.031*/ ) const{
	int d_i (i-trunc(((air[i][j][k].get_vitesse()[0]*delta_t)/lambda)));

	int d_j(j-trunc(((air[i][j][k].get_vitesse()[1]*delta_t)/lambda)));

	int d_k(k-trunc(((air[i][j][k].get_vitesse()[2]*delta_t)/lambda)));

	
	
	if (d_i >= N_x or d_i<0 or d_j >= N_y or d_j<0 or d_k >= N_z or d_k<0){

		return {55,55,55}; //code pour non nuageux
	}
	else{
		i=d_i;
		j=d_j;
		k=d_k;
			return {i,j,k};
		}
	}
	

bool Ciel::nuage(size_t i, size_t j,size_t k) const{
	return air[i][j][k].nuage();
}


void Ciel::reduit_taux_hum(size_t i, size_t j, size_t k, double c){
	air[i][j][k].reduit_taux_hum(c);
}
void Ciel::augmente_taux_hum(size_t i, size_t j, size_t k, double c){
	air[i][j][k].augmente_taux_hum(c);
}
void Ciel::pluie(){
	for(size_t i(1); i< N_x-1;++i){
		unsigned int n(0);
		size_t k_max(0);
		
		for(size_t j(1); j< N_y-1;++j){
			
			for(size_t k(1); k <N_z-1; ++k){
				if (air[i][j][k].pluie()){
					air[i][j][k].reduit_taux_hum();
					++n;
			}
		}
		if (n !=0){
		cout<<i<<" "<<j<<" la quantite de pluie au sol est: "<<n<<endl;
	}
	}
}
}
				
			
	


void Ciel::affiche_cube(size_t i, size_t j, size_t k) const{
	cout<<i<<" "<<j<<" "<<k<<" "<<air[i][j][k].norme2()<< " "<<air[i][j][k].get_enthalpie()<<" "<<air[i][j][k].temperature()<<" "<<air[i][j][k].pression()<<" "<<air[i][j][k].pression_eau()<< " "<< air[i][j][k].pression_rosee() << " "<< air[i][j][k].nuage()<<endl;
};

std::vector<double> Ciel::get_vitesse_cube(size_t i, size_t j,size_t k) const{
	return air[i][j][k].get_vitesse();
}

double Ciel::get_norme_cube(size_t i, size_t j,size_t k) const{
	return air[i][j][k].norme();
}
