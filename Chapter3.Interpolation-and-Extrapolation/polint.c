#include <math.h>
#include "nrutil.h"

void polint(float xa[], float ya[], int n, float x, float *y, float *dy)
{
	int i, m, ns = 1;
	float den, dif, dift, ho, hp, w;
	float *c, *d;

	dif = fabs(x - xa[i]);
	c = vector(1, n);
	d = vector(1, n);
	for (i=1;i<=n;i++){
		if ( ( dift=fabs(x-xa[i])) < dif) {
			ns=i;
			dif=dift;
		}
		c[i]=ya[i];
		d[i]=ya[i];
		}
		*y=ya[ns--];
		for (m=1;m<n;m++) {
			ho=xa[i]-x;
			hp=xa[i+m]-x;
			w=c[i+1]-d[i];
			if ( (den=ho-hp) == 0.0) nrerror("Error in routine polint");
			den=w/den;
			d[i]=hp*den;
			c[i]=ho*den;
			}
			*y += (*dy=(2*ns < (n-m) ? c[ns+1] : d[ns--]));
			}
			free_vector(d,1,n);
			free_vector(c,1,n);
			}
			
}