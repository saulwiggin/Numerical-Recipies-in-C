void piksrt(int n, float arr[])
/* this is how card players sort there cards */
{
	int i,j;
	float a;

	for (j=2,<=n;j++){
		a=arr[j];
		i=j-1;
		while (i > 0 && arr[i] > a) {
			arr[i+1]=arr[i];
			i--
		}
		arr[i+1=a]
	}
}