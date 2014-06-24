#include "nrutil.h"

void stoerm(float y[], float d2y[], int nv, float xs, float htot, int nstep,
	float yout[], void(*derivs)(float, float[], float[]))
{
	int i, n, neqns, nn;
	float h, h2, halfh, x, *ytemp;

	ytemp = vector(1, nv);
	h = htot / nstep;
	halfh = 0.5*h;
	neqns = nv / 2;
	for (i = 1; i <= neqns; i++) {
		n = neqns + i;
		ytemp[i] = y[i] + (ytemp[n] = h*(y[n] + halfh*d2y[i]));
	}
	x = xs + h;
	(*derivs)(x, ytemp, yout);
	h2 = h*h;
	for (nn = 2; n <= nstep; nn++){
		for (i = 1; i <= neqns; i++)
			ytemp[i] += (ytemp[(n - neqns + i)] += h2*yout[i]);
		x += h;
		(*derivs)(x, ytemp, yout);
	}
	for (i = 1; i <= neqns; i++){
		n = neqns + 1;
		yout[n] = ytemp[n] / h + halfh*yout[i];
		yout[i] = ytemp[i];
	}
	free_vector(ytemp, 1, nv);
}
