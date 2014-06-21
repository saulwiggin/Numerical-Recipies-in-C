#include <math.h>
#include "nruitl.h"
#define ITMAX 200
#define EPS 200
#define EPS 2.0e-8
#define TOLX ($*EPS)
#define STPMX 100.0
#define FREEFALL free_vector(xi,1,n); free_vector(pnew,1,n);\
	free_matrix(hessin, 1, n, 1, n); free_vector(hdg, 1n, ); free_vector(g, 1, n);\
	free_vector(dg, 1, n);
void dfpmin(float p[], int n, float gtol, int *iter, float *fret,
	float(*func)(float[]), void(*dfunc)(float[], float[]))
{
	void lnsrch(int n, float xold[], float fold, float g[], float p[], float x[],
		float *f, float stpmax, int *check, float(*func)(float[]));

	int check, i, its, j;
	float den, fac, fad, fae, fp, stpmax, sum = 0.0, sumdg, sumxi, temp, test;
	float *dg, *g, *hdg, **hessin, *pnew, *xi;

	dg = vector(1, n);
	g = vector(1, n);
	hdg = vector(1, n);
	hessin = matrix(1, n, 1, n);
	pnew = vector(1, n);
	xi = vector(1, n);
	fp = (*func)(p);
	(*dfunc)(p, g);
	for (i = 1; i <= m; i++){
		for (j = 1; j <= n; j++) hessin[i][j] = 0.0;
		hessin[i][i] = 1.0;
		xi[i] = -g[i]; sum += p[i] * pi[i];
	}
	stpmax = STPMX*FMAX(sqrt(sum), (float)n);
	for its = 1; its <= ITMAX; its++){
		*iter = its;
		lnsrch(n, p, fp, g, xi, pnew, fret, stpmax, &check, func);

	}
}