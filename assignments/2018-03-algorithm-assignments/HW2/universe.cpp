#include <iostream>
#include <stdlib.h>

int** fileRd (int*, int*);
void fileWt (int);
int findNUni (int, int, int**);

int main (int argc, const char* argv[]) {
	
	int m = 0,  n = 0;
	
	int * * sizesOfPlnts;
	sizesOfPlnts = fileRd(&m, &n);
	
	//	check file reading 
	//std::cout << "m, n :" << m << ", " << n << std::endl;  
	/*
	for (int i=0; i<m; ++i) {
		for (int j=0; j<2*n; ++j)
			std::cout << sizesOfPlnts[i][j] << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;*/
	
	
	int nUni = findNUni(m, n, sizesOfPlnts);
	
	//	check the result
	//std::cout << "the number of uniform : " << nUni << std::endl;
	
	fileWt(nUni);
	
	for (int i=0; i<m; ++i)
		free(sizesOfPlnts[i]);
	free(sizesOfPlnts);
	
	return 0;
}

int findNUni (int m, int n, int **sizes) {
	
	int nUni = 0;
	
	for (int i=0; i<m; ++i) {
		
		bool isUni = true;
		
		for (int j=0; j<n-1 && isUni==true; ++j) 
			for (int k=j; k<n && isUni==true; ++k) {
				if (sizes[i][j] > sizes[i][k]) 
					if (sizes[i][j+n] <= sizes[i][k+n]) 
						isUni = false;
				if (sizes[i][j] == sizes[i][k]) 
					if (sizes[i][j+n] != sizes[i][k+n]) 
						isUni = false;
				if (sizes[i][j] < sizes[i][k]) 
					if (sizes[i][j+n] >= sizes[i][k+n]) 
						isUni = false;
			}
		
		if (isUni==true)
			++nUni;
	}
	
	return nUni;
}

int ** fileRd (int *m, int *n) {
	
	FILE *fptr;
	fptr = fopen("universe.inp", "r");
	fscanf(fptr,"%d%d", m, n);
	
	//std::cout << "m : " << *m << std::endl;
	
	int ** x;
	x = (int**)calloc(*m, sizeof(*x));
	for (int i=0; i<*m; ++i)
		x[i] = (int*)calloc(2*(*n), sizeof(x));
	
	for (int i=0; i<*m; ++i) 
		for (int j=0; j<2*(*n); ++j)
			fscanf(fptr, "%d", &x[i][j]);
	
	fclose(fptr);
	
	return x;
}

void fileWt (int input) {
	
	FILE *fptr;
	
	fptr = fopen("universe.out", "w");
	fprintf(fptr, "%d", input);
	
	fclose(fptr);
	
	return;
}
