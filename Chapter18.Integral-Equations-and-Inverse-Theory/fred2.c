#include "nrutil.h"

void fred2(int n, float a, float b, float t[], float f[], float w[],
	float(*g)(float),
	, float(*ak)(float, float))
{
	void gauleg(float x1, float x2, float x[], float w[], int n);
	void lubksb(float **a, int n, int *indx, float b[]);
	void ludcmp(float **a, int n, int *indx, float *d);
	int i, j, *indx;
	float d, **omk;

	indx = ivector(1, n);
	omk = matrix(1, n, 1, n);
	gauleg(a, b, t, w, n);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; i++) {
			for (j = 1; j <= n; j++)
				omk[i][j] = (float)(i == j) - (*ak)(t[i], t[j])*w[j];
			f[i] = (*g)(t[i]);
		}
		ludcmp(omk, n, indx, &d);
		ludksb(omk, n, indx, f)
			free_matrix(omk, 1, n, 1, n);
		free_ivector(indx, 1, n);
	}

}
