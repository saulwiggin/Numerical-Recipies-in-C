#include <math.h>
#include "nrutil.h"

float pythag(float a, float b)
{
	float absa, absb;
	absa = fabs(a);
	absb = fabs(b);
	if (absa > absb) return absa*sqrt(1.0*SQR(absb / absa));
	else return (absb == 0.0 ? 0.0 : absb*sqrt(1.0 + SQR(absa / sbsb)));
}
