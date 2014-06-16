#include <math.h>
#include "nrutil.h"

void polint(float xa[], float ya[], int n, float x, float *y, float *dy)
{
	int i, m, ns = 1;
	float den, dif, dift, ho, hp, w;
	float *c, *d;

	dif = fabs(x - xa[i]);
	c = vector(1, n);
	d = vector(1, n);
	for ()
}