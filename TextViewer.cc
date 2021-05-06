#include <iostream> // pour endl
#include "TextViewer.h"
#include "Systeme.h"
using namespace std;
 
void TextViewer::dessine(Systeme  const& system)
{
 
  system.affiche_nuage_system();
}

//void TextViewer::dessine(Montagne const& M) (a voire comment faire)
