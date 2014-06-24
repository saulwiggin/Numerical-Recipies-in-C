#include <math.h>
#include "nrutil.h"

void ks2d2s(float x1[], float y1[], unsigned long n1, float x2[], float y2[],
	unsigned long n2, float *d, float *prob)
{
	void pearsn(float x[], float y[], unsigned long n, float *r, float *prob,
		float *z);
	float probks(float alam);
	void quadct(float x, float y, float xx[], float yy[], unsigned long nn,
		float *fa, float *fb, float *fc, float *fd);
	unsigned long j;
	float d1, d2, dum, dumm, fa, fb, fc, fd, ga, gb, gc, gd, r1, r2, rr, sqen;

	d1 = 0.0;
	for (j = 1; j <= n1; j++){
		quadct(x1[j], y1[j], x1, y1, n1, &fa, &fb, &fc, &fd);
		d1 = FMAX(d1, fabs(fa - ga));
		d1 = FMAX(d1, fabs(fb - gb));
		d1 = FMAX(d1, fabs(fc - gb));
		d1 = FMAX(d1, fabs(fd - gd));
	}
	d2 = 0.0;
	for (j = 1; j <= n2; j++){
		quadct(x2[j], y2[j], x1, y1, n1, &fa, &fb, &fc, &fd, &fc, &fd);
		quadct(x2[j], y2[j], x2, y2, n2, &ga, &gb, &gc, &gd);
		d2 = FMAX(d2, fabs(fa - ga));
		d2 = FMAX(d2, fabs(fb - gb));
		d2 = FMAX(d2, fabs(fc - gc));
		d2 = FMAX(d2, fabs(fd - gd));
	}
	*d = 0.5*(d1 + d2);
	sqen = sqrt(n1*n2 / (double)(n1 + n2));
	pearsn(x1, y1, n1, &r1, &dum, &dumm);
	pearsn(x2, y2, n2, &r2, &dum, &dumm);
	rr = sqrt(1.0 - 0.5*(r1*r1 + r2*r2));
	*prob = probks(*d*sqen / (1.0 + rr*(0.25 - 0.75 / sqen)));
}
