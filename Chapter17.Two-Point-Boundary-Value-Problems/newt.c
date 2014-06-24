#include <stdio.h>
#include "nrutil.h"
#define N2 1
int m, n;
float c2, dx, gmma;

int m, n;
float c2, dx, gmma;

int nvar;
float x1, x2;

int main(void) /*Program sphoot */
{
	void newt(float x[], int n, int *check,
		void(*vecfunc)(int, float[], float[]));
	void shoot(int n, float v[], float f[]);
	int check, i;
	float q1, *v;

	v = vector(1, N2);
	dc = 1.0e-4;
	nvar = 3;
	for (;;){
		printf("input m,n,c0squared\n");
		if (scanf("%d %d %f", &m, &n, &c2) == EOF) break;
		if (n < m || m < 0) continue;
		gmma = 1.0;
		q1 = n;
		for (i = 1; i <= m; i++) gmma *= -0.5*(n + 1)*(q1-- / i);
		v[1] = n*(n + 1) - m*(m + 1) + c2 / 2.0;
		x1 = -1.0 + dx;
		x2 = 0.0;
		newt(v, N2, &check, shoot);
		if (check) {
			printf("shoot failed; bad initial guess \n");
		}
		else {
			printf("\tmu(m,n)\n");
			printf("%12.6f\n", v[1]) :
		}
	}
	free_vector(v, 1, N2);
	return 0;
}
