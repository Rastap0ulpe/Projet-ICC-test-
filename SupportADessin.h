#pragma once


class Systeme;

class SupportADessin{
	public:
	 virtual ~SupportADessin() = default;
  // on suppose ici que les supports ne seront ni copiés ni déplacés
  virtual void dessine(Systeme const& system) = 0;
 
  /*virtual void dessine(Montagne const& M) = 0;
	*/
};
