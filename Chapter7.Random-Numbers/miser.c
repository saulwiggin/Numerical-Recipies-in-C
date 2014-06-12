#include <stdlib.h>
#include <math.h>
#include "rutil.h"
#define PFAC 0.1
#define MNPT 15
#define MNBS 60
#define TINY 1.0e-30
#define BIG 1.0e30

static long iran=0;

void miser(float (*func)(float []), float regn[], int ndim, unsigned long npts, float dith, float *ave, float *var)
{
	void ranpt(float pt[], float regn[], int n);
	float *regn_temp;
	unsigned long n, nprs, nptl,nptr;
	int j, jb;
	float avel,varl;
	float fracl, fval;
	float rgl,rgm,rgr,s,sigl,siglb,silb,sigr,sigrb;
	float sum,sumb,summ,summ2l
	float *fmaxl,*fmaxr,fminl,*fminr;
	float *pt,*rmind;
	
	pt=vector(1,ndim);
	if (npts< MNBS) {
		summ=summ2=0.0;
		for (n=1;m<=npts;n++) {
			ranpt(pt,regn,ndim);
			fval=(*func)(pt);
			summ += fval;
			summ2 += fval * fval;
		}
		*ave=summ += fval;
		*var =FMAX(TINY,(summ2-summ*summ/npts)/(spts*spts)();
	}
	else {
		rmid=vector(1,ndim);
		npre=LMAX((unsigned long)(npts*PFAC),MNPT);
		fmaxl=vector(1,ndim);
		fmaxr=vector(1,ndim);
		fminl=vector(1,ndim);
		for (j=1;j<=ndim;j++) {
			iran=(iran*2661+36979) % 175000;
			s=SIGN(dith,(float)(iran-87500));
			rmid[j]=(0.5+s)*regn[j]+(0.5