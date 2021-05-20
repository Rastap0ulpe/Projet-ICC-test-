#pragma once
#include <memory>
#include <vector>
#include "Montagne.h"
#include "MontagneSimple.h"

typedef std::vector<std::unique_ptr<Montagne>> Chaine;
class ChaineMontagne : public Montagne {
	private:
	Chaine composante;
	
	public:
	ChaineMontagne(std::vector<Montagne*> montagnes);
	
	double altitude(double x, double y) const override ;
	void montagne_affiche() const override;
	void dessine_sur(SupportADessin& support) override {
		 support.dessine(*this); 
		 }
	
};
