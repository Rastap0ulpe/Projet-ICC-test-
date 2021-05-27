#include <iostream> // pour endl
#include "text_viewer.h"
#include "contenu.h"

void TextViewer::dessine(Contenu const& a_dessiner)
{
  flot << a_dessiner.infos() << std::endl;
}

void TextViewer::dessine(Montagne_simple const& a_dessiner){}
void TextViewer::dessine(ChaineMontagne const& a_dessiner){}
void TextViewer::dessine(Systeme const& a_dessiner){


}
void TextViewer::dessine(ChampPotentiels const& a_dessiner){}
