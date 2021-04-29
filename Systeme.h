#pragma once
#include "Dessinable.h"
#include "SupportADessin.h"
#include "Montagne.h"
#include "ChampPotentiels.h"
#include "Nuages.h"
#include "constantes.h"


class Systeme: public Dessinable {
	private:
	ChampPotentiels champ_p;
	Ciel ciel;
	Montagne M; //changer a un pointer ??
	public:
	Systeme(Montagne m, int N_x, int N_y, int N_z, double lambda):champ_p(N_x,N_y,N_z,lambda),M(m),ciel(champ_p) {
		champ_p.initialise(20,M);
		champ_p.calcule_laplacien(M);
	};
	std::ostream& affiche(std::ostream& out) const;
	void evolue();
	void demarre();
	virtual void dessine_sur(SupportADessin& support) override {
		 support.dessine(*this); 
		 }
};
std::ostream& operator<<(std::ostream& out, Systeme const& s);
