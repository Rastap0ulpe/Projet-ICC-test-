#include <iostream>
#include "Systeme.h"
#include "TextViewer.h"

using namespace std;

ostream& Systeme::affiche(ostream& out) const{
	out<<"une montagne"<<endl;
	out<<M.type()<<" de parametre :"<<endl;
	out<<"i0 = "<< M.get_i0()<<endl;
	out<<"i0 = "<< M.get_j0()<<endl;
	out<<"Si0 = "<< M.get_sig_i()<<endl;
	out<<"Sj0 = "<< M.get_sig_j()<<endl;
	out<<endl;
	out<< "un champ de potentiels :"<<endl;
	out<<"Nx ="<<champ_p.taille_x()<< " Ny ="<<champ_p.taille_y()<< " Nz="<<champ_p.taille_z()<<endl;
	out<<"Lambda ="<<champ_p.get_lambda()<<endl;
	out<<"valeurs: "<<endl;
	champ_p.affiche_potentiel();
	return out;
};

ostream& operator<<(ostream& out, Systeme const& s){
	return s.affiche(out);
};

void Systeme::evolue(){
	ciel.initialise_enthalpie();
	TextViewer text(cout);
	dessine_sur(text);
}


void Systeme::demarre(){
	TextViewer text(cout);
	champ_p.resolution(0.000022621843,3000,M);
	Ciel c(champ_p);
	ciel=c;
	ciel.initialise_enthalpie();
	dessine_sur(text);
	evolue();
	
	
}
