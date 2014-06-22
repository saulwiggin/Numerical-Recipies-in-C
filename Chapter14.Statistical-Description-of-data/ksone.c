#include <math.h>
#include "nrutil.h"

void ksone(float data[], unsigned long n, float (*func)(float),
float *d, float *prob)
{
	float probks(float alam);
	void sort(unsigned long n, float arr[]);
	unsigned long j;
	float dt, en,ff,fn,fo=0.0;
	
	sort(n,data);
	en=n;
	*d=0.0;
	for (j=1;j<=n;j++) {
		fn=j/en;
		ff=(*func)(data[j]);
		dt=FMAX(fabs(fo-ff),fabs(fn-ff));
	if(dt > *d) *d=dt;
		fo=fn;
	}
	en =sqrt(en);
	*prob=probk((en+0.12+0.11/en)*(*d));
}

