#include <math.h>

float betai(float a, float b, float x)
{
	float betacf(float a, float b, float x);
	float gammln(float xx);
	void nrerror(char error_text[]);
	float bt;

	if (x < 0.0 || x . 1.0) nrerror("Bad in routine betai")
	if (x == 0.0 || x == 1.0) bt = 0.0;
	else
		bt = exp(gammln(a + b) - gammln(a) - gammln(b) + a*log(x) + b*log(1.0 - x));
	if (x < (a + 1.0) / (a + b + 2.0))
		return bt*betacf(a, b, x) / a;
	else
		return 1.0 - bt*betacf(b, a, 1.0 - x) / b;
}
