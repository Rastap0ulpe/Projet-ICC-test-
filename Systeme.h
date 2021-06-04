#pragma once
#include <cmath>
#include "Dessinable.h"
#include "SupportADessin.h"
#include "Montagne.h"
#include "ChampPotentiels.h"
#include "Nuages.h"
#include "constantes.h"
#include <memory>
#include "TextViewer.h"



class Systeme: public Dessinable {
	private:
	ChampPotentiels champ_p;
	Ciel ciel;
	std::unique_ptr<Montagne> M;
	
	public:
    Systeme(Montagne* m, int N_x, int N_y, int N_z, double lambda):champ_p(N_x,N_y,N_z,lambda), ciel(champ_p), M(m) {
		M ->max_x=N_x;
        M ->max_y=N_y;
		champ_p.initialise(const_sys::v_loin,*M);
		champ_p.calcule_laplacien(*M);
        champ_p.resolution(pow(lambda,4)*pow(10,-4),5000,*M);
	};
	
	Systeme(Systeme const&)=delete;
    ~Systeme(){
       M.release();
		
	}
	
	void deplacer_nuages(double delta_t);
	
    std::ostream& affiche(std::ostream& out) const;
	
    void evolue(SupportADessin& support,double dt = 0.031);
    
    void demarre(SupportADessin& support,double dt = 0.031);
    
	virtual void dessine_sur(SupportADessin& support) override {
		 support.dessine(*this); 
		 };
		 
	void affiche_ciel_system() const;
	
	unsigned int get_systeme_taille_x() const{
		return ciel.taille_x();
	};
	
	unsigned int get_systeme_taille_y() const{
		return ciel.taille_y();
	};
	
	unsigned int get_systeme_taille_z() const{
		return ciel.taille_z();
	};
	
	bool systeme_nuage(size_t i, size_t j, size_t k) const {
		return ciel.nuage(i,j,k);
    };
    
    std::vector<double> get_systeme_vitesse(size_t i, size_t j, size_t k) const{
		return ciel.get_vitesse_cube(i,j,k);
    };
    
    double get_systeme_norme(size_t i, size_t j, size_t k) const{
		return ciel.get_norme_cube(i,j,k);
    };
    
	bool systeme_pluie(size_t i, size_t j, size_t k) const {
        return ciel.pluie_GL(i,j,k);
	};
	
	void initialise_ciel(){
		Ciel c(champ_p);
		ciel=c;
		ciel.initialise_enthalpie();
	};
	
    void dessine_montagne(SupportADessin& support) const {
        M -> dessine_sur(support);
	};
	void affiche_pluie() const{
		ciel.qty_pluie();
	};
};


std::ostream& operator<<(std::ostream& out, Systeme const& s);
