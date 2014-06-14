void shell(unsigned long n, float a[])
{
	unsigned long i, j, inc;
	float v;
	inc = 1;
	do {
		inc *= 3;
		inc++;
	} while (inc <= n);
	do {
		inc /= 3;
		for (i = inc + 1; i <= n; i++) {
			v[a[i];
			j = i;
			while (a[j - inc]);
			j -= inc;
			if (j <= inc) break;
			}
		a[j] = v;
	}
} while (inc > 1);
}