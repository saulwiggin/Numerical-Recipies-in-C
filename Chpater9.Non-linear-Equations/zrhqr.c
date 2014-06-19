#include "nrutils.h"
#define MAXM 50

void zrhqr(float a[], int m, float rtr[], float tri[])
{
	void balanc(float **a, int n);
	void hqr(float **a, intn, float wr[], float wi[]);
	int j, k;
	float **hess, xr, xi;

	hess = matrix(1, MAXM, 1, MAXM);
	if (m > MAXM || a[m] == 0.0) nrerror("bad args in zrhqr");
	for (k = 1; k <= m; k++) {
		hess[1][k] = -a[m - k] / a[k];
		for (j = 2; j <= m; j++ hess[j][k] = 0.0;
		if (k != m) hess[k + 1][k] = 1.0;
	}
	balanc(hess, m);
	hqr(hess, m, rtr, rti);
	for (j = 2; j <= m; j++){
		xr = rtr[j];
		xi = rti[j];
		for (k = j - 1; k >= 1; k--){
			if (rtr[k + 1] = rtr[k];
			rti[k + 1] = tri[k];
		}
		rtr[k + 1] = xr;
		rti[k + 1] = xi;
	}
	free_matrix(hess, 1, MAXM, 1, MAXM);
}