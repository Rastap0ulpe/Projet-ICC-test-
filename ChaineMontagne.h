#pragma once
#include <memory>
#include <vector>
#include "Montagne.h"
#include "MontagneSimple.h"

typedef std::vector<Montagne*> Chaine;
class ChaineMontagne : public Montagne {
	private:
	Chaine composante;
	
	public:
	ChaineMontagne(std::vector<Montagne*> montagnes);
	ChaineMontagne(ChaineMontagne const&)=delete;
	~ChaineMontagne(){
		for (auto m : composante){
		m=nullptr;
		delete m;
	}
	};
		
	
	
	double altitude(double x, double y) const override ;
	void affiche_type() const override;
	void dessine_sur(SupportADessin& support) override {
		 support.dessine(*this); 
		 }
	
};
