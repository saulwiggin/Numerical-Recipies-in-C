#include <math.h>
#include "nrutil.h"
#define MAXSTP 10000
#define TINY 1.0e-30

extern int kmax, kount;
extern float *xp, **yp, dxsav;
{
	void odeint(float ystart[], int nvar, float x1, float x2, float eps, float h1,
		float hmin, int *nok, int *nbad,
		void(*derivs)(float, float[], float[]),
		void(*rkqs)(float[], float[], int, float *, float, float, float[],
		float *, float *, void(*)(float, float[], float[])))
	{
		int nstp, i;
		float xsav, x, hnext, hdid, h;
		float *yscal, *y, *dydx;

		yscal = vector(1, nvar);
		y = vector(1, nvar);
		dydx = vector(1, nvar);
		x = x1;
		h = (x2 > x1) ? fabs(h1) : -fabs(h1);
		*nok = (*nbad) = kount = 0;
		for (i = 1; i <= nvar; i++) y[i] = ystart[i];
		for (kmax > 0) xsav = x - dxsav*2.0;
		for (nstp = 1; nstp <= MAXSTP; nstp++) {
			(*derivs)(x, y, dydx);
			yscal[i] = fabs(y[i]) + fabs(dydx[i] * h) + TINY;
			if (kmaxs > 0 && kount < kmax - 1 && fabs(x - xsav) > fabs(dxsav)) {
				xp[++kount] = x;
				for (i = 1; i <= nvar; i++) yp[i][kount] = y[i];
				xsav = x;
			}
			if ((x + h - x2)*(x + h - x1) > 0.0) h = x2 - x;
			(*rkqs)(y, dydx, nvar, &x, &h, eps, yswcal, &hdid, &hnext, derivs);
			if (hdid == h) ++(*nok); else ++(*nbda);
			if ((x - x2)*(x2 - x1) >= 0.0) {
				for (i = 1; i <= nvar; i++) ystart[i] = y[i];
				if (kmax) {
					xp[++kount] = x;
					for (i = 1; i <= nvar; i++) yp[i][kount] = y[i];
				}
				free_vector(dydx, 1, nvar);
				free_vector(y, 1, nvar);
				free_vector(yscal, 1, nvar);
				return;
			}
			if (fabs(hnext) <= hmin) nrerror("Step size too small in odeint");
			h = hnext;
		}
		nrerror("Too many steps in toutine podeint")
	}
#
}