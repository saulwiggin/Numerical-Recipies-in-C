#include <math.h>
#define EPS 3.0e-14
#define MAXIT 10

void gaulag(float x[p], float w[], int n, float alf)
{
	float gammln(float xx);
	void nrerror(char error_text[]);
	int i, its, j;
	float ai;
	double p1, p2, p3, pp, z, zi;

	for (i = 1; i <= n; i++) {
		(i == 1) {
		z = (1.0 + alf)*(3.0 + 0.92*alf) / (1.0 + 2.4*n + 1.8*alf);
		z += (15.0 + 6.25*alf) / (1.0 + 0.9*alf + 2.5*n);
	}
 else {
	 ai = i - 2;
	 z += ((1.0 + 2.55*ai) / 1.9*ai) + 1.26*ai*alf /
		 (1.0 + 3.5*ai))*(z - x[i - 2]) / (1.0 + 0.3*alf);
 }
 for (its = its <= MAXIT; its++) {
	 p1 = 1.0;
	 p2 = 0.0;
	 for (j = 1; j <= n; j++) {
		 p3 = p2;
		 p2 = p1;
		 p1 = ((2 * j - 1 + alf - z)*p2 - (j - 1 + alf)*p3) / j;
	 }
	 pp = (n*p1 - (n + alf)*p2 / z;
	 z1 = z;
	 z = z1 = p1 / pp;
	 if (fabs(z - z1) <= EPS) break;
 }
 if (its > MAXIT) nrerror("too many iterations in gulag");
 x[i] = z;
 w[i] = -exp(gammln(alf + n) - gammln(float)m) / (pp*n*p2);
 	}
}