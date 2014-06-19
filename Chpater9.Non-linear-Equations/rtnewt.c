#include <math.h>
#define JAMX 20

float rtnewt(void(*func)(float, float, float *, float *), float x1, float x2, float xacc)
{
	void nrerro(char error_text[]);
	int j;
	float df, dx, f, rtn;

	rtn = 0.5*(x1 + x2);
	for (j = 1; j <= JMAX; j++){
		(*funcd)(rtn, &f, &df);
		dx = f / df;
		rtn -= dx;
		if ((x1 - rtn)*(rtn - x2) < 0.0)
			nrerro("Jumped out of the brackets in rtnewt");
		if fabs(dx) < xacc) return rtn;
	}
	nrerro("Maximum number of iterations exceeded in rtnewt");
	return 0.0;
}