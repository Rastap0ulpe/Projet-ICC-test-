#pragma once
#include "Dessinable.h"
#include "SupportADessin.h"
#include "Montagne.h"
#include "ChampPotentiels.h"
#include "Nuages.h"
#include "constantes.h"
#include <memory>


class Systeme: public Dessinable {
	private:
	ChampPotentiels champ_p;
	Ciel ciel;
	unique_ptr<MontagneAbstrait> M;
	public:
	Systeme(MontagneAbstrait* m, int N_x, int N_y, int N_z, double lambda):champ_p(N_x,N_y,N_z,lambda),M(m),ciel(champ_p) {
		champ_p.initialise(20,M);
		champ_p.calcule_laplacien(M);
	};
	void deplacer_nuages(delta_t = 0.031);
	std::ostream& affiche(std::ostream& out) const;
	void evolue();
	void demarre();
	virtual void dessine_sur(SupportADessin& support) override {
		 support.dessine(*this); 
		 }
};
std::ostream& operator<<(std::ostream& out, Systeme const& s);
