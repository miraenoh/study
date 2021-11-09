/*	Counting sort function	*/
void counting_sort(int A[], int k, int n) {
	
	int B[n], C[k];
	
	for (int i=0; i<=k; ++i)
		C[i] = 0;
	
	for (int j=1; j<=n; ++j)
		++C[A[j]];
	
	for (int i=1; i<=k; ++i)
		C[i] += C[i-1];
	
	for (int j=n; j>0; --j) {
		
		B[C[A[j]]] = A[j];
		--C[A[j]];
	}
}
