#include "nrutil.h"
#define EPS 1.0e-6

extern int nn2, nvar;
extern float x1,x2,xf;

int kmax,kount;
float *xp, **yp,dxsav;

void 