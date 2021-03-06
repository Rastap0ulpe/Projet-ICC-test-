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
                air[i][j][k].set_enthalpie(k);
				
			
				
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

vector<size_t> Ciel::precedente(size_t i,size_t j , size_t k, double delta_t /*=0.031*/ ) const{
    int d_i (i-trunc(((air[i][j][k].get_vitesse()[0]*delta_t/lambda))));

    int d_j(j-trunc(((air[i][j][k].get_vitesse()[1]*delta_t/lambda))));

    int d_k(k-trunc(((air[i][j][k].get_vitesse()[2]*delta_t/lambda))));

	
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
void Ciel::pluie(size_t i, size_t j, size_t k){
	if (air[i][j][k].pluie()){
		air[i][j][k].reduit_taux_hum(0.95);
		int n(0);
        for (int t(k) ; t >=0; --t){
			if(air[i][j][t].pluie()){
				++n;
			}
		}
		cout<<"le quantite de pluie au sol est: "<<n<<endl;
	}
}
	
void CubedAir::reset(){
    vitesse.resize(2);
}


void Ciel::reset(ChampPotentiels champ){
    N_x=champ.taille_x();
    N_y=champ.taille_y();
    N_z=champ.taille_z();
    lambda=champ.get_lambda();
    air.resize(N_x);
    for(int i=0; i<N_x; i++){
        air[i].resize(N_y);
        for(int j=0; j<N_y; j++){
            air[i][j].resize(N_z);
            for(int k=0;k<N_z;k++){
                //air[i][j][k].reset();
                air[i][j][k].set_vitesse(champ.vitesse(i,j,k));

                air[i][j][k].set_hum();

               // if(not (i==0 or i==29 or j==0 or j==29  or k==0 or k>19) ){air[i][j][k].set_enthalpie(k*lambda);}
                air[i][j][k].set_enthalpie(k*lambda);
            }
        }
    }

};
