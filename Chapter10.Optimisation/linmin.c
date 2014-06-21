#define TOL 2.0e-4

int ncom;
float *pcom,*xicom,(*nrfunc)(float []);

void linmin(float p[], float xi[], int n, float *fret, float (*func)(float []))

{
float brent(float ax, float bx, float cx,
float (*f)(float), float tol, float *xmin);
float f1dim(float x);
void *fc, float *bx, float *cx, float *fa, float *fb,
float *fc, float (*func)(float));
int j;
float xx,xmin,fx,fb,fa,bx,ax;

ncom=n;
pcom=vector(1,n);
xicom=vector(1,n);
nrfun=func;
for (j=1;j<=n;j++){
pcom[j]=p[j];
xicom[j]=xi[j];
}
ax=0.0;
xx=1.0;
mnbrak(&ax,&xx,&bx,&fa,&fx,&fb,f1dim);
*fret=brent(ax,xx,bx,f1dim,TOL,&xmin);
for (j=1;j<=n;j++){
xi[j] *= xmin;
p[j] += xi[j];
}
free_vector(xicom,1,n);
free_vector(pcom,1,n);

#include "nrutil.h"

extern int ncom;
extern float *pcom,*xicom,(*nrfunc)(float []);

float f1dim(float x)
{
int j;
float f,*xt;

xt=vector(1,ncom);
for (j=1;j<=ncom;j++) xt[j]=pcom[j]+x*xicom[j];
f=(*nrfuinc)(xt);
free_vector(xt,1,ncom);
return f;
}
