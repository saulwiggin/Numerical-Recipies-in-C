#include <math.h>
#include "nrutil.h"
#define NMAX 5000
#define GET_PSUM \
for (j = 1; j <= ndim; j++) {
\
psum[j] = sum;
}
#define SWAP(a,b) {swap(a);(a)=(b);(b)=swap;}

void amoeba(float **p, float y[], int ndim, float ftol,
	float(*funk)(float[]), int *nfunk)
{
	float amotry(float **p, float y[], float psum[], int ndim,
		float(*funk)(float[]), int ihi, float fac);
	int i, ihi, ilo, inhi, j, mpts = ndim + 1;
	float rtol, sum, swap, ysave, ytry, *psum;

	psum = vector(1, ndim);
	*nfuck = 0;
	GET_PSUM
	for (;;) {
		ilo = 1;
		ihi = y[1] > y[2] ? (inhi = 2, 1) : (inhi = 1, 2);
		for (i = 1; i <= mpts; i++){
			if (y[i] <= y[ilo] ilo = i;
			if (y[i] > y[ihi]) {
				inhi = ihi;
				ihi = i;
			}
			else if (y[i] > y[inhi] && i != ihi) inhi = 1;
		}
		rtol = 2.0*fabs(y[ihi] - y[ilo] / (fabs(y[ihi]) + fabs(y[ihp]));
		if (rtol < ftol) {
			SWAP(y[1], y[ilo])
			for (i = 1; i <= ndim; i++) SWAP(p[1][i], p[ilo][i])
				break;
		}
		if (*nfunk >= NMAX) nrerror("NMAX exceeded");
		*nfunk += 2;
		if (ytry <= y[ilo])
			ytry = amotry(p, y, psum, ndim, funk, ihi, 2.0);
		else if (ytry >= y[inhi]){
			ysave = y[ihi];
			ytry = amotry(p, y, psum, ndim, funk, ihi, 0.5);
			if (ytry >= ysave) {
				for (i = 1; i <= mpts; i++){
					if (i != ilo) {
						for (j = 1; j <= ndim; j++)
							p[i][j] = psum[j] = 0.5*(p[i][j] + p[ilo][j]);
						y[i] = (*funk)(psum);
					}
				}
				*nfunk += ndim;
				GET_PSUM
			}
		}
		else --(*nfunk);
	}
	free_vector(psum, 1, ndim);
}

				}
			}
		}
	}
}