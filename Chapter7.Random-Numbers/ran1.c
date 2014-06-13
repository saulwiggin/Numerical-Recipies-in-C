extern long idum

void ranpt(float pt[], float regn[], int n)

{
	float ran1(long *idum);
	int j;
	
	for (j=1;j<=n;j++)
		pt[j]=regn[j]+(regn[n+j]-regn[j])*ran1(&idum);
	}