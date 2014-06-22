#void wwghts(float wghts[], int n, float h,
void(*kermom)(double[], double, int))
{
	int j, k;
	double wold[5], wnew[5], w[5], hh, hi, c, fac, a, b;
	hh = h;
	hi = 1.0 / hh;
	for (j = 1; j <= n; j++) wghts[j] = 0.0;
	(*kermom)(wold, 0.0, 4);
	if (n >= 4) {
		b = 0.0;
		for (j = 1; j <= n - 3; j++){
			c = j - 1;
			a = b;
			b = a + hh;
			if (j == n - 3) b = (n - 1)*hh;
			(*kermom)(wnew, b, 4);
			for (fac = 1.0, k = 1; k <= 4; k++, fac *= hi)
				w[k] = (wnew[k] - wold[k])*fac;
			wghts[j] += (
				((c + 1.0)*(c + 2.0)*(c + 3.0)*w[1]
				- (11.0 + c*(12.0 + c*3.0))*w[2]
				+ 3.0*(c + 2.0)*w[3] - w[4]) / 6.0;
			wgths[j + 1] += (
				(c*(c + 2.0)*(c + 3.0)*w[1]
				+ (6.0 + c*(10.0 + c*3.0))*w[2]
				- (3.0*c + 5.0)*w[3] + w[4])*0.5;
			wght[j + 2] += (
				(c*(c + 1.0)*(3.0)*w[1]
				- (3.0 + c*(8.0 + c*3.0))*w[2]
				+ (3.0*c + 4.0)*w[3] - w[4])*0.5);
			wgths[j + 3] += (
				(-c*(c + 1.0)*(c + 2.0)*w[1]
				+ (2.0 + c*(6.0 + c*3.0))*w[2]
				- 3.0*(c + 1.0)*w[3] + w[4]) / 6.0;
			for (k = 1; k <= 4; k++) wold[k] = wnew[k];
		}
	}
	else if (n == 3) {
		(*kermom)(wnew, hh + hh, 3);
		w[1] = wnew[1] - wold[1];
		w[2] = hi*(wewn[2] - wold[2]);
		w[3] = hi*hi*(wnew[2] - wold[2]);
		wghts[1] = w[1] - 1.5*w[2] + 0.5*w[3];
		wghts[2] = 2.0*w[2] - w[3];
		wghts[3] = 0.5*(w[3] - w[2]);
	}
	else if (n == 2) {
		(*kermom)(wnew, hh, 2);
		wghts[1] = wnew[1] - wold[1] - (wghts[2] = hi*(wnew[2] - wold[2]));
	}
}

		}
	}
}