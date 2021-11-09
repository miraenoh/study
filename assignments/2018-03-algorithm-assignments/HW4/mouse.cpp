#include <iostream>
#include <stdlib.h>

#define FILENAME_INP "mouse.inp"
#define FILENAME_OUT "mouse.out"

int** readFile(const char*, int*, int*);
void writeFile (const char*, int);
int findBigSeeds(int, int, int**);
void findFromRoot(int*, int, int, int, int, int, int**);

int main(void) {
	
	int n, m;
	int **matrix = readFile(FILENAME_INP, &n, &m);
	
	int bigN = findBigSeeds(n, m, matrix);
	
	writeFile(FILENAME_OUT, bigN);
	/*
	//	CHECK
	std::cout << "n = " << n << ", m = " << m << std::endl;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j)
			std::cout << matrix[i][j] << "\t";
		std::cout << "\n";
	}
	std::cout << "The Biggest Number = " << bigN << std::endl;
	//	CHECK
	*/
	
	for (int i=0; i<n; ++i)
		free(matrix[i]);
	free(matrix);
	
	return 0;
}

int findBigSeeds(int n, int m, int** matrix) {
	
	int biggestN = 0;
	
	for (int i=0; i<n; ++i) {
		
		int bigN = 0;
		findFromRoot(&bigN, 0, i, 0, n, m, matrix);
		
		if (bigN > biggestN) {
			biggestN = bigN;
		}
			
	}
	
	return biggestN;
}

void findFromRoot(int *bigN, int curBigN, int i, int j, int n, int m, int **matrix) {
	
	curBigN += matrix[i][j];
	
	if (j==m-1) {
		
		if (curBigN > *bigN) 
			*bigN = curBigN;
		
		return;
	}
	
	if (i>0)
		findFromRoot(bigN, curBigN, i-1, j+1, n, m, matrix);
	
	findFromRoot(bigN, curBigN, i, j+1, n, m, matrix);
	
	if (i<n-1)
		findFromRoot(bigN, curBigN, i+1, j+1, n, m, matrix);
}

int** readFile(const char* fileName, int* n, int* m) {
	
	FILE *fptr;
	fptr = fopen(fileName, "r");
	
	fscanf(fptr, "%d%d", n, m);
	
	int** matrix;
	matrix = (int**)calloc(*n, sizeof(*matrix));
	for (int i=0; i<*n; ++i)
		matrix[i] = (int*)calloc(*m, sizeof(**matrix));
	
	for (int i=0; i<*n; ++i)
		for (int j=0; j<*m; ++j)
			fscanf(fptr, "%d", &matrix[i][j]);
	
	return matrix;
}

void writeFile (const char* fileName, int input) {
	
	FILE *fptr;
	fptr = fopen(fileName, "w");
	
	fprintf(fptr, "%d", input);
	
	fclose(fptr);
	return;
}
