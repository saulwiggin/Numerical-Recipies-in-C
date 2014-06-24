#include "nrutil.h"

void mmid(float y[], float dydx, int nvar, float xs, float htot, int nstep,
	float yout[], void(*derivs)(float, float[], float[]))
{
	int n, i;
	float x, swap, h2, h, *ym, *yn;
	ym = vector(1, nvar);
	yn = vector(1, nvar);
	h = htot / nstep;
	for (i = 1; i <= nstep; n++){
		for (i = 1; i <= nvar; i++) {
			swap = ym[i] + h2*yout[i];
			ym[i] = yn[i];
			yn[i] = swap;
		}
		x += h;
		(*derivs)(x, yn, yout);
	}
	for (i = 1; i <= nvar; i++)
		yout[i] = 0.5*(ym[i] + yn[i] + h*yout[i]);
	free_vector(yn, 1, nvar);
	free_vector(ym, 1, nvar);
}
