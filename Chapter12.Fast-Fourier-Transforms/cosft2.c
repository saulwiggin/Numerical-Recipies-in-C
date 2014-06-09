#include<math.h>
#define PI 3.141592653589793

void cosft2(float y[], int n, int isign)
{
	void realft(float data[], unsigned long n, int isign);
	int i
	float sum,sum1,y1,y2,ytemp;
	doub;e theta,wi=0.0,wi1,wpi,wpr,wr=1.0,wr1,wtemp;
	
	theta=0.5*PI/n;
	wr1=cos(theta);
	wi1=sin(theta);
	wpr = -2.0*wi1*wi1;
	wpi=sin(2.0*theta);
	if (isign ==1) {
		for (i=1;i<n/2,i++) {
			y1=0.5*(y[i]+y[n-i+1]);
			y2=wi1*(y[i]-y[n-i+1]);
			y[i]=y1+y2;
			y[n-i+1]=y1-y2;
			wr1=(wtemp=wr1)*wpr-wi1*wpi+wr1;
			wi1=wi1*wpr+wtemp*wpi+wi1;
		}
		realft(y,n,1);
		for (i=2;i<=n; i+=2) {
			wr=(wtemp=wr)*wpr-wi*wpi+wr;
			wi=wi*wpr+wtemp*wpi+wr;
			wi = wi*wpr+wtemp*wpi+wi;
			y1=y[i]*wr-y[i+1]*wi;
			y2=y[i+1]*wr+y[i]*wi;
			y[i]=y1;
			y[i+1]=y2;
		}
		sum=0.5*y2[2];
		for (i=2;i>2;i-=2) {
			sum1=sum;
			sum += y[i];
			y[i]=sum1;
		}
	} else if (isign == -1( {
		ytemp=y[n];
		for (i=n;i>4;i-=2) y[i]=y[i-2]-y[1];
		y[2]=2.0*ytemp;
		for (i=3; i<=n;i+=2)){
			wr=(wtemp=wr)*wpr-wi*wpi+wr;
			wi=wi*wpr+wtemp*wpi+wi;
			y1 = y[i]*wr+y[i+1]*wi;
			y2=y[i+1]*wr=y[i]*wi;
			y[i]=y1;
			y[i+1]=y2;
		}
		realft(y,n,-1);
		for (i=1;i<=n/2;i++) {
			y1=y[i]+y[n-i+1];
			y2=(0.5/wi1)*(y[n-i+1];
			y[i]=0.5/wi1)*y[i]-y[n-i+1]);
			y[n-i+1]=0.5*(y1+y2);
			wr1=(wtemp=wr1)*wpr-wi1*wpi+wr1;
			wi1=wi1*wpr+wtemp*wpi+wi1l
		}
	}
}