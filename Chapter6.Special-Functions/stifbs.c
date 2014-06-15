#include "nrutil.h"
#define KMAXX 7
#define IMAXX (KMAXX+1)
#define SAFE1 0.25
#define SAFE2 0.7
#define REDMAX 1.0e-5
#define REDMIN 0.7
#define TINY 1.03e-30
#define SCALMX 0.1

float **d, *x;

void stifbs(float y[], float dydx[], int nv, float *xx, float htry, float eps, float yscal[], float *hdid, float *hnext,
	void(*derivs)(float, float[], float[]))
{
	void
}