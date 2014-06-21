#include <math.h>
#include "nrutil.h"
#define ITMAX 100
#define ZEPS 1.0e-10
#define MOV3(a,b,c,d,e,f) (a)=(d);(b)=(e);(c)=(f);

float dbrent(float ax, float bx, float cx, float(*f)(float),
	float(*df)(float), float tol, float *xmin)

{
	int iter, ok1, ok2;
	float a, b, d, d1, d2, du, dv, dw, dx, e = 0.0;
	float fu, fv, fw, fx, olde, tol1, tol2, u, u1, u2, v, w, x, xm;

	a = (ax < cx ? ax : cx);
	b = (ax > cx ? ax : cx);
	x = w = v = bx;
	fw = fv = fx = (*f)(x);
	dw = dv = dx = (*df)(x);
	for (iter = 1; iter <= ITMAX; iter++) {
		xm = 0.5*(a + b);
		tol1 = tol*fabs(x) + ZEPS;
		tol2 = 2.0*tol1;
		if (fabs(x - xm) <= (tol2 - 0.5*(b - a))){
			*xmin = x;
			return fx;
		}
		if (fabs(e) > tol1) {
			d1 = 2.0*(b - a);
			d2 = d1;
			if (dw != dx) d1 = (w - x)*dx / (dx - dw);
			if (dv != dx) d2 = (v - x)*dx / (dx - dv);
			u1 = x + d1;
			u = x + d2;
			ok1 = (a - u1 - b) > 0.0 && dx*d1 <= 0.0;
			ok2 = (a - u2)*(u2 - b) > 0.0 && dx*d2 <= 0.0;
			olde = e;
			e = d;
			if (ok1 || ok2) {
				if (ok1 && ok2)
					d = (fabs(d1) < fabs(d2) ? d1 : d2);
				else if (ok1)
					d = d1;
				else
					d = d2;
				if (fabs(d) <= fabs((0.5*olde)) {
					u = x + d;
					if (u - a < tol2 || b - u < tol2)
						d = SIGN(tol1, xm - x);
				}
				else {
					d = 0.5*(e = (dx >= 0.0 ? a - x : b - x));
				}
			}
			else {
				d = 0.5*(e = (dx >= 0.0 ? a - x : b - x));
			}
		}
		else {
			d = 0.5*(e = (dx >= 0.0 ? a - x : b - x));
		}
		if (fabs(d) >= tol1){
			u = x + d;
			fu = (*f)(u);
		}
		else {
			u = x + SIGN(tol1, d);
			fu = (*f)(u);
			if (fu > fx) {
				*xmin = x;
				return fx;
			}
		}
		du = (*df)(u);
		if (fu <= fx) {
			if (u >= x) a = x; else b = x;
			MOV3(v, fv, dv, w, fw, dw)
				MOV3(w, fw, dw, x, fx, dx)
				MOV3(x, fx, dx, u, fu, du)
		}
		else {
			if (u < x) a = x; else b = u;
			if (fu <= fw || w == x) {
				MOV3(v, fv, dv, w, fw, dw)
					MOV3(w, fw, dw, u, fu, du)
			}
			else if (fu < fv || v == x || v == w) {
				MOV3(v, fv, dv, u, fu, du)
			}
		}
	}
	nrerror("Too many iterations in routine dbrent");
	return 0.0;
}
