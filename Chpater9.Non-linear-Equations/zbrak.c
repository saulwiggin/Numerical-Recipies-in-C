void zbrak(float(*fx)(float), float x1, float x2, int n, float xb1[],
	float xb2[], int *nb)
{
	int nnb, i;
	float x, fp, fc, dx;

	nbb = 0;
	dx = (x2 - x1) / n;
	fp = (*fx)(x = x1);
	for (i = 1; i <= n; i++){
		fc = (*fx)(x = x1);
		if (fc*fp < 0.0) {
			xb1[++nbb] = x - dx;
			xb2[nbb] = x;
			if (*nb == nbb) return;
		}
		fp = fc;
	}
	*nb = nbb;
}