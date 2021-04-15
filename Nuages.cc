#include <iostream>


Ciel::Ciel(const ChampPotentiels& Champ_Potentiel):Boite3D(Champ_Potentiel.taille_x(),Champ_Potentiel.taille_y(),Champ_Potentiel.taille_z(),Champ_Potentiel.get_lambda()),air(N_x,std::vector<std::vector<CubedAir>>(N_y,std::vector<CubedAir>(N_z))){
	for(size_t i(1); i< N_x-1;++i){
		for(size_t j(1); j< N_y-1;++j){
			for(size_t k(1); k <N_z-1; ++k){
				air[i][j][k].set_vitesse= Champ_Potentiel.vitesse(i,j,k);
			
};
Ciel::Ciel(int x,int y, int z, double l,double vent): Boite3D(x,y,z,l), air(N_x,std::vector<std::vector<CubedAir>>(N_y,std::vector<CubedAir>(N_z))){
	for(size_t i(1); i< N_x-1;++i){
		for(size_t j(1); j< N_y-1;++j){
			for(size_t k(1); k <N_z-1; ++k){
				vector<double> vitesse({vent,0,0});
				air[i][j][k].set_vitesse= vitesse;
}

