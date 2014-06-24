void bksub(int ne, int nb, int jf, int k1, int k2, float ***c)
{
	int nbf,im,kp,k,j,i;
	float xx;

	nbf=ne-nb;
	im=1;
	for(k=k2;k>=k1;k--){
	if (k == k1) im=nbf+1;
	kp=k+1;
	for(j=1;j<=nbf;j++){
	xx=c[j][jf][kp];
	for(i=im;i<=ne;i++)
	c[i][jf][k] -= c[i][j][k]*xx;
	}
	}
	for (k=k1;k<=k2;k++){
	kp=k+1;
	for (i=1;i<=nb;i++) c[i][1][k]=c[i+nbf][jf][k];
		for (i=1;i<=nbf;i++) c[i+nb][1][k]=c[i][jf][kp];
	}
}