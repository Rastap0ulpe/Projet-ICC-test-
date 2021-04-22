#pragma once
#include <cmath>

class Montagne{
	private:
	double x_0;
	double y_0;
	double H;
	double sigma_x;
	double sigma_y;
	public:
	Montagne(double x,double y,double h,double sigmax, double sigmay):x_0(x),y_0(y),H(h),sigma_x(sigmax),sigma_y(sigmay){};
	double altitude(double x, double y) const ;
};

