#include <stdio.h>
#include <stdlib.h>

#define INPUTNAME "sequence.inp"
#define OUTPUTNAME "sequence.out"

void read_input_from_file(int**, int*);
void output_to_file(int);
int process (int*, int);

int main (void) {
	
	int n;										//	integer values for given n
	int *seq;									//	array for given sequence
	read_input_from_file(&seq, &n);				//	get n and seq from the input file
	
	int smallSum = process(seq, n);				//	find the smallest sum
	
	output_to_file(smallSum);					//	write the result on the input file
	/*
	//	check
	printf("n = %d\n", n);
	for (int i=0; i<n; ++i)
		printf("%d ", seq[i]);
	printf("\n");
	printf("the smallest sum = %d\n", smallSum);
	*/
	return 0;
}

int process (int* seq, int n) {
	
	int smallSum = 0;
	for (int i=0; i<4; ++i)
		smallSum += seq[i];						//	initialize smallSum
	
	int curSum;
	for (int i=4; i<=n; i += 4)					//	i : size of sub-sequence
		for (int j=0; j+i-1 < n; ++j) {			//	examine each sub-sequence, then change smallSum if curSum is smaller.
			
			curSum = 0;
			for (int k=0; k<i; ++k)
				curSum += seq[j+k];
			
			if (curSum < smallSum)
				smallSum = curSum;
		}
	
	return smallSum;
}

void read_input_from_file(int** arr, int* n) {
	
	FILE *fptr;
	fptr = fopen(INPUTNAME, "r");
	
	fscanf(fptr, "%d", n);							//	get n from the input file
	
	*arr = (int*)calloc(*n, sizeof(*arr));
	for (int i=0; i<*n; ++i)
		fscanf(fptr, "%d", &(*arr)[i]);				//	get the given sequence from the input file
}

void output_to_file(int n) {
	
	FILE *fptr;
	fptr = fopen(OUTPUTNAME, "w");
	
	fprintf(fptr, "%d", n);							//	writes given number on the output file.
}
