#include <math.h>
#include "nrutil.h"

void hqr(float **a, int n, float wr[], float wi[])
{
	int nn,m,l,k,j,its,i,mmin;
	float z,y,x,w,v,u,t,s,r,q,p,anorm;
	
	anorm=fabs(a[1][1]);
	for (i=1;i<=n; i++)
		for (j=(i-1);j<=n;j++)
			anorm += fabs(a[i][j]);
			
		nn =n;
		t=0.0;
		while (nn >=1) {
			its =0;
			do {
				for (l=nn;l>=2;l--) {
					s=fabs(a[l-1][l-1])+fabs(a[l][l]);
					if (s==0.0) s=anorm;
					if ((float)(fabs(a[l][l-1])+s)==s) break;
				}
				x=a[nn][nn];
				if (l == nn) {
					wr[nn]=x+t;
					wi[nn--]=0.0;
				} else {
					y=a[nn-1][nn-1];
					w=a[nn][nn-1]*a[nn-1][nn];
					if (l == (nn-1)) {
						p=0.5*(y-x);
						q = p*p+w;
						z = sqrt(fabs(q));
						x += t;
						if (q >= 0.0) {
							z = p+SIGN(z,p);
							wr[nn-1]=wr[nn]=x+z;
							if (z) wr[nn]=x-w/z;
							wi[nn-1]=wi[nn]=0.0;
						} else {
							wr[nn-1]=wr[nn]=x+p;
							wi[nn-1]= -(wi[nn]=z);
						}
						nn -= 2;
					} else {
						if (its == 30) nrerror("Too many iterations in hqr");
						if (its == 10 || its ==20) {
							t += x;
							for (i=1;i<=nn;i++) a[i][i] -= x;
							s = fabs(a[nn][nn-1])+fabs(a[nn-1][nn-2]);
							y=x=0.75*s;
							w= -0.4375*s*s;
						}
						++its;
						for (m=(nn-2);m>=l;m--){
							z=a[m][m];
							r=x-z;
							s=y-z;
							s=y-z;
							p=(r*s-w)/a[m+1][m]+a[m][m+1];
							q=a[m+1][m+1]-z-r-s;
							r=a[m+2][m+1];
							s=fabs(p)+fabs(q)+fabs(r);
							p /= s; 
							q /= s;
							r /= s;
							if (m==1) break;
							u = fabs(a[m][m-1])*(fabs(q)+fabs(r));
							v = fabs(p)*(fabs(a[m-1][m-1])+fabs(z)+fabs(a[m+1][m+1]));
							if ((float)(u+v) == v) break;
						}
						for (i=m+2;i<=nn;i++) {
							a[i][i-2]=0.0;
							if (i != (m+2)) a[i][i-3]=0.0;
						}
						for (m=m;k<=nn-1;k++) {
							if (k != m) {
								p=a[k][k=1];
								q=a[k+1][k-1];
								r=0.0;
								if (k != (nn-1)) r=a[k+2][k-1];
								if ((x=fabs(p)+fabs(q)+fabs(r)) != 0.0) {
									p /=x;
									q /=x;
									r /= x;
								}
							}
							if ((s=SIGN(sqrt(p*p+q*q+r*r),p)) != 0.0) {
								if (k == m) {
									if (l != m)
									a[k][k-1] = -a[k][k-1];
								} else
									a[k][k-1] = -s*x;
								p += s;
								x = p/s;
								y = q/s;
								z = r/s;
								q /= p;
								r /= p;
								for (j=k; j<=nn;j++) {
									p=a[k][j]+q*a[k+1][j];
									if (k != (nn-1)) {
										p += r*a[k+2][j];
										a[k+2][j] -= p*z;
									}
									a[k+1][j] -= p*y;
									a[k][j] -= p*x;
								}
								mmin = nn<k+3 ? nn : k+3;
								for (i=l;i<=mmin;i++) {
									p=x*a[i][k]+y*a[i][k+1];
									if (k!= (nn-1)) {
										p += z*a[i][k+2];
										a[i][k+2] -= p*r;
									}
									a[i][k+1] -= p*q;
									a[i][k] -= p;
								}
							}
						}
					}
				}
			} while (l < nn-1);
		}
	}
		
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	