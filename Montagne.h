#pragma once
#include "Dessinable.h"

class Montagne: public Dessinable{
	public:
	virtual double altitude(double x, double y) const = 0 ;
	
	virtual void montagne_affiche() const =0;
	void affiche() const;
};
