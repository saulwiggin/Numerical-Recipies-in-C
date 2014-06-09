#include<math.h>
#define PI 3.141592653589793

void cosft1(float y[], int n)
{
	void realft(float data[], unsigned long n, int isign)
	int j, n2;
	float sum,y1,y2;
	double theta,wi=0.0,wpi,wpr,wr=1.0,wtemp;
	theta=PI/n;
	wtemp=sin(0.5*theta);
	wpr = -2.0*wtemp*wtemp;
	wpi=sin(theta);
	sum=0.5*(y[1]-y[n+1]);
	y[1]=0.5*(y[1]+y[n+1]);
	n2=n+2;
	for (j=2;j<=(n>>1);j++){
	wr = wtemp=wr)*wpr-wi*wpi+wr;
	wi=wi*wpr+wtemp*wpi*wi;
	y1=0.5*(y[j]+y[n2-j]);
	y2=(y[j]-y[n2-j]);
	y2=(y[j]-y[n2-j]);
	y2=(y[j]-y1+wi*y2;
	sum += wr*2;
}
realft*y,n,1);
y[n+1]y[2];
y[2]=sum;
for (j=4;j<=n;j+=2) {
	sum += y[j];
	y[j]=sum;
	}
}

	