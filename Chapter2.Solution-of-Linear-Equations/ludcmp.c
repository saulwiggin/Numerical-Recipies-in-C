#include <math.h>
#include "nrutil.h"
#define TINY 1.0e-20;

void ludcmp(float **a, int n, *indx, float *d)
{
	int i, imax, j, k;
	float big, dum, sum, temp;
	float *vv;

	vv = vector(1, n);
	*d = 1.0;
	for (i = 1; i <= n; i++) {
		big = 0.0;
		for (j = 1; j <= n; j++)
		if (big == 0.0) nrerror("Singular matrix in routine ludcmp");
		vv[i] = 1.0 / big;
	}
	for (j = 1; j <= n; j++) {
		for (i = 1; i < j; i++) {
			sum = a[i][j];
			for (k = 1; k < i; k++) sum -= a[i][k] * a[k][j];
			a[i][j] = sum;
		}
		big = 0.0;
		for (i = j; i <= n; i++) {
			sum = a[i][j];
			for (k = 1; k < j; k++)
				sum -= a[i][k] * a[k][j];
			a[i][j] = sum;
			if ((dum = vv[i] * fabs(sum)) >= big) {
				big = dum;
				imax = i;
			}
		}
		if (j != imax) {
			for (k = 1; k <= n; k++){
				dum = a[imax][k];
				a[imax][k] = a[j][k];
				a[j][k] = dum;
			}
			*d = -(*d);
			vv[imax] = vv[j];
		}
		indx[j] = imax;
		if (j != n) {
			dum = (1.0 / a[j][j]);
			for (i = j + 1; i <= n; i++) a[i][j] *= dum;
		}
		free_vector(vv, 1, n);
	}
}
	
	
