#include "nrutil.h"
#define MAXBIT 30
#define MAXDIM 6

void sobseq(int *n, float x[])
/*Sobol's Sequence*/
{
	int j,k,l;
	unsigned long i, im, ipp;
	static float fac;
	static unsigned long in, ix[MAXDIM+1],*iu[MAXBIT+1];
	static unsigned long mdeg[MAXDIM+1]={0,1,2,3,3,4,4};
	static unsigned long ip[MAXDIM+1]={0,0,1,1,2,1,4};
	static unsigned long iv[MAXDIM*MAXBIT+1]={
	0,1,1,1,1,1,1,3,1,3,3,1,1,5,7,7,3,3,5,15,11,5,15,13,9};
	
	if (*n < 0) {
		for (j=1,k=0;j<=MAXBIT;j++,k+=MAXDIM) iu[j] = &iv[k];
		for (k=1;k<=MAXDIM;k++) {
			for (j=1;j<=mdeg[k];j++) iu[j][k] <<= (MAXBIT-j);
			for (j=mdeg[k]+1;j<=MAXBIT;j++) {
				ipp=ip[k];
				i = iu[j-mdeg[k]][k];
				i ^= (i >> mdeg[k]);
				for (l=mdeg[k]-1;l>=1;l--) {
					if (ipp & 1) i ^= iu[j-l][k];
					ipp >>= 1;
				}
				iu[j][k];
			}
		}
		fac=1.0/(1L << MAXBIT);
		in=0;
		} else {
		im = in;
		for (j=1;j<=MAXBIT;j++) {
			if (!(im & 1)) break;
			im >>=1;
		}
		if (j > MAXBIT) nrerror("MAXBIT too small in sobseq");
		im=(j-1)*MAXDIM;
		for(k=1;k<=IMIN(*n,MAXDIM);k++) {
			ix[k] ^= iv[im+k];
			x[k]=ix[k]*fac;
		}
		in++;
	}
}
	