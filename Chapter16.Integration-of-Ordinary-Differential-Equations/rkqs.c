#include <math.h>
#include "nrutil.h"
#define SAFETY 0.9
#define PGROW -0.2
#define PSHRNK -0.25
#define ERRCON 1.89e-4

void rkqs(float y[], float dydx[], int n, float *x, float htry, float eps,
	float yscal[], float *hdid, float *hnext,
	void(*derivs)(float, float[], float[]))
{
	void rkck(float y[], float dydx[], int n, float x, float h,
		float yout[], float yerr[], void(*derivs)(float, float[], float[]));
	int i;
	float errmax, h, xnew, *yerr, *ytemp;

	yerr = vector(1, n);
	ytemp = vector(1, n);
	h = htry;
	for (;;){
		rkck(y, dydx, n, *x, h, ytemp, yerr, derivs);
		errmax = 0.0;
		for (i = 1; i <= n; i++) errmax = FMAX(errmax, fabs(yerr[i] / yscal[i]));
		errmax /= eps;
		if (errmax > 1.0) {
			h = SAFETY*h*pow(errmax, PSHRNK);
			if (h < 0.1*h) h *= 0.1;
			xnew = (*x) + h;
			if (xnew == *x) nrerror("stepsize underflow in rkqs");
			continue;
		}
		else {
			if (errmax > ERRCON) *hnext = SAFETY*h*pow(errmax, PGROW);
			else *hnext = 5.0*h;
			*x += (*hdid = h);
			for (i = 1; i <= n; i++) y[i] = ytemp[i];
			break;
		}
	}
	free_vector(ytemp, 1, n);
	free_vector(yerr, 1, n);
}
