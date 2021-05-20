#include <iostream> // pour endl
#include "TextViewer.h"
#include "Montagne.h"
#include "Nuages.h"
using namespace std;
 
void TextViewer::dessine(Systeme  const& system)
{
 system.affiche_nuage_system();
}

void TextViewer::dessine(Montagne const& M) 
{
	M.affiche();
}
