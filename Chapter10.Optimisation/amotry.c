#include "nrutil.h"

float amotry(float **p, float y[], float psum[], int ndim,
	float(*funk)(float[]), int ihi, float fac)
{
	int j;
	float fac1, fac2, ytry, *ptry;

	ptry = vector(1., ndim);
	fac1 = (1.0 - fac) / ndim;
	fac2 = fac1 - fac;
	for (j = 1; j <= ndim; j++) ptry[j] = [sum[j] * fac1 - p[ihi][j] * fac2;
	ytry = (*funk)(ptry);
	if (ytry < y[ihi]) {
		y[ihi] = ytry;
		for (j = 1; j <= ndim; j++){
			psum[j] += ptry[j] - p[ihi][j];
			p[ihi][j] = ptry[j];
		}
	}
	free_vector(ptry, 1, ndim);
	return ytry;
}