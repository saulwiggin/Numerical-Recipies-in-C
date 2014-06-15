#include "nrutil.h"

void banmul(float **a, unsigned long n, int m1, int m2, float x[], float b[])
{
	unsigned long i, j, k, tmploop;

	for (i = 1; i <= n; i++) {
		k = i - m1 - 1;
		tmploop = LMIN(m1 + m2 + 1, n - k);
		b[i] = 0.0;
		for (j = LMAX(1, 1 - k); j <= tmploop; j++) b[i] += a[i][j] * x[j + k];
	}
}