#pragma once
class Montagne_simple;
class Contenu;
class ChaineMontagne;
class Systeme;
class ChampPotentiels;

class SupportADessin
{
public:
 virtual ~SupportADessin() = default;
 // on ne copie pas les Supports
 SupportADessin(SupportADessin const&)            = delete;
 SupportADessin& operator=(SupportADessin const&) = delete;
  // mais on peut les déplacer
 SupportADessin(SupportADessin&&)            = default;
 SupportADessin& operator=(SupportADessin&&) = default;

 SupportADessin() = default;

  virtual void dessine(Contenu const& a_dessiner) = 0;
  virtual void dessine(Montagne_simple const& a_dessiner)=0;
  virtual void dessine(ChaineMontagne const& a_dessiner)=0;
  virtual void dessine(Systeme const& a_dessiner)=0;
  virtual void dessine(ChampPotentiels const& a_dessiner)=0;

  /* Mettre ici toutes les méthodes nécessaires pour dessiner tous les
   * objets que l'on veut dessiner. Par exemple :
   *    virtual void dessine(Nounours const& a_dessiner) = 0;
   *    virtual void dessine(Voiture  const& a_dessiner) = 0;
   */
};
