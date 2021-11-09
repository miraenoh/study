#include <iostream>
#include <stdlib.h>

#define INPUTNAME "monosequence.inp"
#define OUTPUTNAME "monosequence.out"

void readFile(int*, int**);
void writeFile(int);
int process(int, int[]);
int process_recur(int, int[], int*);

int main(void) {
	
	//	read data from the input file
	int n;
	int *seq;
	readFile(&n, &seq);
	
	//	find the maximum # of elements of sub-sequence
	int nSub = process(n, seq);
	
	//	write the result on the output file
	writeFile(nSub);
	
	return 0;
}

int process_recur(int n, int seq[], int *nSub) {
	
	int cur_nSub = 1;
	int result = 1;
	
	for (int i=1; i<n; ++i) {
		
		//	reculsively get all ends
		result = process_recur(i, seq, nSub);
		
		//	check if seq[i-1] is smaller and current # is smaller,
		//	then replace it
		if (seq[i-1]>seq[n-1])
			continue;
		if (cur_nSub>result+1)
			continue;
		
		cur_nSub = result + 1;
	}
	
	//	check if we found the max number, then replace
	if (cur_nSub > *nSub)
		*nSub = cur_nSub;
	
	//	return current # of subarray for recursion
	return cur_nSub;
}

int process(int n, int seq[]) {
	
	int nSub = 1;
	//	find the # of elements of the longest sub-sequence
	process_recur(n, seq, &nSub);
	
	return nSub;
}

void readFile(int* n, int** arr) {
	
	FILE *fptr;
	fptr = fopen(INPUTNAME, "r");
	
	fscanf(fptr, "%d", n);
	
	*arr = (int*)calloc(*n, sizeof(*arr));
	for (int i=0; i<*n; ++i)
		fscanf(fptr, "%d", &(*arr)[i]);
	
	fclose(fptr);
	return;
}

void writeFile(int n) {
	
	FILE *fptr;
	fptr = fopen(OUTPUTNAME, "w");
	
	fprintf(fptr, "%d", n);
	
	fclose(fptr);
	return;
}


