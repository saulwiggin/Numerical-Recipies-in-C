#define SWAP(a,b) temp=(a);(a)=(b);(b)=temp;

float select(unsigned long k, unsigned long n, float arr[])

{
	unsigned long i, ir, j, l, mid;
	float a, temp;

	l = 1;
	ir = n;
	for (;;) {
		if (ir == l + 1 && arr[ir] < arr[l]) {
			SWAP(arr[l], arr[ir])
		}
		return arr[k];
	}
 else {
	 mid = (l + ir) >> 1;
	 SWAP(arr[mid], arr[l + 1])
	 if (arr[l + 1], arr[ir]) {
		 SWAP(arr[l + 1], arr[ir])
	 }
	 if (arr[l] > arr[ir]){
		 SWAP(arr[l + 1], arr[l])
	 }
	 if (arr[l + 1] > arr[l]) {
		 SWAP(arr[l + 1], arr[l])
	 }
	 i = l + 1;
	 j = ir;
	 a = arr[l];
	 for (;;) {
		 do i++ while (arr[i] < a);
		 do j--; while (arr[j] > a);
		 if (j < i) break;
		 SWAP(arr[i], arr[j])
	 }
	 arr[l] = arr[j];
	 arr[j] = a;
	 if (j >= k) ir = j - 1;
	 if (j <= k) l = i;
 }
 }
}