#include <stdio.h>#include <math.h>
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
	void rebin()(float rc, int nd, float r[], float xin[], float xi[]);
	static int i, it,j,k,mds,nd,ndo,ng,npg,ia[MXDIM+1],ks[MXDIM+1];
	static float d[NDMX+1][MXDIM+1,di[NDMX+1][MXDIM+1],dt[MXDIM+1],
		dx[MXDIM+1],R[NDMX+1],x[MXDIM+1],x1[MXDIM+1][NDMX+1],xin[NDMX+1];
	static double schi,si,swgt;
	
	if (inti <= 0) {
		mda=ndo=1;
		for (j=1;j<ndim;j++) xi[j][1]=1.0;
		