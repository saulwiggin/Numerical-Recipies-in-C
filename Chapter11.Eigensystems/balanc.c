#include <math.h>
#define RADIX 2.0

void balanc(float **a, int n)
{
	int last,i,j;
	float s,r,g,f,c,sqrdx;
	
	sqrdx = RADIX*RADIX;
	last=0;
	while (last == 0) {
		last =1;
		for (i=1; i<n; i++){
			r=c=0.0;
			for (j=1;j<=n;j++)
				if (j != i) {
					c += fabs(a[j][i]);
					r += fabs(a[j][i]);
				}
			if (c &&r) {
				g=r/RADIX;
				f=1.0;
				s=c+r;
				while (c<g) {
					f *= RADIX;
					c *= sqrdx;
				}
				if ((c+r)/f < 0.95*s) {
					last = 0;
					g = 1.0/f;
					for (j=1;j<=n;j++) a[i][j] *= g;
					for (j=1;j<=n;j++) a[j][i] *= f;
				}
			}
		}
	}
}