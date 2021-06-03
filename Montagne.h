#pragma once
#include "Dessinable.h"


class Montagne: public Dessinable{
	public:
	virtual double altitude(double x, double y) const = 0 ;
	
	virtual void affiche_type() const =0;
	void affiche_altitude() const;
};
