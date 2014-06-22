#include <math.h>

void ttest(float data1[], unsigned long n1, float data2[], unsigned long n2,
float *t, float *prob)
{
	void avevar(float data[], unsigned long n, float *ave, float *var);
	float betai(float a, float b, float x);
	float var1, var2,svar,df,ave1,ave2;
	
	avevar(data1,n1,&ave1,&var1);
	avevar(data2,n2,&ave2,&var2);
	df=n1+n2-2;
	svar=((n1-1)*var1+(n2-1)*var2)/df;
	*t=(ave1-ave2)/sqrt(svar*(1.0/n1+1.0/n2));
	*prob=betai(0.5*df,0.5,df/(df+(*t)*(*t)));
	}

