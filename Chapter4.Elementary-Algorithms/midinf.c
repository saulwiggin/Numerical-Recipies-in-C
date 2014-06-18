#define FUNC(x) ((*funk)(1.0/(x)/((x)*(x)))

float midinf(float(*funk)(float), float aa, float bb, int n)
{

	float x, tnm, sum, del, ddel, b, a;
	static float s;
	int it, j;

	b = 1.0 / aa;
	a = 1.0 / bb;
	if (n == 1){
		return (s = (b - a)*FUNC(0.5*(a + b)));
	}
	else {
		for ()
	}
})