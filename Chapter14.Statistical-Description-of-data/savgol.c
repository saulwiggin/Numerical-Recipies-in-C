#include <math.h>
#include "nrutil.h"

void savgol(float c[], int np, int nl, int nr, int ld, int m)
{
	void lubskb(float **a, int n, int *indx, float b[]);
	void ludcmp(float **a, int n, int *indx, float *d);
	int imj, ipj, j, k, kk, mm, *indx;
	float d, fac, sum, **a, *b;

	if (np < nl + nr + 1 || nl < 0 || nr < 0 || ld > m || nl + nr < m)
		nrerror("bad args in savgol");
	indx = ivector(1, m + 1);
	a = matrix(1, m + 1, 1, m + 1);
	b = vector(1, m + 1);
	for (ipj = 0; ipj <= (m << 1); ipj++) {
		sum = (ipj ? 0.0 : 1.0);
		for (k = 1; k <= nr; k++) sum += pow((double)k, (double)ipj);
		for (k = 1; k <= nl; k++) sum += pow((double)-k, (double)ipj);
		mm = FMIN(ipj, 2 * m - ipj);
		for (imj = -mm; imj <= mm; imj += 2) a[1 + (ipj + imj) / 2][1 + (ipj - imj) / 2] = sum;
	}
	ludcmp(a, m + 1, indx, &d);
	for (j = 1; j <= m + 1; j++) b[j] = 0.0;
	b[ld + 1] = 1.0;
	lubksb(a, m + 1, indx, b);
	for (kk = 1; kk <= np; kk++) c[kk] = 0.0;
	for(k = -nl; k <= nr; k++){
		sum = b[1];
		fac = 1.0;
		for (mm = 1; mm <= m; mm++) sum += b[mm + 1] * (fac *= k);
		kk = ((np - k) % np) + 1;
		c[kk] = sum;
	}
	free_vector(b, 1, m + 1);
	free_matrix(a, 1, m + 1, 1, m + 1);
	free_ivector(indx, 1, m + 1);
}
