#include <stdio.h>
#include <stdlib.h>

#define INPUTNAME "thief.inp"
#define OUTPUTNAME "thief.out"

void read_input_from_file(int*, int*, int**, int**);
void output_to_file(int, int*);
void process(int*, int*, int, int,int*, int*);
int findCurMax(float*, int);
void sort(int, int*);

int main(void) {
	
	int n, w;										//	n & w
	int *wts, *pfs;									//	weights & profits
	
	read_input_from_file(&n, &w, &wts, &pfs);		//	get n from the input file
	/*
	//	check input
	printf("n : %d, w : %d\n", n, w);
	for (int i=0; i<n; ++i)
		printf("%d\t%d\n",wts[i],pfs[i]);
	*/
	int nItems;										//	the number of chosen items
	int items[n];									//	array for save items which are selected
	process(&nItems, items, n, w, wts, pfs);		//	select items to maximize profit
	
	output_to_file(nItems, items);					//	write result on the output file
	
	free(wts);
	free(pfs);
	return 0;
}

void process(int* nItems, int* items, int n, int w,int* wts, int* pfs) {
	
	*nItems = 0;
	float pftPerWts[n];								//	profits per weights
	for (int i=0; i<n; ++i)							//	fill the array 'profits per weights'
		pftPerWts[i] = pfs[i]/wts[i];
	
	int iMax;
	while (w>0) {									//	select items to carry
		
		iMax = findCurMax(pftPerWts, n);
		items[*nItems] = iMax+1;
		w -= wts[iMax];
		++*nItems;
		pftPerWts[iMax] = 0;
	}
	
	sort(*nItems, items);							//	sort on ascending order
	
	return;
}

void sort(int n, int* arr) {						//	sort items by simple sorting method
	
	for (int i=0; i<n-1; ++i)
		for (int j=0; j<n-1; ++j)
			if (arr[j]>arr[j+1]) {
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
	
	return;
}

int findCurMax(float* pftPerWts, int n) {			//	find current maximum profits per weights and return its index
	
	float max = pftPerWts[0];
	int iMax = 0;
	
	for (int i=1; i<n; ++i)
		if (pftPerWts[i]>max) {
			max = pftPerWts[i];
			iMax = i;
		}
	
	return iMax;
}

void read_input_from_file(int* n, int* w, int** arr1, int** arr2) {
	
	FILE *fptr;
	fptr = fopen(INPUTNAME, "r");
	
	fscanf(fptr, "%d%d", n, w);
	
	*arr1 = (int*)calloc(*n, sizeof(*arr1));
	*arr2 = (int*)calloc(*n, sizeof(*arr2));
	for (int i=0; i<*n; ++i)
		fscanf(fptr,"%d%d", &(*arr1)[i], &(*arr2)[i]);
	
	return;
}

void output_to_file(int n, int* arr) {
	
	FILE *fptr;
	fptr = fopen(OUTPUTNAME, "w");
	
	for (int i=0; i<n; ++i)
		fprintf(fptr, "%d ", arr[i]);
		
	return;
}


