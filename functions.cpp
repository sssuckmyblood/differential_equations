#include "equation.h"

double F0(double x, double y)
{
	
	return -x - y + (y/x); // y'= -x-y+(y/x)
}

double F1(double x, double y)
{
	return (1. - (y * y))/(2.0 * x); // y'= (1-y^2)/(2*x)
}

double F2(double x, double y)
{
	return ((x * x) - 2.* y); // y'= x^2-2y
}

double F3(double x, double y)
{
	return (exp(-sin(x)) - (y * cos(x))); // y'= e^(-sin(x))-y*cos(x)
}

double F4(double x, double y)
{
	return -(((y * y) - y)/(x + 1.)); // y'= -((y^2-y)/(x+1))
}

double F5(double x, double y)
{
	return y/(-1. - x); // y'= y/(-1-x)
}

double F0_analytical(double x, double x0, double y0)
{					
	return (((((x0*exp(x0)+y0*exp(x0))/x0)*x)/exp(x)) - x); 

	       // y = ((C*x)/e^x) - x, C = (x0*e^x0 + y0*e^x0)/x0
}

double F1_analytical(double x, double x0, double y0)
{
	return ((x + ((x0 * y0 - x0)/(y0 + 1.)))/(x - ((x0 * y0 - x0) / (y0 + 1.)))); 

	       // y = (x + C)/(x - C), C = (x0*y0 - x0)/(y0 + 1)
}
double F2_analytical(double x, double x0, double y0)
{
	return ((((-(x0*x0)*exp(2.*x0) + x0*exp(2.*x0))/2. - exp(2.*x0)/4. + y0*exp(2*x0))/exp(2.*x)) + ((x*x)/2.) - x/2. + 1./4.);

		   // y = C/e^2*x + x^2/2 - x/2 + 1/4, C = (-x0^2*e^(2*x0) + x0*e^(2*x0))/2 - e^(2*x0)/4 + y0*e^(2*x0)
}

double F3_analytical(double x, double x0, double y0)
{
	return ((x + (-x0+exp(sin(x0))*y0))/exp(sin(x)));

			// y = (x + C)/e^sin(x), C = -x + e^sin(x)*y
}

double F4_analytical(double x, double x0, double y0)
{
	return ((x + 1.)/(x + ((x0 + 1. - (x0 *y0) - y0)/y0) + 1.)); 

	       // y = (x + 1)/x + C + 1, C = (x0 + 1 - x0*y0 - y0)/y0
}

double F5_analytical(double x, double x0, double y0)
{
	return ((x0*y0+y0)/(x+1));
	
			// y = C/(x + 1), C = x*y + y
}
