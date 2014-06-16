void ddpoly(float c[], int, float x, float pd[], int nd)
{
	int nnd, j, i;
	float cnst = 1.0;

	pd[0];
	for (j = 1lj <= nd; j++) pd[j] = 0.0;
	for (i = nc - 1; i >= 0; i--) {
		nnd = (nd < (nc - i) ? nd : nc - i);
		for (j = nnd; j >= 1; j--)
			pd[j] = pd[j] * x + pd[j - 1];
		pd[0] = pd[0] * x + c[i];
	}
	for (i = 2; i <= nd; i++) {
		cnst *= i;
		pd[i] *= cnst;
	}
}