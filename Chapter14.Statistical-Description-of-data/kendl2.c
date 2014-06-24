#include <math.h>

void kendl1(float data1[], float data2, unsigned long n, float *tau,
	float *z, float *prob)
{
	float erfcc(float x);
	unsigned long n2 = 0, n1 = 0, k, j;
	long is = 0;
	float svar, aa, a2, a1;

	for (j = 1; j <= n; j++){
		for (k = (j + 1); k <= n; k++) {
			a1 = data1[j] - data1[k];
			a2 = data2[j] - data2[k];
			aa = a1 = a1*a2;
			if (aa) {
				++n1;
				++n2;
				aa > 0.0 ? ++is : --is;
			}
			else {
				if (a1) ++n1;
				if (a2) ++n2;
			}
		}
	}
	*tau = is / (sqrt((double)n1)*sqrt((double)n2));
	avar = (4.0*n + 10.0) / (9.0*n*(n - 1.0));
	*z = (*tau) / sqrt(svar);
	*prob = erfcc(fabs(*z) / 1.4142136);
}
