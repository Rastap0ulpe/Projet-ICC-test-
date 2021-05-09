#pragma once
#include "MontagneAbstrait.h"
#include <memory>
#include "Montagne.h"
#include <vector>

typedef std::vector<std::unique_ptr<MontagneAbstrait>> Chaine;
class ChaineMontagne : public MontagneAbstrait {
	private:
	Chaine composante;
	
	public:
	ChaineMontagne(std::vector<MontagneAbstrait*> montagnes);
	
	double altitude(double x, double y) const override ;
	void montagne_affiche() const override;
	void dessine_sur(SupportADessin& support) override {
		 support.dessine(*this); 
		 }
	
};
