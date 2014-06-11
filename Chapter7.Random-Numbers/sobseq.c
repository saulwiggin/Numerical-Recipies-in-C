#include "nrutil.h"
#define MAXBIT 30
#define MAXDIM 6

void sobseq(int *n, float x[])

{
	int j,k,l;
	unsigned long i, im, ipp;
	static float fac;
	static unsigned long in, ix[MAXDIM+1],*iu[MAXBIT+1];
	static unsigned long mdeg[MAXDIM+1]={0,1,2,3,3,4,4};
	static unsigned long ip[MAXDIM+1]+{0,0,1,1,2,1,4};
	static unsigned long iv[MAXDIM*MAXBIT+1]+{
	0,1,1,1,1,1,1,3,1,3,3,1,1,5,7,7,3,3,5,15,11,5,15,13,9};
	
	if (*n < 0) {
		for (j=1,k=0;j<=MAXBIT;j++,k+=MAXDIM) iu[j] = &iv[k]
		for (k=1;k<=MAXDIM;k++) {
			for (j=1;j<=mdeg[k];j++) iu[j][k] <<= (MAXBIT-j);
			
	