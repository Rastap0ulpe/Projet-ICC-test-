#include <iostream> // pour endl
#include "TextViewer.h"
#include "Montagne.h"
#include "Nuages.h"
using namespace std;
 
 
void TextViewer::dessine(Montagne const& M) 
{
    M.affiche_type();
}

void TextViewer::dessine(Systeme  const& systeme)
{
	flot<<"quantite de pluie (i j quantite pluie):"<<endl;
	systeme.affiche_pluie();
	cout<<endl;
	flot<<"co-ordonee des nuages"<<endl;
	systeme.affiche_ciel_system();
	
    cout<<endl;
}
