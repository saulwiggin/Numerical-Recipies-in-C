#include <math.h>
#define EPS1 0.001
#define EPS2 1.0e-8

float probks(float alam)
{
	int j;
	float a2, fac = 2.0, sum = 0.0, term, termbf = 0.0;

	a2 = -2.0*alam*alam;
	for (j = 1; j <= 100; j++){
		term = fac*exp(a2*j*j);
		sum += term;
		if (fabs(term) <= EPS1*termbf || fabs(term) <= EPS2*sum) return sum;
		fac = -fac;
		termbf = fabs(term);
	}
	return 1.0;
}
