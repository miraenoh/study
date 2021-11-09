#include <iostream>
#include <stdlib.h>

void readFile(int*, int*, int**, int**);
void findAndWrite(int, int, int*, int*);

int main(void) {
	
	int p, m;
	int* nBalls;
	int* labels;
	
	readFile(&p, &m, &nBalls, &labels);
	/*
	//	CHECK
	std::cout << ">> check file reading <<\n";
	for (int i=0; i<p; ++i)
		std::cout << nBalls[i] << " ";
	std::cout << std::endl;
	for (int i=0; i<m; ++i)
		std::cout << labels[i] << " ";
	std::cout << "\n\n";
	//	CHECK
	*/
	findAndWrite(p, m, nBalls, labels);
	
	free(nBalls);
	free(labels);
	return 0;
}

void findAndWrite(int p, int m, int* nBalls, int* labels) {
	
	int* labelForPipes;
	labelForPipes = (int*)calloc(p, sizeof(*labelForPipes));
	
	labelForPipes[0] = nBalls[0];
	for (int i=1; i<p; ++i)
		labelForPipes[i] = labelForPipes[i-1] + nBalls[i];
	/*
	//	CHECK
	std::cout << ">> check labelForPipes <<\n";
	for (int i=0; i<p; ++i)
		std::cout << labelForPipes[i] << " ";
	std::cout << "\n\n";
	//	CHECK
	*/
	//	find & write
	FILE *fptr;
	fptr = fopen("ball.out", "w");
	
	for (int i=0; i<m; ++i) {
		for (int j=0; j<p; ++j) {
			if (labels[i]<=labelForPipes[j]) {
				fprintf(fptr, "%d\n", j+1);
				break;
			}
		}
	}
	
	free(labelForPipes);
	fclose(fptr);
	return;
}

void readFile(int *n, int *m, int **arr1, int **arr2) {
	
	FILE *fptr;
	fptr = fopen("ball.inp", "r");
	
	fscanf(fptr,"%d", n);
	
	*arr1 = (int*)calloc(*n, sizeof(**arr1));
	for (int i=0; i<*n; ++i)
		fscanf(fptr, "%d", &(*arr1)[i]);
	
	fscanf(fptr,"%d", m);
	
	*arr2 = (int*)calloc(*m, sizeof(**arr2));
	for (int i=0; i<*m; ++i)
		fscanf(fptr, "%d", &(*arr2)[i]);
	
	fclose(fptr);
	return;
}
