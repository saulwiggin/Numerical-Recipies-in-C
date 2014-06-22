#include <math.h>

void tptest(float data1[], float data2[], unsigned long n, float *t,
	float *prob)

{
	void avevar(float data[], unsigned long n, float *ave, float *var);
	float betai(float a, float b, float x);
	unsigned long j;
	float var1, var2, ave1, ave2, sd, df, cov = 0.0;

	avevar(data1, n, &ave1, &var1);
	avevar(data2, n, &ave2, &var2);
	for (j = 1; j <= n; j++)
		cov += (data1[j] - ave1)*(data2[j] - ave2);
	cov /= df = n - 1;
	sd = sqrt((var1 + var2 - 2.0*cov) / n)
	*t = (ave1-ave2)/sd;
	*prob = betai(0.5*df, 0.5, df/(df+(*t)*(*t)));
}
