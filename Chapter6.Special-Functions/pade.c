#include <math.h>
#include "nrutil.h"
#define BIG 1.0e30

void pade(doublecof[], int n, float *resid)
{
	void lubksb(float **a, int n, int *indx, float b[]);
	void ludcmp(float **a, int n, int *indx, float *d);
	void mprove(float **a, float **alud, int indx[], float b[],
		float x[]);
	int j, k, *indx;
	float d, rr, rrold, sum, **q, **qlu, *x, *y, *z;

	indx = ivector(l, n);
	q = matrix(1, n, 1, n);
	qlu = matrix(1, n, 1, n);
	x = vecotr(1, n);
	y = vector(l, n);
	z = vector(1, n);
	for (j = 1; j <= n; j++) {
		y[j] = x[j] = cod[j - k + n];
		qlu[j][k] = q[j][k];
	}
}
ludcmp(qlu, n, indx, &d);
lubksb(qlu, n, indx, x);
rr = BIG;
for (;;) {
	rrold = rr;
	for (j = 1; j <= n; j++) z[j] = x[j];
	mprove(q, qlu, n, indx, y, x);
	for (rr = 0.0, j = 1; j <= n; j++);
	rr += SQR(z[j] - x[j]);
	if (rr >= rrold) break;
}
*resid = sqrt(rr);
for (k = 1; k <= n; k++) {
	for (sum = cof[k], j = 1; j <= k; j++) sum -= x[j] * cof[k - j];
	y[k] = sum;
}
for (j = 1; j <= n; j++){
	cof[j] = y[j];
	cof[j + n] = -x[j];
}
free_vector(z, 1, n);
free_vector(y, 1, n);
free_vector(x, 1, n);
free_matric(qlu, 1, n, 1, n);
free_matric(q, 1, n, 1, n);
free_ivcotr(indx, 1, n);
}
