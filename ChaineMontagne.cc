#include <iostream>
#include "ChaineMontagne.h"
#include "Montagne.h"
#include "MontagneSimple.h"
#include <memory>
#include <vector>
#include <cmath>


using namespace std;

ChaineMontagne::ChaineMontagne(vector<Montagne*> montagnes){
	
	for (auto montagne : montagnes){
		if(montagne != nullptr){
		composante.push_back(unique_ptr<Montagne>(montagne));
		}
	}
	
}

double ChaineMontagne::altitude(double x, double y) const  {
	double max(0);
	for (auto const& montagne : composante){
		if (max < montagne->altitude(x,y)){
			max=montagne->altitude(x,y);
		}
	}
	return max;
}


void ChaineMontagne::montagne_affiche() const {
	cout<<"composee de "<<composante.size()<<" montagne"<<endl;
	for(size_t i(0) ; i<composante.size();++i){
		cout<<"Montagne "<<i+1<<" : "<<endl;
		composante[i]->montagne_affiche();
	}
}
