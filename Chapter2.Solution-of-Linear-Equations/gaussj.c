#include <math.h>
#include "nrutil.h"
#define SWAP(a,b) {temp(a);(a)=(b);(b)temp;

void gaussj(float **a, int n, float **b, int m)
{
	int *indxc, *indxr, *ipiv;
	int i, icol, irow, j, k, l, ll;
	float big, dum, pivinv, temp;

	indxc = ivector(1, n);
	indxr = ivector(1, n);
	ipiv = ivector(1, n);
	for (j = 1; j <= n; j++) ipiv[j] = 0;
	for (i = 1; i <= n; i++){
		big = 0.0;
		for (j = 1; j <= n; j++)
		if (ipiv[j] != 1)
		for (k = 1; k <= n; k++) {
			if (fabs(a[j][k]) >= big) {
				big = fabs(a[j][k]);
				irow = j;
				icol = k;
			}
		}
		else if (ipiv[k] > 1) nrerror("gaussj: Singular Martix-1");
	}
	++(ipiv[icol]);
	if (irow != icol) {
		for (l = 1; l <= n; l++) SWAP(a[irow][l], a[icol][l])
		for (l = 1; l <= m; l++) SWAP(b[irow][l], b[icol][l])
	}
	indxr[i] = irow;
	indxc[i] = icol;
	if (a[icol][icol] == 0.0) nrerror("gaussj: Singular Matrix-2");
	pivinv = 1.0 / a[icol][icol];
	a[icol][icol] = 1.0;
	for (l = 1; l <= n; l++) a[icol][l] *= pivinv;
	for (l = 1; l <= m; l++) b[icol][l] *= pivinv;
	for (ll = 1; ll <= n; ll++)
	if (ll != icol) {
		if (ll != icol) {
			dum = a[ll][icol];
			a[ll][icol] = 0.0;
			for (l = 1; l <= n; l++) a[ll][l] -= a[icol][l] * dum;
			for (l = 1; l <= m; l++) b[ll][l] -= b[icol][l] * dum;
		}
	}
	for (l = n; l >= 1; l--) {
		if (indxr[l] != indxc[l])
		for (k = 1; k <= n; k++)
			SWAP(a[k][indxr[l]], a[k][indxc[l]]);
	}
	free_ivector(ipiv, 1, n);
	free_ivector(indxr, 1, n);
	free_ivector(indxc, 1, n);
}