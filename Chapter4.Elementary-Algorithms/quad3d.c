static float xsav, ysav;
static float(*nrfunc)(float, float, float);

float quad3d(float(*func)(float, float, float), float x1, float x2)
{
	float qgaus(float(*func)(float, float a, float b);
	float f1(float x);

	nrfunc = func;
	return qgaus(f1, x1, x2);
}
float f1(float x)
{
	float qgaus(float(*func)(float), float a, float b);
	float f2(float y);
	float yy1(float), yy2(float);

	xsav = x;
	return qgaus(f2, yy1(x), yy2(x));
}

float f2(float y)
{
	float qgaus(float(*func)(float), float a, float b);
	float f3(float z);
	float z1(float, float), z2(float, float);

	ysav = y;
	return qgaus(f3, z1(xsav, y), z2(xsav, y));
}
float f3(float z)
return (*nrfunc)(xsav,ysav, z);
}
