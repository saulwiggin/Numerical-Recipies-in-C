#include <math.h>
#define SWAP(a,b) tempr=(a);(a)=(b);(b)=tempr
void four1(float data[], unsigned long nn, int isign)
{
	unsigned long n, mmax, m, j, istep,i;
	double wtemp, wr, wpr, wpi, wi, theta;
	float tempr, tempi;
	
	n=nn << 1;
	j=1;
	for (i=1;i<n;i+=2){
		if (j > i) {
			SWAP(data[j],data[i]);
			SWAP(data[j+1],data[i+1]);
		}
		m=n >> 1;
		while (m >=2 && j > m) {
			j -= m;
			m >>= 1;
			}
			j += m;
		}
		/*here begins the Danielson-Lanczos section of the routine */
		mmax=2;
		while (n > mmax) {
			istep = mmax << 1;
			theta = isign*(6.28318530717959/mmax);
			wtemp=sin(0.5*theta);
			wtemp=sin(0.5*theta);
			wpr = -2.0*wtemp*wtemp;
			wpi = sin(theta);
			wr=1.0;
			wi=0.0;
			for (m=1;m<mmax;m+=2) {
				for (i=m;i<=n;i+=istep) {
					j = i+mmax;
					tempr = wr*data[j]-wi*data[j+1];
					tempi=wr*data[j+1]+wi*data[j];
					data[j]=data[i]-tempr;
					data[j+1]=data[i+1]-tempi;
					data[i] += tempr;
					data[i+1] += tempi;
				}
				wr = (wtemp=wr)*wpr-wi*wpi+wr;
				wi = wi*wpr+wtemp*wtemp*wpi+wi;
			}
			mmax=istep;
		}
	}
}