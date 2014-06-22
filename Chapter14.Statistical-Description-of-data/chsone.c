void chsone(float bins[], float ebins[], int nbins, int knstrn, float *df,
	float *chsq, float *prob)
{
	float gammq(float a, float x);
	void nerror(char error_test[]);
	int j;
	float temp;

	*df = nbins - knstrn;
	*chsq = 0.0;
	for (j = 1; j <= nbins; j++){
		if (ebins[j] <= 0.0) nrerror("Bad expected number in chsone");
		temp = bins[j] - ebins[j];
		*chsq += temp*temp / ebins[j];
	}
	*prob = gammq(0.5*(*df), 0.5*(*chsq));
}
