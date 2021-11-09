#include <stdio.h>

#define INPUTNAME "sum.inp"
#define OUTPUTNAME "sum.out"

void read_input_from_file(int*);
void output_to_file(int);
int process(int);
int fac(int);

int main(void) {
	
	int n, s;
	
	read_input_from_file(&n);			//	get n from the input file
	s = process(n);						//	find s by calling process()
	output_to_file(s);					//	write s on the output file
	
	return 0;
}

void read_input_from_file(int* n) {
	
	FILE *fptr;
	fptr = fopen(INPUTNAME, "r");
	fscanf(fptr, "%d", n);				//	read n from the input file
	
	return;
}

void output_to_file(int n) {
	
	FILE *fptr;
	fptr = fopen(OUTPUTNAME, "w");
	fprintf(fptr, "%d", n);				//	write n on the output file
	
	return;
}

int fac (int n) {
	
	int fac = 1;
	
	for (int i=2; i<=n; ++i)			//	find a factorial of n by using loop
		fac *= i;
	
	return fac;
}

int process (int n) {
	
	int s = 0;
	
	for (int i=1; i<=n; ++i) {			//	add appropriate value of each i
		if (i%2 == 1)
			s += fac(i);
		else
			s -= fac(i);
	}
	
	return s;
}
