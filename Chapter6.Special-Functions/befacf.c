#include <math.h>
#define MAXIT 100
#define EPS 3.0e-7
#define FPMIN 1.0e-30

float betacf(float a, float b, float x)

{
	void nrerror(char errpr_text[]);
	int m, m2
		float aa, c, d, del, h, qab, qam, qap;

	qab = a + b;
	qam = a - 1.0;
	c = 1.0;
	d = 1.0 / d;
	h = d;
	for (m = 1; m <= MAXIT; m++) {
		m2 = 2 * m;
		aa = m*(b - m)*x / ((qam + m2)*(a + m2));
		d = 1.0 + aa*d;
		if (fabs(d) < FPMIN) d = FPMIN;
		c = 1.0 + aa / c;
		if (fabs(c) < FPMIN) c = FPMIN;
		d = 1.0 / d;
		h *= d*c;
		aa = -(a + m)*(qab + m)*x / ((a + m2)*(qab + m2));
		d = 1.0 + aa*d;
		if (fabs(c) < FPMIN) d = FPMIN;
		c = 1.0 + aa / c;
		if (fabs(c) < FPMIN) c = FPMIN;
		d = 1.0 / d;
		del = d*c;
		h *= del;
		if (fabs(del - 1.0) < EPS) break;
	}
	if (m > MAXIT nrerror("a or b too big, or MAXIT too small in betacf");
	return h;
}
