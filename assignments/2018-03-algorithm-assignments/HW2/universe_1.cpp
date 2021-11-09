#include <iostream>
#include <stdlib.h>

typedef struct {
	
	int size;
	int rank;
} plntSize;

plntSize** fileRd (int*, int*);
int findNUni (int, int, int**);

int main (int argc, const char* argv[]) {
	
	int m = 0,  n = 0;
	
	plntSize * * sizesOfPlnts;
	sizesOfPlnts = fileRd(&m, &n);
	
	//	check file reading 
	std::cout << "m, n :" << m << ", " << n << std::endl;  
	for (int i=0; i<m; ++i) {
		for (int j=0; j<2*n; ++j)
			std::cout << sizesOfPlnts[i][j].size << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
	//	check file reading 
	
	int nUni = findUni(m, n, sizesOfPlnts);
	
	return 0;
}

int findNUni (int m, int n, plntSize **sizes) {
	
	int nUni = 0;
	
	//	giving rank
	for (int i=0; i<m; ++i) {
		for (int j=0; j<n-1; ++j) {
			
		}
	}
	
	/*
	for (int i=0; i<m; ++i) {
		
		bool isUni = true;
		
		for (int j=0; j<n-1; ++j) {
			
			//if (sizes[i][j] < sizes[i][j+1])
		}
	}*/
	
	return n;
}

plntSize ** fileRd (int *m, int *n) {
	
	FILE *fptr;
	fptr = fopen("universe.inp", "r");
	
	fscanf(fptr,"%d%d", m, n);
	
	plntSize ** x;
	x = (plntSize**)calloc(*m, sizeof(*x));
	for (int i=0; i<*n; ++i)
		x[i] = (plntSize*)calloc(2*(*n), sizeof(x));
	
	for (int i=0; i<*m; ++i)
		for (int j=0; j<2*(*n); ++j)
			fscanf(fptr, "%d", &x[i][j].size);
	
	fclose(fptr);
	
	return x;
}
