void avevar(float data[], unsigned long n, float *ave, float *var)
{
	unsigned long j;
	float s, ep;

	for (*ave = 0.0, j = 1; j <= n; j++) *ave += data[j];
	*ave /= n;
	*var = ep = 0.0;
	for (j = 1; j <= n; j++) {
		s = data[j] - (*ave);
		ep += s;
		*var += s*s;
	}
	*var = (*var - ep*ep / n) / (n - 1);
}
