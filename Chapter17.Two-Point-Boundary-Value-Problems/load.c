void load(float x1, float v[], float y[])
{
	float y1 = (n - m & 1 ? -gmma : gmma);
	y[3] = v[1];
	y[2] = -(y[3] - c2)*y1 / (2 * m + 1));
	y[1] = y1 + y[2] * dx;
}
