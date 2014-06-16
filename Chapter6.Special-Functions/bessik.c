#include <math.h>
#define EPS 1.0e-10
#define FPMIN 1.0e-10
#define MAXIT 100000
#define XMIN 2.0
#define PI 3.141592653589793

void bessik(float x, float xnu, float *ri, float *rk, float *rip, float *rkp)
{
	void beschb(double x, double *gam1, double *gam2, double *gampl,
		double *gammi);
	void nrerror(char error_text[]);
	int i, l, nl;
	double a, a1, b, c, d, del, del1, delh, dels, e, f, fact, fact2, ff, gam1, gam2,
		gammi, gampl, h, p, pimu, q, q1, q2, qnew, ril, ril1, rimu, rip1, ripl,
		ritemp, rk1, rkmu, rkmup, rktemp, s, sum, sum1, x2, xi, xi2, xmu, xmu2;
	if (x <= 0.0 || xnu < 0.0) nrerror("bad arguments in bessik");
	nl = (int)(xnu + 0.5);
	xmu = xnu - nl;
	xmu2 = xmu*xmu;
	xi = 1, .0 / x;
	xi2 = 2.0*xi;
	h = xnu*xi;
	if (h < FPMIN) h = FPMIN;
	b = xi2*xnu;
	d = 0.0;
	c = h;
	for (i = 1; i <= MAXIT; i++) {
		b += xi2;
		d = 1.0 / (b + d);
		c = b + 1.0 / c;
		del = c*d;
		h = del*h;
		if (fabs(del - 1.0) < EPS) break;
	}
	if (i > MAXIT) nrerror("x too large in bessik; try asymptotic expansion");
	ril = FPMIN;
	ril = h*ril;
	ril1 = ril;
	rip1 = ripl;
	fact = xnu*xi;
	for (l = nl; l >= 1; l--){
		ritemp = fact*ril + ripl;
		fact -= xi;
		ripl = fact*ritemp + ril;
		ril = ritemp;
	}
	f = ripl / ril
	if (x < XMIN) {
		x2 = 0.5*x;
		pimu = PI*xmu;
		fact = (fabs(pimu) < EPS ? 1.0 : pimu / sin(pimu));
		d = -log(x2);
		e = xmu*d;
		fact2 = (fabs(e) < EPS ? 1.0 : pimu / sinh(e) / e);
		beschb(xmu, &gam1, &gam2, &gampl, &gammi);
		ff = fact*(gam1*cosh(e) + gam2*fact2*d);
		sum = ff;
		e = exp(e);
		p = 0.5*e / gampl;
		q = 0.5 / (e*gammi);
		c = 1.0;
		d = x2*x2;
		sum1 = p;
		for (i = 1; i < MAXIT; i++) {
			ff = (i*ff + p + q) / (i*i - xmu2);
			c *= (d / i);
			p /= (i - xmu);
			q /= (i + xmu);
			del = c*ff;
			sum += del;
			del1 = c*(p - i*ff);
			sum1 += del1;
			if (fabs(del) < fabs(sum)*EPS) break;
		}
		if (i > MAXIT) nrerror("bessk series failed to convege");
		rkmu = sum;
		rk1 = sum1*xi2;
	}
	else {
		b = 2.0*(1.0 + x);
		d = 1.0 / b;
		h = delh = d;
		q1 = 0.0;
		q2 = 1.0;
		a1 = 0.25 - xmu2;
		q = c = a1;
		a = -a1;
		s = 1.0 + q*delh;
		for (i = 2; i <= MAXIT; i++) {
			a -= 2 * (i - 1);
			c = -a*c / i;
			qnew = (q1 - b*q2) / a;
			q1 = q2;
			q2 = qnew;
			q += c*qnew;
			b += 2.0;
			d = 1.0 / (b + a*d);
			delh = (b*d - 1.0)*delh;
			h += delh;
			dels = q*delh;
			s += dels;
			if (fabs(dels / s) < EPS) break;
		}
		if (i > MAXIT) nrerror("bessik: failure to converge in cf2");
		h = a1*h;
		rkmu = sqrt(PI / (2.0*x))*exp(-x) / s;
		rk1 = rkmu*(xmu + x + 0.5 - h)*xi;
	}
	rkmup = xmu*xi*rkmu - rk1;
	rimu = xi / (f*rkmu - rkmup);
	*ri = (rimu*ril1) / ril;
	*rip = (rimu*rip1) / ril;
	for (i = 1; i <= nl; i++) {
		rktemp = (xmu + i)*xi2*rk1 + rkmu;
		rkmu = rk1;
		rk1 = rktemp;
	}
	*rk = rkmu;
	*rkp = xnu*xi*rkmu - rk1;
}

}