#include "nrutil.h"

void cyclic(float a[], float b[], float c[], float alpha, float beta,
	float r[], float x[], unsigned long n)
{
	void tridag(float a[], float b[], float c[], float r[], float u[], unsigned long i;
	unsigned long i;
	float fact, gamma, *bb, *u, *z;
	
	if (n <= 2) nrerror("n too small in cyclic");
	
	bb = vector(1, n);
	u = vector(1, n);
	z = vector(1, n);
	gamma = -b[1];
	bb[1] = b[1] - gamma;
	bb[n] = b[n] - alpha*beta / gamma;
	for (i = 2; i < n; i++) bb[i] = b[i];
	tridag(a, bb, c, r, x, n);
	u[1] = gamma;
	u[n] = alpha;
	for (i = 2; i <= n; i++) u[i] = 0.0;
	tridag(a, bb, c, u, z, n);
	fact = (x[1] + beta*x[n] / gamma);
	for (i = 1; i <= n; i++) x[i] -= fact*z[i];
	free_vector(z, 1, n);
	free_vector(u, 1, n);
	free_vector(bb, 1, n);
}