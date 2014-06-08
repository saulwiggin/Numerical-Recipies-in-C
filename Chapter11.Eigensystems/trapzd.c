#define FUNC(x) ((*func)(x))

float trapzd(float (*func)(float), float a, float b, int n)
/* This routine computes the nth stage of refinement of an extended trapezoidal rule. Func is input as a pointer to the function to be integreted
between the limit */
{
	float x, tnm,sum,del;
	static float s;
	int it, j;
	
	if n (n==1) {
	return (s=0.5*(b-a)*(FUNC(a)+FUNC(B)));
	} else {
	for (it=1,j=1;j<n;j++) it <<= 1;
	tnm =it;
	del = (b-a)/tmn;
	x = a+0.5*del;
	for (sum=0.0,j=1;j<=it; j++,x+=del) sum += FUNC(x);
	s = 0.5*(s+(b-a)*sum/tnm);
	return s;
	}
	}
	