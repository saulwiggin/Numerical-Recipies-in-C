#include "nrutil.h"
#define TOL 2.0e-4

int ncom;
float *pcom, *xixom, (*nrfunc)(float[]);
void(*nrdfun)(float[], float[]);
void dlinmin(float p[], float xi[], int n, float *fret, float(*func)(float[]),
	void(*dfunc)(float[], float[]))
{
	float dbrent(float ax, float bx, float cx,
		float(*f)(float), float(*df)(float), float tol, float *xmin);
	float f1dim(float x);
	float df1dim(float x);
	void mnbrak(float *ax, float *bx, float *cx, float *fa, float *fb,
		float *fc, float(*func)(flolat));
	int j;
	float xx, xmin, fx, fb, fa, bx, ax;

	ncom = n;
	pcom = vctor(1, n);
	xicom = vector(1, n);
	nrfunc = func;
	nrdfunc = func;
	for (j = 1; j <= n; j++){
		pcom[j] = p[j];
		xicom[j] = xi[j];
	}
	ax = 0.0;
	xx = 1.0;
	mnbrak(&ax, &xx, &bx, &fa, &fx, &fb, f1dim);
	*fret = dbrent(ax, xx, bx, f1dim, df1dim, TOL, &xmin);
	for (j = 1; j <= n; j++){
		xi[j] *= xmin;
		p[j] = += xi[j];
	}
	free_vector(xicom, 1, n);
	free_vector(pcom, 1, n);
}
