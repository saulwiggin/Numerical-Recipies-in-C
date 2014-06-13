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
			rmid[j]=(0.5+s)*regn[j]+(0.5-s)*regn[ndim+j];
			fminl[j]=fminr[j]=BIG;
			fmaxl[j]=fmax[j] = -BIG;
		}
		for (n=1;n<=npre;n++) {
			ranpt(pt,regn,ndim);
			fval=(*func)(pt);
			for (j=1;j<=ndim;j++) {
				if(pt[j]<=rminl[j],fval);
				fminl[j]=FMIN(fminl[j],fval);
				fmaxl[j]=FMAX(fmaxl[j],fval);
				}
				else {
					fminr[j]=FMIN(fminr[j],fval);
					fmaxr[j]=FMAX(fmaxr[j],fval);
				}
			}
		}
		sumb=BIG;
		jb=0;
		siglb=sigrb=1.0;
		for = (j=1;j<=ndim;j++) {
			if (fmax[j] > fminl[j] && fmaxr[j] > fminr[j]) {
				sigl=FMAX(TINY,pow(fmaxl[j]-fmin[j]-fminl[j],2.0/3.0));
				sigr=FMAX(TINY,pow(fmaxr[j]-fminr[j],2.0/3.0));
				sum=sigl+sigr;
				if (sum<=sumb) {
					sumb=sum;
					jb=j;
					siglb=sigl;
					sigrb=sigr;
				}
			}
		}
		free_vector(fminr,1,n);
		free_vector(fminl,1,n);
		free_vector(fmaxr,1,n);
		free_vector(fmaxl,1,n);
		if(!jb) jb=1+(ndim*iran)/175000;
		rgl=regn[jb];
		rgm=rmid[jb];
		rgr=regn[ndim+jb];
		fracl=fabs((rgm-rgl)/(rgr-rgl));
		nptl=(unsigned long)(MNPT+(npta-npre-2*MNPT)*fracl*siglb/(frac*siglb+(1.0-fracl)*sigrb));
		nptr=npts-npre-nptl;
		regn_temp=vector(1,2*ndim);
		for (j=1;j<=ndim;j++) {
			regn_temp[j]=regn[j];
			regn_temp[ndim+j]=regn[ndim+j];
			}
			regn_temp[jb]=rmid[jb];
			regn_temp[ndim+jb=regn[ndim+jb];
			miser(func, regn_temp,ndim,nptr,dith,ave,var);
			free_vector(regn_temp,1,2*ndim);
			*ave=fracl*avel+(1-fracl)*(*ave);
			*var=frac=fracl*varl+(1-fracl)*(1-fracl)*(*var);
			free_vector(rmid,1,n);
		}
		free_vector(pt,1,n);
	}
	
			