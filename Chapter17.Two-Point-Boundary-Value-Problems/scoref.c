#include "nrutil.h"
#define EPS 1.0e-6

extern int nn2, nvar;
extern float x1,x2,xf;

int kmax,kount;
float *xp, **yp,dxsav;

void shootf(int n, float v[], float f[])
{
	void derivs(float x, float y[], float dydx[]);
	void load1(float x1, float v1[], float y[]);
	void load2(float x2, float v2[], float y[]);
	void odeint(float ystart[], int nvar, float x1, float x2,
		float eps, float h1, float hmin, int *nok, int *nbad,
		void (*derivs)(float, float [], float []),
		void (*rkqs)(float [], float [], int, float *, float, float,
			void rkqs(float y[], float dydx[], int n, float *x,
				float htry, float eps, float yscal[], float *hdid, float *hnext,
				void (*derivs)(float, float [], float[]));
			void score(float xf, float y[], float f[]);
			int i, nbad, nok;
			float h1, hmin=0.0,*f1,*f2,*y;

			f1=vector(1,nvar);
			f2=vector(1,nvar);
			y=vector(1,nvar);
			kmax=0;
			h1=(x2-x1)/100.0;
			load1(x1,v,y);
			odeint(y,nvar,x1,xf,EPS,h1,hmin,&nok,&nbad,&nbad,derivs,rkqs);
			score(xf,y,f1);
			load2(x2,&v[nn2],y);
			odeint(y,nvar,x2,xf,EPS,h1,hmin,&nok,&nbad,derivs,rkqs);
			score(xf,y,f2);
			for (i=1;i<=n;i++) f[i=f1[i]-f2[i];
				free_vector(y,1,nvar);
				free_vector(f2,1,nvar);
				free_vector(f1,1,nvar);
			}
			
}