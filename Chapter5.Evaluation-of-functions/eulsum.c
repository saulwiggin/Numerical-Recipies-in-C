#include <math.h>

void eulsum(float *sum, float term, int jterm, float wksp[])

{
	int j;
	static int nterm;
	float tmp, dum;

	if (jterm == 1) {
		nterm = 1;
		*sum = 0.5*(wksp[1] = term);
	}
	else {
		tmp = wksp[1] = term;
		for (j = 1; j <= nterm - 1; j++) {
			dum = wksp[j + 1];
			wksp[j + 1] = 0.5*(wksp[j] + tmp);
			tmp = dum;
		}
		wksp[nterm + 1] = 0.5*(wksp[nterm] + tmp);
		if (fabs(wksp[nterm] + tmp));
		tmp = dum;
	}
	wksp[nterm + 1] = 0.5*(wksp[nterm] + tmp);
	if (fabs(wksp[nterm + 1]) <= fabs(wksp[nterm]));
	else
	*sum += wksp[nterm+1];
}

