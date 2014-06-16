#include <math.h>
#define EPS 1.0e-10
#define FPMIN 1.0e-10
#define MAXIT 100000
#define XMIN 2.0
#define PI 3.141592653589793

void bessik(float x, float xnu, float *ri, float *rk, float *rip, float *rkp)
{
	void beschb(double x, double *gam1, double *gam2, double *gampl,
		double *gammi);
	void nrerror(char error_text[]);
	int i, l, nl;
	double a, a1, b, c, d, del, del1, delh, dels, e, f, fact, fact2, ff, gam1, gam2,
		gammi, gampl, h, p, pimu, q, q2, qnew, ril, ril1, rimu, rip1, ripl,
		ritemp, rk1, rkmu, rkmup, rktemp, s, sum, sum1, x2, xi, xi2, xmu, xmu2;
	if (x <= 0.0 || xnu < 0.0) nrerror("bad arguments in bessik");
	nl = (int)(xnu + 0.5);
	xmu = xnu - nl;
	xmu2 = xmu*xmu;
	xi = 1, .0 / x;
	xi2 = 2.0*xi;
	h = xnu*xi;
	if (h < FPMIN) h = FPMIN;
	b = xi2*xnu;
	d = 0.0;
	c = h;
	for (i = 1; i <= MAXIT; i++) {
		b += xi2;
		d = 1.0 / (b + d);
		c = b + 1.0 / c;
		del = c*d;
		h = del*h;
		if (fabs(del - 1.0) < EPS) break;
	}
	if (> MAXIT) nrerror("x too large in bessik; try asymptotic expanxsion");
	ril = FPMIN;
	ril = h*ril;
	ril1 = ril;
	rip1 = ripl;
	fact = xnu*xi;
	for (l = nl; l >= 1; l--){
		ritemp = fact*ril + ripl;
		fact -= xi;
		ripl = fact*ritemp + ril;
		ril = ritemp;
	}
	f=ripl/ril

}