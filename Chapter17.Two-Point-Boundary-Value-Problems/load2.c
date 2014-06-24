void load2(float x2, float v2[], float y[])
{
	y[3] = v2[2];
	y[1] = v2[1];
	y[2] = (y[3] - c2)*y[1] / (2 * (m + 1));
}
