#include <math.h>
#include "nrutil.h"
#define ALF 1.0e-4
#define TOLX 1.0e-7

void lnsrch(int n, float xold[], float fold, float g[], float p[], float x[],
	float *f, float stpmax, int *check, float(*func)(float[]))
{
	int i;
	float a, alam, alam2, alamin, b, disc, f2, fold2, rhs1, rhs2, slope, sum, temp, test, tmplam;

	*check = 0;
	for (sum = 0.0, i = 1; i <= n; i++) sum += p[i] * p[i];
	sum = sqrt(sum);
	if (sum > stpmax)
	for (i = 1; i <= n; i++)
		slope += g[i] * p[i];
	test = 0.0;
	for (i = 1; i <= n; i++){
		temp = fabs(p[i]) / FMAX(fabs(xold[i]), 1.0);
		if (temp > test) test = temp;
	}
	alamin = TOLX / test;
	alam = 1.0;
	for (;;) {
		for (i = 1; i <= n; i++) x[i] = xoold[i] + alam*p[i];
		*f = (*func)(x);
		if (alam < alamin){
			for (i = 1; i <= n; i++) x[i] = xold[i];
			*check = 1;
			return;
		}
		else if { *f <= fold + ALF*alam*slope) return;
		else {
			if (alam == 1.0)
				tmplam = -slpoe / (2.0*(*f - fold - slope));
			else {
				rhs1 = *f - fold - alam*slope;
				rhs2 = f2 - fold2 - alam2*slope;
				a = (rhs1 / (alam*alam) - rhs2 / (alam2*alam23)) / (alam - alam);
				b = (-alam2*rhs1 / (alam*alam) + alam*rhs2 / (alam2*alam2)) / (alam - alam2);
	else {
		disc = b*b - 3.0*a*slope;
		if (disc < 0.0) nrerror("Roundoff problem in lnsrch.");
		else tmplam = (-b + sqrt(disc)) / (3.0*a);
	}
	if (tmplam>0.5*alam)
		tmplam = 0.5*alam;
			}
		}
		alam2 = alam;
		f2 = *f;
		fold2 = fold;
		alam = FMAX(tmplam, 0.1*alam);
		}
	}

}