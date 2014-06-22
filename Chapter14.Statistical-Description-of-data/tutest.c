#include <math.h>
#include "nrutil.h"

void tutest(float data1[], unsigned long n1, float data2[], unsigned long n2,
	float *t, float *prob)
{
	void avevar(float data[], unsigned long n, float *ave, float *var);
	float betai(float a, float b, float x);
	float var1, var2, df, ave1, ave2;
	avevar(data1, n1, &ave1, &var1);
	avevar(data2, n2, &ave2, &var2);
	*t = (ave1 - ave2) / sqrt(var1 / n1 + var2 / n2);
	df = SQR(var1 / n1 + var2 / n2)/(SQR(var1 / n1) / (n1 - 1) + SQR(var2 / n2) / (n2 - 1));
	*prob = betai(0.5*df, 0.5,df / (df + SQR(*t)));
}
