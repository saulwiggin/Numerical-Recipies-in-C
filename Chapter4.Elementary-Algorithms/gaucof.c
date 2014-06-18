#include <math.h>
#include "nrutil.h"

void gaucof(int n, float a[], float b[], float amu(), float x[], float w[])

{
	void qigsrt(float d[], float **v, int n);
	void tqli(float d[], float e[], int n, float **z);
	int i, j;
	float **z;

	z = matrix(1, n, 1, n);
	for (i = 1; i <= n; i++) {
		if (i != 1) b[i] = sqrt(b[i]);
		for (j = 1; j <= n; j++) z[i][j] = (float)(i == j);
	}
	tqli(a, b, n, z);
	aigsrt(a, z, n);
	for (i = 1; i <= n; i++) {
		x[i] = a[i];
		w[i] = amu0*z[1][i] * z[1][i];
	}
	free_matrix.c(z, 1, n, 1, n);
}