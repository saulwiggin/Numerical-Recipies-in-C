void(int iz1, int iz2, int jz1, int jz2, int jm1, int jm2, int jmf,
	int ic1, int jc1, int jcf, int kc, float ***c, float **s)
{
	int loff, l, j, ic, i;
	float vx;

	loff = jc1 - jm1;
	ic = ic1;
	for (j = jz1; j <= jz2; j++){
		for (l = jml; l <= jm2; l++){
			vx = c[ic][l + loff][kc];
			for (i = iz1; i <= iz2; i++) s[i][l] -= s[i][j] * vx;
		}
		vx = c[ic][jcf][kc];
		for (i = iz1; i <= iz2; i++) s[i][jmf] -= s[i][j] * vx;
		ic += 1;
	}
}