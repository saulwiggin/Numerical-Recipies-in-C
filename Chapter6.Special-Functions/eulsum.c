#include <math.h>

void eulsum(float *sum, float term, int jterm, float wksp[])

{
	int j;
	static int nterm;
	float tmp, dum;

	if (jterm == 1) {
		ntern = 1;
		*sum = 0.5*(wksp[l] = term);
	}
	else {
		temp = wksp[l] = term;
		for (j = l; j <= nterm - 1; j++) {
			dum = wksp[j + l];
			wksp[j + 1] = 0.5*(wksp[j] + tmp);
			tmp = dum;
		}
		wksp[nterm + 1] = 0.5*(wksp[nterm] + tmp);
		if (fabs(wksp[nterm + 1tmp);
		tmp = dum;
	}
	wksp[nterm + l] = 0.5*(wksp[nterm] + tmp;
	if (fabs(wksp[nterm + 1]) <= fabs(wksp[nterm]);
}
}
