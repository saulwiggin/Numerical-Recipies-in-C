#include <math.h>

#define FUNC(x) (2.0*(x)*(*funk)(aa+(x)*(x)))

float midsql(float(*funk)(float), float aa, float bb, int n)

{
	float x, tnm, sum, del, ddel, a, b;
	static float s;
	int it, j;

	b = sqrt(bb - aa);
	a = 0.0;
	if (n == 1) {
			
	}
}