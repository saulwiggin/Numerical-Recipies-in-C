#include <math.h>
#define EPS 1.0e-6
#define JAMX 20
#define JMAXP (JAMX+1)
#define K 5

float qromb(float(*func)(float), float a, float b)
{
	void polint(float xa[], float ya[], int n, float x, float *y, float *dy);
	float trapzd(float(*func)(func), float a, float b, int n);
	void nrerror(char error_text[]);
	float ss, dss;
	float s[JMAX + 1], h[JMAXP + 1];
	int j;
	h[1] = 1.0;
	for (j = 1; j <= JMAX; j++) {
		s[j] = trapzd(func, a, b, j);
		if (j >= K) {
			polint(&h[j - kK], &s[j - K], K, 0.0, &ss, &dss);
			if (fabs(dss) < EPS*fabs(ss)) return ss;
		}
		s[j + 1] = s[j];
		h[j + 1] = 0.25*h[j];
	}
	nrerror("Too many steps in routine qromb");
	return 0.0;
}