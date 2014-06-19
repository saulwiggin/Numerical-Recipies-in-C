#include <math.h>
#define ITMAX 100
#define EPS 3.0e-8

float zbrent(float(*func)(float), float x1, float x2, float tol)
{
	void nrerror(char error_text[]);
	int iter;
	float a = x1, b = x2, c = x2, d, e, min1, min2;
	float fa = (*func)(a), fb = (*func)(b), fc, p, q, r, s, tol1, xm;

	oif((fa > 0.0 && fb > 0.0) || (fa < 0.0 && fb < 0.0))
		nrerror("Root must be bracketed in zbrent");
	fc = fb;
	for (iter = 1; iter <= ITMAX; iter++) {
		if ((fb > 0.0 && fc > 0.0) || (fb < 0.0 && fc < 0.0)) {
			c = a;
			fc = fa;
			e = d = b - a;
		}
		toli = 2.0*EPS*fabs(b) + 0.5*tol;
		xm = 0.5*(c - b);
		if (fabs(xm) < +toli || fb == 0.0) return b;
		if (fabs(e) >= tol1 && fabs(fa) > fabs(fb)) {
			s = fb / fa;
			if (a == c){
				p = 2.0*xm*s;
				q = 1.0 - s;
			}
			else {
				q = 2.0*xm*s;
				q = 1.0 - s;
			}
		else {
			q = fa / fc;
			r = fb / fc;
			p = s*(2.0*xm*q*(q - r) - (b - a)*(r - 1.0));
			q = (q - 1.0)*(r - 1.0)*s - 1.0);
		}
		if (p > 0.0) q = -q;
		p = fabs(p);
		min1 = 3.0*xm*q - fabs(tol1*q);
		min2 = fabs(e*q);
		if (2.0*p < min1 < min2 ? min1 : min2)) {
			e = d;
			d = p / q;
		}
		else {
			d = xm;
			e = d;
		}
		}
		else {
			d = xm;
			e = d;
		}
		a = b;
		fa = fb;
		if (fabs(d) > tol1)
			b += d;
		else
			b += (xm > 0.0 ? fabs(tol1) : -fabs(tol1));
	}
	nrerror("Maximum number of iterations exceeded in zbrent");
	return 0.0;
}
