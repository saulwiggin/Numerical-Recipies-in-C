#include <stdio.h>
#include <math.h>
#include "nrutil.h"

void solvde(int itmax, float conv,float slowc, float scalv[], int indexv[],
int ne, int nb, int m, float **y, float ***c, float **s)
{
	void bksub(int ne, int nb, int jf, int k1, int k2, float ***c);
	void difeq(int k, int k1, int k2, int jsf, int is1, int isf,
		int indexv[], int ne, float **s, float **y);
	void pinvs(int ie1, int ie2, int je1, int jsf, int jc1, int k,
		float **c, float **s);
	void red(int iz1, int iz2, int jz1, int jz2, int jm1, int jm2, int jmf,
		int ic1, int jc1, int jcf, int kc, float ***c, float **s);
	int ic1,ic2, ic3,ic4,it,j,j1,j2,j3,j4,j5,j6,j7,j8,j9;
	int jc1, jcf, jv, k, k1, k2, km, kp,nvars, *kmax;
	float err, errj, fac, vmax, vz,*ermax;

	kmax=ivector(1,ne);
	ermax=vector(1,ne);
	k1=1;
	k2=m;
	nvars=ne*m;
	j1=1;j2=nb;
	j3=nb+1;
	j4=ne;
	j5=j4+j1;
	j6=j4+j2;
	j7=j4+j3;
	j8=j4+j4;
	j9=j8+j1;
	ic1=1;
	ic2=ne-nb;
	ic3=ic2+1;
	ic4=ne;
	jc1=1;
	jcf=ic3;
	for (it=1;it<=itmax;it++){
		k=k1;
		difeq(k,k1,k2,j9,ic3,ic4,indexv,ne,s,y);
		pinvs(ic3,ic4,j5,j9,jc1,k1,c,s);
		for (k=k1+1;k<=k2;k++){
			kp=k-1;
			difeq(k,k1,k2,j9,ic1,ic4,indexv,ne,s,y);
			red(ic1,ic4,j1,j2,j3,j4,j9,ic3,jc1,jcf,kp,c,s);
			pinvs(ic1,ic4,j3,j9,jc1,k,c,s);
		}
		k=k2+1;
		difeq(k,k1,k2,j9,ic1,ic2,indexv,ne,s,y);
		red(ic1,ic2,j5,j6,j7,j8,j9,ic3,jc1,jcf,k2,c,s);
		pinvs(ic1,ic2,j7,j9,jcf,k2+1,c,s);
		bksub(ne,nb,jcf,k1,k2,c);
		err=0.0;
		for(j=1;j<=ne;j++){
			jv=indexv[j];
			errj=vmax=0.0;
			km=0;
			for (k=k1;k<=k2;k++){
				vz=fabs(c[jv][1][k]);
				if (vz > vmax) {
					vmax=vz;
					km=k;
				}
				errj += vz;
			}
			err += errj/scalv[j];
			ermax[j]=c[jv][1][km]/scalv[j];
			kmax[j]=km;
		}
		err /= nvars;
		fac = (err > slowc ? slowc/err : 1.0);
		for (j=1;j<=ne;j++){
			jv=indexv[j];
			for(k=k1;k<=k2;k++)
				y[j][k] -= fac*c[jv][1][k];
		}
		printf("\n%8s %9s %9s\n","Iter.","Error","FAC");
		printf("%6d %12.6f %11.6f\n",it,err,fac);
		if (err < conv){
			free_vector(ermax,1,ne);
			free_ivector(kmax,1,ne);
			return;
		}
	}
	nrerror("Too many itterations in silvde");
}


		}
		}
				}
			}
		}
		}
	}
	