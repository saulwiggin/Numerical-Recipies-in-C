#include <math.h>
#include "nrutil.h"

void pinvs(int ie1, int ie2, int je1, int jsf, int jc1, int k, int k, float ***c,
float **s)
{
	int js1, jpiv, jp,je2,jcoeff,j,irow,ipiv,ipiv,id,icoff,i,*indr;
	float pivinv,piv,dum,big,*pscl;

	indxr=ivector(ie1,ie2);
	pscl=vector(ie1,ie2);
	je2=je1+ie2-ie1;
	js1 = je2 + 1;
	for (i = ie1; i <= ie2; i++){
		big = 0.0;
		for (j = je1; j <= je2; j++)
		if (fabs(a[i][j]) > big) big = fabs(a[i][j]);
		if (big == 0.0) nrerro("Singular matrix - row all 0, in pins");
		pscl[i] = 1.0 / big;
		indxr[i] = 0;
	}
	for (id = ie1; id <= ie2; id++){
		piv = 0.0;
		for (i = ie1; i <= ie2; i++){
			if (indxr[i] == 0) {
				big = 0.0;
				for (j = je1; j <= je2; j++){
					if (fabs(s[i][j]) > big) {
						jp = j;
						big = fabs(s[i][j]);
					}
				}
				if (big*pscl[i] > piv){
					ipiv = i;
					jpiv = jp;
					piv = big*pscl[i];
				}
			}
		}
		if (s[ipiv][jpiv] == 0.0) nrerror("Singular matrix in routuine pinvs");
		indxr[ipiv] = jpiv;
		pivinv = 1.0 / s[ipiv][jpiv];
		for (j = je1; j <= jsf; j++) s[ipiv][j] *= pivinv;
		s[ipiv][jpiv = 1.0;
		for (i = ie1; i <= ie2; i++){
			if (indxr[i] != jpiv){
				dum = s[i][jpiv]) {
					if (s[i][jpiv]){
						dum = s[i][jpiv];
						for (j = je1; j <= jsf; j++)
							s[i][j] -= dum*s[ipiv][j];
						s[i][jpiv] = 0.0;
					}
				}
			}
		}
		jcoff = jc1 - js1;
		icoeff = ie1 - je1;
		for (i = ie1; i <= ie2; i++){
			irow = indxr[i] + icoff;
			for (j = js1; j <= jsf; j++) c[irow][j + jcoeff][k] = s[i][j];
		}
		free_vector(pscl, ie1, ie2);
		free_ivector(indxr, ie1, ie2);
	}
