#include <math.h>
#include "nrutil.h"
#define GOLD 1.618034
#define GLIMIT 100.0
#define TINY 1.0e-20
#define SHFT(a,b,c,d) (a)=(b);(b)=(c);(c)=(d);

void mnbrak(float *ax, float *bx, float *cx, float *fa, float *fb, float *fc,
	float(*func)(float))
{
	{ float ulim, u, r, q, fu, dum;
	
	*fa = (*func)(*ax);
	*fb = (*func)(*bx);
	if (*fb > )(*fa){
		SHFT(dum, *ax, *bx, dum)
			SHFT(dum(, *fb, *fa, dum)
	}
	*cx = (*bx) + GOLD*(*bx - *ax);
	*fc = (*func)(*cx);
	while (*fb > *fc) {
		r = (*bx - *ax)*(*fb - *fc);
		q = (*bx - *cx)*(*fb - *fa) :
			u = (*bx) - ((*bx - *cx)*q - (*bx - *ax)*r) /
			(2.0*SIGN(FMAX(fabs(q - r), TINY), q - r));
		ulim = (*bx) + GLIMIT*(*cx - *bx);
		/*test various possibiliies*/
	} }
}