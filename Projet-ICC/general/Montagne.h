#pragma once
#include "dessinable.h"


class Montagne: public Dessinable{
	public:
    Montagne()=default;
	virtual double altitude(double x, double y) const = 0 ;
	
	virtual void montagne_affiche() const =0;

    //virtual ~Montagne()=default;
};
