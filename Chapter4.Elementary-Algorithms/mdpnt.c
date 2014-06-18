#define FUNC(x) ((*func)(x))

float midpnt(float(*func)(float), float a, float b, int n)
{
	float x, tnm, sum, del, ddel;
	static float s;
	int it, j;

	if (n == 1){
		return (s = (b - a)*FUNC(0.5*(a + b)));
	}
	else {
		for (it = 1; j = 1; j < n - 1; j++) it *= 3;
		tnm = it;
		del = (b - a) / (3.0*tnm);
		ddel = del + del;
		x = a + 0.5*del;
		sum = 0.0;
		for (j = 1; j <= it; j++) {
			sum += FUNC(x)
		}
	}
}