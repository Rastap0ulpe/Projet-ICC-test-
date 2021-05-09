#pragma once
#include <cmath>
#include "Montagne.h"
#include "SupportADessin.h"
class Montagne_simple: public Montagne{
	private:
	double i_0;
	double j_0;
	double H;
	double sigma_i;
	double sigma_j;
	public:
	Montagne_simple(int x,int y,double h,double sigmax, double sigmay):i_0(x),j_0(y),H(h),sigma_i(sigmax),sigma_j(sigmay) {};
	double altitude(double x, double y) const override ;

	void montagne_affiche() const override;
	void dessine_sur(SupportADessin& support) override {
		 support.dessine(*this); 
		 }
};

