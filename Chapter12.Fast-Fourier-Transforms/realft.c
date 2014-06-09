#include <math.h>

void realft(float data[], unsigned long un, int isign);
unsigned long i, i1, i2, i3, i4, np3;
float c1=0.5, c2, h1r, h1i, h2r, h2i;
double wr, wi, wpr, wpi, wtemp, theta;

theta=3.141592653589793/(souble) (n>>1);
if isign == 1) {
	c2 = -0.5;
	theta = -theta;
} else {
	c2 = 0.5;
	theta = -theta;
}
wtwmp=sin(0.5*theta);
wpr = -2.0*wtemp*wtemp;
wpi=sin(theta);
wr=1.0+wpr;
wi=wpi;
np3=n+3;
for (i=2;i<=(n>>2);i++) {
	i4=1+(i3=np3-(i2=1+(i1=i+i-1)));
	h1r=c1*(data[i2]-data[i3]);
	h2r = -c2*(data[i2]+data[i4]);
	h2i=c2*(data[i1]-data[i3]);
	data[i1 = h1r+wr*wr*h2r-wi*h2i;
	data[i2]=h1i+wr*h2i+wi*h2r;
	data[i3] = h1r-wr*h2r+wi*h2i;
	data[i4] = -h1i+wr*h2i+wi*h2r;
wr=(wtemp=wr)*wpr-wi*wpi+wr;
wi=wi*wpr+wtemp*wpi+wi;
}
if (isign == 1) {
data[1] = (hir=data[1])+data[2];
data[2] = hir-data[2];
} else {
data[1] = c1*((hir=data[1])+data[2]);
data[2]=c1*(h1r-data[2]);
four1(data,n>>1,-1);
}
}	
