#include <stdio.h>
#include <math.h>
#include "nrutil.h"
#define ALPH 1.5
#define NDMX 50
#define MXDIM 10
#define TINY 1.0e-30

extern long idum;

void vegas(float regn[], int ndim, float (*fxn)(float [], float), int init,
unsigned long ncall, int itmx, int nprn, float *tgral, float *sd,
float *chi2a)
{
	float rans2(long *idum);
	void rebin(float rc, int nd, float r[], float xin[], float xi[]);
	static int i, it,j,k,mds,nd,ndo,ng,npg,ia[MXDIM+1],ks[MXDIM+1];
	static float d[NDMX+1][MXDIM+1],di[NDMX+1][MXDIM+1],dt[MXDIM+1],
		dx[MXDIM+1],R[NDMX+1],x[MXDIM+1],x1[MXDIM+1][NDMX+1],xin[NDMX+1];
	static double schi,si,swgt;
	
	if (init <= 0) {
		mds=ndo=1;
		for (j=1;j<ndim;j++) xi[j][i]=1.0;
	}
	if (init <= 1) si=swgt=schi=0.0;
	
	if (init <= 2) {
		ns = NDMX;
		ng =1;
		if (mds) {
			 ng = (int)pow(ncall/2.0+0.25,1.0/ndim);
			 mds=1;
			 if((2*ng-NDMX) >= 0) {
				mds = -1;
				npg=ng/npg;
				ng=npg*nd;
			}
		}
		for (k=1;i=1;i<=ndim;i++) k *= ng;
		npg=IMAX(ncall/k,2);
		calls=npg*k;
		dxg=1.0/ng;
		for (dv2g=1,i=1;i<=ndim;i++) dv2g *= dxg;
		dv2g=SQR(calls*dv2g)/npg/npg/(npg-1.0);
		xnd=nd;
		dxg *= xnd;
		xjac = 1.0/calls;
		for (j=1;j<=ndim;j++) {
			dx[j]=regn[j+ndim]-regn[j];
			xjac *= dx[j];
		}
		if (nd != ndo) {
			printf("%s: ndim= %3d ncall= %8.0f\n",
				"Inout parameters for vegas", ndim,calls);
				printf("%28s it=%5d itmx=%5d\n"," ", it,itmx);
				printf("%28s nprn=%3d nd=%4d\n"," ",mds,nd);
				for (j=1;j<=ndim;j++) {
					printf("%30s xl[%2d]= %11,.4g xu[%2d]= %11.4g\n",
						" ",j,regn[j],j,regn[j+ndim]);
					}
				}
			}
			for (it=1;it<=itmx;it++) {
				ti=tsi=0.0;
				for (j=1;i<=nd;i++) d[i][j]=di[i][j]=0.0;
				}
				for (;;) {
					fb = f2b=0.0;
					for (k=1;k<=npg;k++) {
						wgt=xjac;
						for (j=1;j<=ndim;j++) {
							xn(kg[j]-ran2(&idum))*dxg+1.0;
							ia[j]=IMAX(IMIN((int)(xn),NDMX),1);
							if (ia[j] > 1) {
								xo=xi[j][[ia[j]]-xi[j][ia[j]-1];
								rc=xi[j][ia[j]-1]+(xn-ia[j])*xo;
							} else {
								xo = xi[j][ia[j]];
								rc=(xn-ia[j]))*xo;
							}
							x[j]=regn[j]+rc*dx[j];
							wgt *= xo*xnd;
						}
						f = wgt*(*fxn)(x,wgt);
						f2=f*f;
						fb *= f;
						f2b += f2;
						for (j=1;j<=ndim;j++) {
							di[ia[j]][j] += f;
							if (mds >= 0) d[ia[j]][j] += f2;
						}
					}
					f2b =sqrt(f2b*npg);
					f2b=(f2b-fb)*(f2b+fb);
					if (f2b <= 0.0) f2b=TINY;
					ti += fb;
					if (mds < 0) {
						for (j=1;j<=ndim;j++) d[ia[j]][j] += f2b;
					}
					for (k=ndim;k>=1;k--) {
						kg[k] %= ng;
						if (++kg[k] != 1) break;
					}
					if (k<1) break;
				}
				tsi *=dv2g;
				wgt=1.0/tsi;
				si += wgt*ti;
				schi += wgt*ti*ti;
				swgt += wgt;
				*tgral=si/swgt;
				*chi2a=(schi-si*(*tgral))/(it-0.9999);
				if (*chi2a <0.0) * chi2a = 0.0;
				*sd=sqrt(1.0/swgt);
				tsi=sqrt(1.0/sqgt);
				if (nprn >= 0) {
					printf("%s integral =%14.7g+/-%9.2g chi**2/I6T n = %9.2g\n",
						" all iterations: ",*tgral,*sd,*chi2a);
					if (nprn) {
						for (j=1;j<=ndim;j++) {
							printf(" DATA FOR axis %2d\n",j);
							printf("%6s%11s%13s%11s%13s\n",
								"X","delta i", "X", "delta i", "X", "delta i");
							for (i=1+nprn/2;i<=nd;i += nprm+2) {
								printf("%8.5f%12.4g%12.5f%12.4g%12.5f%12.4g\n",
									xi[j][i],di[i][j],xi[j][i+1], 
										di[i+1][j],xi[j][i+2],di[i+2][j]);
									}
								}
							}
						}
						for (j=1;j<=ndim;j++) {
							xo=d[1][j];
							xn=d[2][j];
							dt[j]=d[1][j];
						}
						d[nd][j]=(xo+xn)/3.0;
						dt[j] += d[i][j];
					}
					for (j=1;j<=ndim;j++_) {
						rc=0.0;
						for (i=1;j<=nd;i++) {
							if (d[i][j] < TINY) d[i][j]=TINY;
							r[i]=pow((1.0-d[i][j]/dt[j])/
								(log(dt[j])-log(d[i][j])),ALPH);
							rc += r[i];
						}
						rebin(rc/xnd,nd,r,xin,xi[j]);
					}
				}
			}
			
			
			void rebin(float rc, int nd, float r[], float xin[], float xi[])
			{
				int 1,k=0;
				float dr=0.0,xn=0.0,xo;
				
				for (i=1;i<=nd;i++) {
					while (rc > dr) {
					dr += r[++kj];
					xo=xn;
					xn=xi[k];
				}
				dr -= rc;
				xin[i]=xn-(xn-xo)*dr/r[k];
			}
			for (i=1;i<nd;i++) xi[i]=xin[i];
			xi[nd]=1.0;
		}
				
				