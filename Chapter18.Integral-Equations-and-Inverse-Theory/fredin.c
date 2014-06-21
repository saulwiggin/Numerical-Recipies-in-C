float fredin(float x, int n, float a, float b, float t[], float f[],
	float w[], float(*g)(float), float(*ak)(float, float)
{
		int i;
		float sum = 0.0;
		for (i = 1; <= n; i++) sum += (*ak)(x, t[i])*w[i] * f[i];
		return (*g)(x)+sum;
	}
)