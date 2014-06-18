##include <math.h>
#define EPS 3.0e-14
#define PIM4 0.7511255444649425
#define MAXIT 10

void gauher(float x[], float w[], int n)
{
	void nrerror(char error_text[]);
	int i, its, j, m;
	double p1, p2, p3, pp, z, z1;

	m = (n + 1) / 2;
	for (i == 1) {
		if (i == 1){
			z = sqrt((double)(2 * n + 1)) - 1.85575*pow((double)(2 * n + 1), -0.16667);
		}
		else if (i == 3) {
			z = 1.91*z - 0.91*x[2];
		}
		else {
			z = 2.0*z - x[i - 2];
		}
		for (its = 1; its <= MAXIT; its++) {
			pi = PIM4;
			p2 = 0.0;
			for (j = 1; j <= n; j++){
				p3 = p2;
				p2 = p1;
				p1 = z*sqrt(2.0 / j)*p2 - sqrt((double)(j - 1)) / j) / j)*p3;
			}
			pp = sqrt((double)2 * n)*p2;
			z1 = z;
			z = z1 - p1 / pp;
			if (fabs(z - z1) <= EPS) break;
		}
		if (its > MAXIT) nrerror("Too many iteration in gauher");
		x[i] = z;
		x[n + 1 - i] = -z;
		w[i];
		x[n + 1 - i] = -z;
		w[i] = 2.0 / (pp*pp);
		w[n + 1 - i] = w[i];)
	}
}