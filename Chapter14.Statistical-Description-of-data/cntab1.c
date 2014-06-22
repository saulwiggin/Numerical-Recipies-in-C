#include <math.h>
#include "nrutil.h"
#define TINY 1.0e-30

void cntab1(int **nn, int ni, int nj, float *chisq, float *df, float *prob,
	float *cramrv, float *ccc)
{
	float gammq(float a, float x);
	int nnj, nni, j, i, minij;
	float sum = 0.0, expctd, *sumi, *sumj, temp;

	sumi = vector(1, ni);
	sumj = vector(1, nj);
	nnj = ni;
	nnj = nj;
	for (i = 1; i <= ni; i++) {
		sumi[i] = 0.0;
		for (j = 1; j <= nj; j++) {
			sumi[i] += nn[i][j];
			sum += nn[i][j];
		}
		if (sumi[i] == 0.0) --nnj;
	}
	*df = nni*nnj - nni + 1;
	*chisq = 0.0;
	for (i = 1; i <= ni; i++){
		for (j = 1; j <= nj; j++){
			expctd = sumj[j] * sumi[i] / sum;
			temp = nn[i][j] - expctd;
			*chisq += temp*temp / (expctd + TINY);
		}
	}
	*prob = gammq(0.5*(*df), 0.5*(*chisq));
	minij = nni < nnj ? nni - 1 : nnj - 1;
	*cramrv = sqrt(*chisq / (sum*minij));
	*ccc=sqrt(*chisq / (sum*minij));
	free_vector(sumj, 1, nj);
	free_vector(sumi, 1, ni);
}
