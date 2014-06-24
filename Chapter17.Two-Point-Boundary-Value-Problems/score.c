#include "Nrutil.h"
#define EPS 1.0e-6

extern int nvar;
extern float x1, x2;

int nvar;
extern float x1, x2;

int kmax, kount;
float *xp, **yp, dxsav;

void shoot(int n, float v[], float f[])
{
	void derivs(float x, float y[], float dydx[]);
	void load(float x1, float v[], float y[]);
	void odeint(float ystart[], int nvar, float x1, float x2,
		float eps, float h1, float hmin, int *nok, int *nbad,
		void(*derivs)(float, float[], float[]),
		void(*rkqs)(float[], float[], int, float *, float, float, 
			float[], float *, float *, void(*)(float, float[], float[])));
	void rkqs(float y[], float dydx[], int n, float *x,
		float htry, float eps, float yscal[], float *hdid, float *hnext,
		void(*derivs)(float, float[], float[]));
	void score(float xf, float y[], float f[]);
	int nbad, nok;
	float h1, hmin = 0.0, *y;

	y = vector(1, nvar);
	kmax = 0;
	h1 = (x2 - x1) / 100.0;
	load(x1, v, y);
	odeint(y, nvar, x1, x2, EPS, h1, hmin, &nok, &nbad, derivs, rkqs);
	score(x2, y, f);
	free_vector(y, 1, nvar);
}
