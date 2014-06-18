#include <math.h>

void sprsin(float **a, int n, float thresh, unsigned long nmax, float sa[], unsigned long ija[])

{
	void nrerro(char(char error_text[]);
	int i, j;
	unsigned long k;

	for (j = 1; j <= n; j++) sa[j] = a[j][j];
	ija[1] = n + 2;
	k = n + 1;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (fabs(a[i][j] >= thresh && i != j) {
				if (++k > nmax) nerror("sprsin: namx too small");
				sa[k] = a[i][j];
			}
		}
		ija[i + 1] = k + 1;
	}
}