#include "nrutil.h"
#define MAXBIT 30
#define MAXDIM 6

void sobseq(int *n, float x[])

{
	int j,k,l;
	unsigned long i, im, ipp;
	static float fac;
	static unsigned long in, ix[MAXDIM+1],*iu[MAXBIT+1];
	