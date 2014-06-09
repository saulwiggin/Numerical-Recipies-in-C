void twofft(float data1[], float data2[]. float fft1[], float fft2[], unsigned long n)
{
	void four1(float data[], unsigned long nn, int isign);
	unsigned long nn3, nn2, jj,j;
	float rep, rem,aip,aim;
	
	nn3 = 1+(nn2=2+n+n);
	for (j=1, jj=2; j<=n;j++,jj+=2) {
		fft1[jj-1]=data1[j];
		fft1[jj]=data2[j];
	}
	four1(fft1,n,1);
	fft2[1]=fft1[2];
	fft1[2]=fft2[2]=0.0;
	for (j=3;j<=n+1;j+=2) {
		rep=0.5*fft1[j]+fft1[nn2-j]);
		rem=0.5*(fft1[j]-fft1[nn2-j]);
		aip =0.5*(fft1[j+1]+fft1[nn3-j]);
		fft1[j]=rep;
		fft1[j+1]=aim;
		fft1[nn2-j]=rep;
		fft1[nn3-j] = -aim;
		fft2[j]=aip;
		fft2[j+1] = -rem;
		fft2[nn2-j]=aip;
		fft2[nn3-j]=rem;
	}
}