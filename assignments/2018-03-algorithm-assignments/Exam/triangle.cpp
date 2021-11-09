#include <stdio.h>

#define INPUTNAME "triangle.inp"
#define OUTPUTNAME "triangle.out"

void read_input_from_file (int*, int*, int*);
void output_to_file (int);
int process (int*, int*, int*);

int main (void) {
	
	int a[2], b[2], c[2];						//	3 arrays for coordinates
	
	read_input_from_file (a, b, c);				//	read coordinates of A, B, and C from the input file
	
	int ifIso = process (a, b, c);				//	find out if the triangle is isosceles triangle
	
	output_to_file(ifIso);						//	write the result on the output file
	
	/*
	//	check
	printf("%d %d %d %d %d %d\n", a[0], a[1], b[0], b[1], c[0], c[1]);
	printf("If the triangle is isosceles : %d\n", ifIso);
	*/
	return 0;
}

int process (int* a, int* b, int* c) {
	
	int sqN1, sqN2, sqN3;						//	squares of the each lines
	
	//	find each squares of lines
	sqN1 = (b[0]-a[0])*(b[0]-a[0]) - (b[1]-a[1])*(b[1]-a[1]);
	sqN2 = (c[0]-b[0])*(c[0]-b[0]) - (c[1]-b[1])*(c[1]-b[1]);
	sqN3 = (a[0]-c[0])*(a[0]-c[0]) - (a[1]-c[1])*(a[1]-c[1]);
	
	//	check if the triangle is Isosceles. if it's true, return 1
	if (sqN1 == sqN2)
		return 1;
	if (sqN2 == sqN3)
		return 1;
	if (sqN3 == sqN1)
		return 1;
	//	if not, return 0
	return 0;
}

void read_input_from_file (int* a, int* b, int* c) {
	
	FILE *fptr;
	fptr = fopen(INPUTNAME, "r");
	
	fscanf(fptr, "%d%d%d%d%d%d", &a[0], &a[1], &b[0], &b[1], &c[0], &c[1]);	//	read values of coordinates from the input file
}

void output_to_file(int n) {
	
	FILE *fptr;
	fptr = fopen(OUTPUTNAME, "w");
	
	fprintf(fptr, "%d", n);	//	writes given number on the output file.
}
