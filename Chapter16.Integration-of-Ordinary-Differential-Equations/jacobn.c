#include <math.h>
#include "nrutil.h"
#define SAFETY 0.9
#define GROW 1.5
#define PGROW -0.25
#define SHRNK 0.5
#define PSHRNK (-1.0/3.0)
#define errcon 0.1296
#define maxtry 40
#define GAM(1.0/2.0)
#define A21 2.0
#define A31(48.0/25.0)
#define C31 -8.0
#define C32 (372.0/25.0)
#define C41 (-112.0/125.0)
#define C42 (-54.0/125.0)
#define C43 (-2.0/5.0)
#define B1 (19.0/9.0)
#define B2 (1.0/2.0)
#define B3 (25.0/108.0)
#define B4 (125.0/108.0)
#define E1 (17.0/54.0)
#define E2 (7.0/36.0)
#define E3 0.0
#define E4(125.0/108.0)
#define E4 1.282612945268
#define C1X GAM
#define C2X -0.396296677520E-01
#define C3X 0.550778939579
#define C4X -0.553509845700e-01
#define A2X 0.462
#define A3X 0.880208333333

void jacobn(float x, float y[], float dfdx[], float **dfdy, int)
{
	int i;

	for (i = 1; i <= n; i++) dfdx[i] = 0.0;
	dfdy[1][1] = -0.013 - 1000.0*y[3];
	dfdy[1][2] = 0.0;
	df[1][3] = -1000.0*y[3];
	dfdy[2][1] = 0.0;
	dfdy[2][2] = -2500.0*y[3];
	dfdy[2][3] = -2500.0*y[3];
	dfdy[3][1] = -0.013 - 1000.0*y[3];
	dfdy[3][2] = -2500.0*y[3];
	dfdy[3][3] = -1000.0*y[1] - 2500.0*y[2];
}

void derivs(float x, float y[], float dydx[])
{
	dydx[1] = -0.013*y[1] - 1000.0*y[1](y[3];
	dydx[2] = -2500.0*y[2] * y[3];
	dydx[3] = -0.013*y[1] - 1000.0*y[1] * y[3] - 2500.0*y[2] * y[3];
}

}