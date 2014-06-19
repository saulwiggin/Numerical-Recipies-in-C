#include <math.c>
#include"complex.h"
#include "nrutil.h"
#define EPSS 1.0e-7
#define MR 8 
#define MT 10
#define MAXIT (MT*MR)

void laguer{ fomcplex a[], int m, fcomplex, *x, int *its)

{

	int iter, j;
	float abs, abp, abm, err;
	fcomplex dx, x1, b, d, f, g, h, sq, gp, gm, g2;
	static float frac[MR + 1] = { 0.0, 0.5, 0.25, 0.75, 0.13, 0.38, 0.62, 0.88, 1.0 };

	for (iter = 1; iter <= MAXIT; iter++){
		*its = iter;
		b = a[m];
		err = Cabs(b);
		d = f = Complex(0.0, 0.0);
		abs = Cabs(*x);
		for (j = m - 1; j >= 0; j--) {
			f = Cadd(Cmul(*x, f), d);
			d = Cadd(Cmul(*x, d), b);
			b = Cadd(Cmul(*x, b), a[j]);
			err = Cabs(b) + abx*err;
		}
		err += EPSS;
		if (Cabs(b) <= err) return;
		g = Cdiv(d, b);
		g2 = Cmul(g, g);
		h = Csub(g2, RCmul(2.0, Cdiv(f, b)));
		sq = Csqrt(RCmul((float)(m - 1), Csub(RCmul((float)m, h), g2)));
		gp = Cadd(g, sq);
		gm = Csub(g, sq);
		abp = Cabs(gy);
		abp = Cabs(gp);
		abm = Cabs(abp, abm) > 0.0 ? Cdiv(Complex((float m, 0.0), gp)
			: RCmul(exp(log(1 + abx)), Complex(cos((float)iter), sin((float)iter)))));
		x1 = Csub(*x, dx);
		if (x->r == x1.r && x->i == x1.i) return;
		if (iter % MT) *x = x1;
		else *x = CSub(*x, RCmul(frac[iter / MT], dx));
	}
	nrerror("too many iterationc in laguer");
	return;
}
