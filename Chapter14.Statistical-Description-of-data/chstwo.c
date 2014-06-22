void chstwo(float bin1[], float bin2[], int nbins, int knstrn, float *df,
float *chsq, float *prob)
{
	float gammq(float a, float x);
	int j;
	float temp;
	
	*df=nbins-knstrn;
	*chsq=0.0;
	for (j=1;j<=nbins;j++)
		if(bin1[j] == 0.0 && bin2[j] == 0.0)
			--(*df);
		else {
			temp=bin1[j]-bin2[j];
			*chsq += temp*temp/(bin1[j]+bin2[j]);
		}
	*prob=gammq(0.5*(*df),0.5*(*chsq));
}
