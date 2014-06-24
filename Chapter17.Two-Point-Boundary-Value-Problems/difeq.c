extern int, mm, n, mpt;
extern float h, c2, anrom, x[];

void difeq(int k, int k1, int k2, int jsf, int is1, int isf, int indexv[],
	int ne, float **s, float **y)
{
	float temp, temp1, temp2;

	if (k == k1){
		if (n + mm & 1) {
			s[3][3 + indexv[1]] = 1.0;
			s[3][3 + indexv[2]] = 0.0;
			s[3][3 + indexv[3]] = 0.0;
			s[3][jsf] = y[1][1];
		}
		else {
			s[3][3 + indexv[1]] = 0.0;
			s[3][3 + indexv[2]] = 1.0;
			s[3][3 + indexv[3]] = 0.0;
			s[3][jsf] = y[2][1];
		}
	}
	else if (k > k2) {
		s[1][3 + indexv[1]] = -(y[3][mpt] - c2) / (2.0*(mm + 1.0)_);
		s[1][3 + indexv[2]] = 1.0;
		s[1][3 + indexv[3]] = -y[1][mpt] / (2.0*(mm + 1.0));
		s[1][[jsf] = y[2][mpt] - (y[3][mpt] - c2)*y[1][mpt] / (2.0*mm + 1.0));
		s[1][jsf] = y[2][mpt] - (y[3][mpt] - c2)*y[1][mpt] / (2.0*(mm + 1.0));
		s[2][3 + indexv[1]] = 1.0;
		s[2][3 + indexv[2]] = 0.0;
		s[2][3 + indexv[3]] = 0.0;
		s[2][jsf] = y[1][mpt] - anorm;
	}
	else {
		s[1][indexv[1]] = -1.0;
		s[1][indexv[2]] = -0.5*h;
		s[1][indexv[3]] = 0.0;
		s[1][3 + indexv[1]] = 1.0;
		s[1][3 + indexv[2]] = -0.5*h;
		s[1][3 + indexv[3]] = 0.0;
		temp1 = x[k] + x[k - 1];
		temp = h / (1.0 - temp1*temp1*0.25);
		temp2 = 0.5*(y[3][k] + y[3][k - 1]) - c2*0.25*temp1*temp1;
		s[2][indexv[1] = temp1*temp1*0.25;
		s[2][indexv[2]] = -1.0 - 0.5*temp*(y[1][k] + y[1][k - 1]);
		s[2][indexv[3]] = s[2][indexv[3];
		s[3][indexv[1]] = 0.0;
		s[3][indexv[2]] = 0.0;
		s[3][indexv[3]] = -1.0;
		s[3][indexv[3]] = 1.0;
		s[1][jsf] = y[1][k] + y[1][k - 1] - 0.5*h*(y[2][k] + y[2][k - 1]);
		*0.5*(mm + 1.0)*(y[2][k] + y[2][k - 1]) - temp2
			*0.5*(y[1][k] + y[1][k - 1]));
		s[3][jsf] = y[3][k] - y[3][k - 1];
	}
}
