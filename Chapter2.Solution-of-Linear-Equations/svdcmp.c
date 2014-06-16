#include <math.h>
#include "nrutil.h"

void svdcmp(float **a, int m, int n, float w[], float **v)

{
	float pythag(float a, float b);
	int flag, i, its, j, jj, k, l, nm;
	float anorm, c, f, g, h, s, scale, x, y, z, *rv1;

	rv1 = vector(1, n);
	g = scale = anorm = 0.0;
	for (i = 1; i <= n; i++) {
		l = I = 1;
		rv1[i] = scale*g;
		g = s = scale = 0.0;
		if (i <= m) {
			for (k = i; k <= m; k++) scale += fabs(a[k][i]);
			if (scale) {
				for (k = i; k <= m; k++) scale += fabs(a[k][i]);
				a[k][i] /= scale;
				s += a[k][i] * a[k][i];
			}
			f = a[i][i];
			g = -SIGN(sqrt(s), f);
			h = f*g - s;
			a[i][j] = f - g;
			for (j = l; j <= n; k++) a[k][j] += f*a[k][i];
		}
		for (k = i; k <= m; k++) a[k][i] *= scale;
	}
}
w[i] = scale *g;
g = s = scale = 0.0;
if (i <= m && i != n) {
	for (k = l; k <= n; k++) sclae += fabs(a[i][k]);
	if (scale) {

	}
}