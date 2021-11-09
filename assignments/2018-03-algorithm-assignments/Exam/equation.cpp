#include <stdio.h>

#define INPUTNAME "equation.inp"
#define OUTPUTNAME "equation.out"
#define NUMINTEGER 3

void read_input_from_file(int*);
void output_to_file(int);
int process(int*);

int main (void) {
	
	int integers[NUMINTEGER];					//	array for given numbers
	
	read_input_from_file(integers);				//	read the input file & set array
	
	int difRoots = process(integers);			//	find # of different roots by running function 'process'
	
	output_to_file(difRoots);					//	write the result on the output file
	/*
	//	check
	printf("a = %d / b = %d / c = %d\n", integers[0], integers[1], integers[2]);
	printf("# of diffrent roots = %d\n", difRoots);
	*/
	return 0;
}

int process(int* arr) {
	
	int n = 0;
	
	for (int i=0; i<NUMINTEGER; ++i) {			//	if there is existing number, reduce the count. Repeat it for all items.
		++n;
		for (int j=i-1; j>=0; --j)
			if (arr[i] == arr[j]) {
				--n;
				break;
			}
	}
	
	return n;									//	return the count
}

void read_input_from_file(int* arr) {
	
	FILE *fptr;
	fptr = fopen(INPUTNAME, "r");
	
	for (int i=0; i<NUMINTEGER; ++i)
		fscanf(fptr, "%d", &arr[i]);			//	reads the given number of files in the input file. Save it in the array.
}

void output_to_file(int n) {
	
	FILE *fptr;
	fptr = fopen(OUTPUTNAME, "w");
	
	fprintf(fptr, "%d", n);						//	writes given number on the output file.
}

