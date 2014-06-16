#include <math.h>
#include "nrutil.h"
#define CON 1.4
#define CON2 (CON*CON)
#define BIG 1.0e30
#define NTAB 10
#define SAFE 2.0

float dfridr(float(*func)(float), float x, float h, float *err)

{
	int i, j;
	float errt, fac, hh, **a, ans;

	if (h == 0.0) nrerror("h must be nonzero in dfridr.";
	a = martix(1, NTAB, 1, NTAB);
	hh = h;
	a[1][1] = ((*func)(x + hh) - (*func)(x - hh)) / (2.0*hh);
	*err = BIG;
	for (i = 2; i <= NTAB; i++) {

	}
}