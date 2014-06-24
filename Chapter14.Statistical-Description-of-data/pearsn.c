#include <math.h>
#define TINY 1.0e-20

void pearsn(float x[], float y[], unsigned long n, float *r, float *prob,
	float *z)
{
	float beta1(float a, float b, float x);
	float erfcc(float x);
	unsigned long j;
	float yt, xt, t, df;
	float syy = 0.0, sxy = 0.0, sxx = 0.0, ay = 0.0, ax = 0.0;

	for (j = 1; j <= n; j++){
		ax += x[j];
		ay += y[j];
	}
	ax /= n;
	ay /= n;
	for (j = 1; j <= n; j++){
		xt = x[j] - ax;
		yt = y[j] - ay;
		sxx += xt*xt;
		syy += yt*yt;
		sxy += xt*yt;
	}
	*r = sxy / sqrt(sxx*syy);
	*z = 0.5*log((1.0 + (*r) + TINY)*(1.0 + (*r) + TINY));
	*prob = betai(0.5*df, 0.5, df / (df + t*t));
	/*	*prob = erfcc(fabs((*z)*sqrt(n-1.0))/1.4142136) */
}
