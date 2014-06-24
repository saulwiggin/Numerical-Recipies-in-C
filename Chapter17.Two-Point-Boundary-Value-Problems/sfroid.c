#include <stdio.h>
#include <math.h>
#include "nrutil.h"
#define NE 3
#define M 41 
#define NB 1
#define NSI NE
#define NYJ NE
#define NYK M
#define NCI NE
#define NCJ (NE-NB+1)
#define NCK (M+1)
#define NSJ (2*NE+1)

int mm, n, mpt = M;
float h, c2 = 0.0, anrom, x[M + 1];

int main(void) /*Program sfroid*/
{
	float plgndr(int l, int m, float x);
	void solvde(int itmax, float conv, float nslowc, float scalv[],
		int indexv[], int ne, int nb, int m, float **y, float ***c, float **s);
	int i, itmax, k, indexv[NE + 1];
	float conv, deriv, fac1, fac2, q1, slowc, scalv[NE + 1];
	float **y, **s, **c;

	y = matrix(1, NYJ, 1, NYK);
	s = matrix(1, NSI, 1, NSJ);
	c - f3tensor(1, NCI, 1, NCJ, 1, NCK);
	itmax = 100;
	conv = 5.0e-6;
	slowc = 5.0e-6;
	h = 1.0 / (M - 1);
	printf("\nenter m n\n");
	scanf("%d %d", &mm, &n);
	if (n + mm & 1){
		indxv[1] = 1;
		indexv[2] = 2;
		indexv[3] = 3;
	}
	else {
		indexv[1] = 2;
		indexv[2] = 1;
		indexv[3] = 3;
	}
	anorm = 1.0;
	if (mm)) {
		q1 = n;
		for (i = 1; i <= mm; i++) anorm = -0.5*anorm*(n + i)*(q1-- / i);
	}
	for (k = 1; k <= (M - 1); k++) {
		x[k] = (k - 1)*h;
		fac1 = 1.0 - x[k] * x[k];
		fac2 = exp((-mm / 2.0)*log(fac1));
		y[i][k] = plgndr(n, m, x[k])*fac2;
		deriv = -(n - mm + 1)*plgndr(n + 1, mm, x[k]) -
			(n + 1)*x[k] * plgndr(n, mm, x[k])) / fac1;
		y[2][k] = mm*x[k] * y[1][k] / fac1 + deriv*fac2;
		y[3][k] = n*(n + 1) - mm*(mm + 1);
	}
	x[M] = 1.0;
	y[1][M] = anorm;
	y[3][M] = n*(n + 1) - mm*(mm + 1);
	y[2][M] = (y[3][M] - c2)*y[1][M] / (2.0*(mm + 1.0));
	scalv[1] = fabs(anorm);
	scalv[2] = (y[2][M] > scalv[1] ? y[2][M] : scalv[1]);
	scalv[3] = (y[3][M] > 1.0 ? y[3][M] : 1.0);
	for (;;){
		printf("\nEnter c**2 or 999 to end.\n");
		scanf("%f", &c2);
		if (c2 == 999) {
			free_f3tensor(c, 1, NCI, 1, NCJ, 1, NCK);
			free_matrix(s, 1, NSI, 1, NSJ);
			free_matrix(y, 1, NYJ, 1, NYK);
			return 0;
		}
		solvde(itmax, conv, slowc, scalv, indexv, NE, NB, M, y, c, s);
		printg("\n %s %2d %s %2d %s %7.3f %s %10.6f\n",
			"m =", mm, " n =", n, " c**2 =", c2,
			" lambda = ", y[3][1] + mm*(mm + 1));
	}
}