#pragma once
#include "Dessinable.h"


class Montagne: public Dessinable{
	public:
        int max_x=30;
        int max_y=30;
	virtual double altitude(double x, double y) const = 0 ;
	virtual void affiche_type() const =0;
	void affiche_altitude() const;
};
