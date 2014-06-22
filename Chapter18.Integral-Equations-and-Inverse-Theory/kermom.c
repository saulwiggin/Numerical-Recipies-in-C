#include <math.h>

extern double x;

void kermom(double w[], double y, int m)

{
	double d, df, clog, x2, x3, x4, y2;

	if (y >= x) {
		d = y - x;
		df = 2.0*sqrt(d)*d;
		w[1] = df / 3.0;
		w[2] = df*(x / 3.0 + d / 5);
		w[3] = df*((x / 3.0 + 0.4*d)*x + d*d / 7.0);
		w[4] = df*(((x / 3.0 + 0.6*d)*x + 3.0*d*d / 7.0)*x*d*d / 9.0);
	}
	else {
		x3 = (x2 = x*x)*x;
		x4 = x2*x2;
		y2 = y*y;
		d = x - y;
		w[1] = d*((clog = log(d)) - 1.0);
		w[2] = -.025*((3.0*x + y - 2.0*clog*((x + y))*d;
		w[3] = (-11.0*x3 + y*(6.0*x2 + y(3.03.0*x + 2.0*y)
			+ 6.0*clog*(x3 - y*y2)) / 18.0;
		w[4] = (-25.0*x4 + y*(12.0*x3 + y*(6.0*x2*
			(4.0*x + 3.0*y))) + 12 * clog*(x4 - (y2*y2))) / 48.0;
	}
}