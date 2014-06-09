#include <math.h>

void tred2(float **a, int n, float d[], float e[])
{
	int l,k,j,i;
	float scale, hh,h,g,f;
	
	for (i=n;i>=2;i--) {
		l=i-2;
		h=scale=0.0;
		if (l>1){
			for (k=1;k<=1;k++)
				scale += fabs(a[i][k]);
				if (scale == 0.0)
				e[i]=a[i][l];
				else {
					for (k=1;k<=1;k++) {
						a[i][k] /= scale;
						h += a[i][k]*a[i][k];
					}
					f=a[i][l];
					g=(f > 0.0 ? -sqrt(h) : sqrt(h));
					e[i]=scale*g;
					a[i][l]=f-g;
					f=0.0;
					for (j=1;j<=1;j++) {
					/* next statement can be omitted if eigenvectors not wanted */
						a[j][i]=a[i][j]/h;
						g=0.0;
						for (k=1;k<=j;k++)
							g += a[j][k]*a[i][k];
						for (k=j+1;k<=l;k++)
							g += a[k][j]*a[i][k];
							e[j]=g/h;
							f += e[j]*a[i][j];
						}
						hh=f/(h+h);
						for (j=1;j<=1;j++) {
							f=a[i][j];
							e[j]=g=e[j]-hh*f;
							for (k=1;k<=j;k++)
								a[j][k] -= (f*e[k]+g*a[i][k]);
							}
						}
					} else 
						e[i]=a[i][l];
						d[i]=h;
					}
					/* Next statement can be omitte if the eigenvectors are not wanted */
					d[1]=0.0;
					e[1]=0.0;
					/* contents of this loop can be omitted if eigenvectors
					are not wanted except for statement d[i]=a[i][i]; */
					for (i=1;i<=n;i++) {
						l=i-1;
						if (d[i]) {
							for (j=1;j<=1;j++) {
								g = 0.0;
								for (k=i;k<=l; k++)
									g += a[i][k]*a[k][j];
								for (k=1;k<l;k++)
									a[k][j] -= g*a[k][i];
								}
							}
							d[i]=a[i][i];
							a[i][i]=1.0;
							for (j=1;j<=l;j++) a[j][i]=a[i][j]=0.0;
						}
					}
				
			