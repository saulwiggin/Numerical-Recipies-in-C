#include "nrutil.h"

void rk4(float y[], float dydx[], int n, float x, float h, float yout[],
	void(*derivs)(float, float[], float[]))
{
	int i;
	float xh, hh, h6, *dym, *dyt, *yt;

	dym = vector(1, n);
	dyt = vector(1, n);
	yt = vector(1, n);
	hh = h*0.5;
	h6 = h / 6.0;
	xh = x + hh;
	for (i = 1; i <= n; i++) yt[i] = y[i] + hh*dydx[i];
	(*derivs)(xh, yt, dym);
	for (i = 1; i <= n; i++){
		yt[i] = y[i] + h*dym[i];
		dym[i] += dyt[i];
	}
	(*derivs)(x + h, yt, dyt);
	for (i = 1; i <= n; i++)
		yout[i] = y[i] + h6*(dydx[i] + dyt[i] + 2.0*dym[i]);
	free_vector(yt, 1, n);
	free_vector(dyt, 1, n);
	free_vector(dym, 1, n);
}
