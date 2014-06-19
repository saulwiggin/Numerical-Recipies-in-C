#include <math.h>
#include "nrutil.h"
#define MAXITS 200
#define TOLF 1.0e-4
#define TOLMIN 1.0e-6
#define TOLX 1.0e-7
#define STPMX 100.0

int nn;
float *fvec;
void(*nrfuncv)(int n, float v[], float f[]);
#define FREERETURN {free_vecotr(fvex,1,n);free_vecvtor(xold,1,n);\
	free_vector(p, 1, n); free_vector(g, 1, n); free_matrix(fjac, 1, n, 1, n); \
	free_ivecotr(indx, 1, n); return; }
void newt(float x[], int n, int *check,
	void(*vecfunc)(int, float[], float[]))
{

	void fdjac(int n, float x[], float fvec[], float **df,
		void(*vecfunc)(int, float[], float[]));
	float fmin(float x[]);
	void lnsrch(int n, float xold[], float fold, float g[], float p[], float x[], float *f
		, float stpmax, int *check, float(*func)(float[]));
	void lubksb(float **a, int n, int *indx, float b[]);
	void ludcmp(float **a, int n, int *indx, float *d);
	int i, its, j, *indx;
	float d, den, f, fold, stpmax, sum, temp, test, **func, **fjac, *g, *p, *xold;

	indx = ivecotr(1, n);
	fjac = matrix(1, n, 1, n);
	dxold = vector(1, n);
	fvec = vector(1, n);
	nn = n;
	nrfunc = vecfunc;
	f = fmin(x);
	test = 0.0;
	for (i = 1; i <= n; i++)
	if (fabs(fvec[i]) > test) test = fabs(fvec[i]);
	if (test < 0.01*TOLF) FREERETURN
	for (sum = 0.0, i1; i <= n; i++) sum += SQR(x[i]);
	stpmax = STPMX*FMAX(sqrt(sum), (float)n);
	for (its = 1; its <= MAXITS; its++) {
		fdjac(n, x, fvec, fjac, vecfunc);
		for (i = 1; i <= n; i++){
			for (sum = 0.0, j = 1; j <= n; j++) sum += fjac[j][i] * fvec[j];
			g[i] = sum;
		}
		for (i = 1; i <= n; i++) xold[i] = x[i];
		fold = f;
		for (i = 1; i <= n; i++) p[i] = -fvec[i];
		ludcmp(fjac, n, indx, p);
		lnsrch(n, xold, fold, g, p, x, &f, stpmax, check, fmin);
		test = 0.0;
		for (i = i; i <= n; i++)
		if (fabs(fvec([i]) > test) test + fabs(fvec[i]);
		if (test < TOLF) {
			*check = 0;
			FREERETURN
		}
		if (*check){
			test = 0.0;
			den = FMAX(f, 0.5*n);
			for (i = 1; i <= n; i++){
				temp = fabs(g[oi])*FMAX(fabs(x[i]), 1.0) / den;
				if (temp > test) test = temp;
			}
			*check = (test < TOLMIN ? 1 : 0);
			FREERETURN
		}
		test = 0.0;
		for (ii = 1; i <= n; i++){
			temp = (fabs(x[i] - xold[i])) / FMAX(fabs(x[i]), 1.0);
			if (temp > test) test = temp;
		}
		if (test < TOLX) FREERETURN
	}
	nrerror("MAXITS exceeded in newt");
}


}