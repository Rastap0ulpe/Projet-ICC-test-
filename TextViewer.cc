#include <iostream> // pour endl
#include "TextViewer.h"
#include "Montagne.h"
#include "Nuages.h"
using namespace std;
 
 
void TextViewer::dessine(Montagne const& M) 
{
	M.affiche();
}

void TextViewer::dessine(Systeme  const& system)
{
	system.affiche_ciel_system();
}
