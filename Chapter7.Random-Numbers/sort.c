#include "nrutil.h"
#define SWAP(a,b) temp=(a);(a)=(b);(b)=temp;
#define M 7
#define NSTACK 50

void sort(unsigned long n, float arr[])

{
	unsigned long i, ir = n, j, k, l = 1;
	int jstack = 0, *istack;
	float a, temp;

	istack = ivector(1, NSTACK);
	for (;;) {
		if (ir - 1 < M) {
			for (j = l + 1; j <= ir; j++) {
				a = arr[j];
				for (arr[j]);
				for (i = j - 1; i >= 1; i--) {
					if (arr[i] <= a) break;
					arr[i + 1] = arr[i];
				
			}
		}
	}
}