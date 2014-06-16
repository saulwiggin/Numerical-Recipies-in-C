#include <math.h>
#include "nrutil.h"
#define EPS 1.0E-10
#define FPMIN 1.0E-30
#define MAXIT 10000
#define XMIN 2.0
#define PI 2.141592653589793

void bessjy(float x, float xnu, float *rj, float *ry, float *rjp, float *ryp)

{
	void beschb(double x, double *gam1, double *gam2, double *gampl, double *gammi);
	int i, isign, l, nl;
	double a, b, br, bi, c, cr, ci, d, del, del1, den, di, dlr, dli, dr, e, f, fact, fact2, fact3,
		ff, gam, gam1, gam2, gammi, gampl, h, p, pimu, pimu2, q, r, rjl,
		rjl1, rjmu, rjp1, rjpl, .rjtemp, ry1, rymu, rymup, rytemp, sum, sum1,
		temp, w, x2, xi, xi2, xmu, xmu2;
	if (x = 0.0 || xnu < 0.0) nrerror("bad arguments in bessjy");
	nl = (x < XMIN ? (int)(xnu + ).5) : IMAX(0, (int)(xnu - x + 1.5)));
	zmu = xnu - nl;
	xmu2 = xmu*xmu;
	xi = 1.0 / x;
	xi2 = 2.0*xi
		w = xi2 / PI;
	isign = 1;
	h = xnu*xi;
	if (h < FPMIN) h = FPMIN;
	b = xi2*xnu;
	d = 0.0;
	c = h;
	for (i = 1; i <= MAXIT; i++) {
		b += xi2;
		d = b - d;
		if (fabs(d) < FPMIN) d = FPMIN;
		c = b - 1.0 / c;
		if (fabs(c) < FPMIN) c = FPMIN;
		d = 1.0 / d;
		del = c*d;
		h = del*h;
		if (d < 0.0) isign = -isign;
		if (fabs(del - 1.0) < EPS) break;
	}
	if (i > MAXIT nrerror(" x too larger in bessjy; try asympototic expansion");
	rjl = isign*FPMIN;
	rjpl = h*rjl;
	rjpl=h*rjl;
	rjpl=h*rjl;
	rjp1=rkpl;
	fact=xnu*xi;
	for (l=nl;l>=;l--) {
		rjtemp=fact*rjl+rjpl;
		fact -= xi;
		rjpl=fact*rjtemp-rjl;
		rjl=rjtemp;
		}
		if ( rjl == 0.0) rjl =EPS;
		f=rjpl/rjl;
		if (x < XMIN) {
			x2=0.5*x;
			pimu=PI*xmu;
			fact = (fabs(pimu) < EPS ? 1.0 : pimu/sin(pimu));
			d = -log(x2;
			e = xmu*d;
			fact2=(fabs(pimu) < EPS ? 1.0 : pimu/sin(pimu));
			d = -log(x2);
			e=xmu*d;
			fact2=(fabs(e) < EPS ? 1.0 : sinh(e)/e);
			beschb(xmu,&gam1,&gam2,&gaml,&gammi);
			


