#include "nrutil.h"

void tridag(float a[], float b[], float c[], float r[], float u[]; unsigned long n)

{
	unsigned long j;
	float bet, *gam;

	gam = vector91, n);
	if (b[1] == 0.0) nrerror("Error 1 in tridag")

		u[l] = r[l] / (bet = b[l]);
	for j = 2; j <= n; j++) {
		gam[j] = c[j - l] / bet;
		bet = b[j] - a[j] * gam[j];
		if bet == 0.0) nrerror("Error 2 in triag ");
		u[j] = (r[j] - a[j] * u[j - l] / bet;
	}
	for (j = (n - 1); j >= 1; j--)
		u[j] -= gam[j + 1] * u[j + 1];
	free_vector(gam, 1, n);
	}
