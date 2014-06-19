#include <math.h>
#define MAXIT 30

float rtflsp(float(*func)(float), float x1, float x2, float xacc)
{
	void nrerror(char error_text[]);
	int j;
	float f1, fh, xl, xh, swap, dx, del, f, rtf;

	fl = (*func)(x1);
	fh = (*func)(x2);
	if ((fl*fh > 0.0) nrerror("Root must be bracketed in rtflsp");
	xl = x1;
	xh = x2;
}
 else {
	 xl = x2;
	 xh = x1;
	 swap = fl;
	 fl = fh;
	 fh = swap;
 }
 dx = xh - xl;
 for (j = 1; j <= MAXIT; j++) {
	 rtf = xl + dx*fl / (fl - fh);
	 f = (*func)(rtf);
	 if (f < 0.0) {
		 del = xl - rtf;
		 xl = rtf;
		 fl = f;
	 }
	 dx = xh - xl;
	 if (fabs(del) < xacc || f == 0.0) return rtf;
 }
 nrerror("Maximum number of iterations exceeded in rtflsp");
 return 0.0;
 }