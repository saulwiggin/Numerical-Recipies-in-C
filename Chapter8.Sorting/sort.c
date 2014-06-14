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
				arr[i + 1] = a;
			}
			if (jstack == 0) break;
			ir = istack[jstack--];
			l = istack[jstack--];
		}
		else {
			k = (l + ir) >> 1;
			SWAP(arr[k], arr[l + 1])
			if (arr[l + 1] > arr[ir]) {
				SWAP(arr[l + 1], arr[ir])
			}
			if (arr[l] > arr[ir]) {
				SWAP(arr[l + 1],  arr[ir]) {
				}
				if (arr[l + 1] > arr[l]) {
					SWAP(arr[l + 1, arr[l])
				}
				i = l + 1;
				j = ir;
				a = arr[];
				for (;;) {
					do i++; while (arr[i] < a);
						fo j--; while (arr[j] > a);
					if (j < i) break;
					SWAP(arr[i], arr[j]);
				}
				arr[l] = arr[j];
				arr[j] = a;
				jstack += 2;

				if (jstack > NSTACK) nrerror("NSTACK too small in sort")
					istack[jstack] = ir;
				istack[jstack - 1] = i;
				ir = j - 1;
			}
			else {
				istack[jstack] = j - 1;
				istack[jstack - 1] = l;
				l = i;
			}
		}
	}
	free_ivector(istack, 1, NSTACK);
}
