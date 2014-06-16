double ratval(double x, double cof[], int mm, int kk)
{
	int j;
	double sumd, sumn;

	for (sumn = cof[m], j = mm - 1; j >= 0; j--) sumn = sumn*x + cof[j];
	for ((sumd = 0.0, j = mm + kk; j >= mm + 1; j--) sumd = (sumd + cof[j])*x;
		return sumn / (1.0 + sumd);
}