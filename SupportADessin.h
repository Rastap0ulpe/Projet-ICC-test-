#pragma once

class Montagne;

class Systeme;

class SupportADessin{
	public:
	 virtual ~SupportADessin() = default;
  // on suppose ici que les supports ne seront ni copiés ni déplacés
  SupportADessin(SupportADessin const&)            = delete; 
  SupportADessin& operator=(SupportADessin const&) = delete;
   // mais on peut les déplacer
  SupportADessin(SupportADessin&&)            = default; 
  SupportADessin& operator=(SupportADessin&&) = default;
  
  SupportADessin() = default; 
  virtual void dessine(Systeme const& a_dessiner) = 0;
  virtual void dessine(Montagne const& a_dessiner) = 0;

  
};
