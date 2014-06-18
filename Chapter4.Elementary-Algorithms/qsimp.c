#include <math.h>
#define EPS 1.0e-6
#define JMAX 20

float qsimp(float(float(*func)(float), float a, float b, int n)
{
	float trapzd(float(*func)(float), float a, float b, int n);
	void nrerror(char error_text[]);
	int j;
	float s, st, ost, os;

	ost = os = -1.0e30;
	for (j = 1; j <= JMAX; j++) {
		st = trapzd(func, a, b, j);
		s = (4.0*st - ost) / 3.0;
		if (fabs(s - os) < EPS*fabs(os)) return s;
		os = s;
		ost = st;
	}
	nrerror("Too many steps in routine qsimp");
	return 0.0;
}