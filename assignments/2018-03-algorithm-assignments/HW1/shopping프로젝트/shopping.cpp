#include <iostream>

int fileOp (int num, int *array) {						//	open and read an input file
	
	FILE *fptr; 
	
	fptr = fopen("shopping.inp","r");
	fscanf(fptr,"%d", &num);
	for (int i=0; i<num; ++i)
		fscanf(fptr, "%d", &array[i]);
	
	fclose(fptr);
	return num;
}

void fileWt (int input) {
	
	FILE *fptr;
	
	fptr = fopen("shopping.out", "w");
	fprintf(fptr, "%d", input);
	
	fclose(fptr);
	return;
}

void merge (int *a, int low, int mid, int high) {
	
	int *b = new int[high-low+1];
	int h, i, j, k;
	h = low; i = low; j = mid + 1;
	
	while ((h<=mid) && (j <= high)) {
		
		if (a[h] <= a[j]) { b[i] = a[h]; ++h; }
		else { b[i] = a[j]; ++j; }
		++i;
	}
	
	if (h > mid)
		for (k=j; k<=high; ++k) {
			
			b[i] = a[k];
			++i;
		}
	else
		for (k=h; k<=mid; ++k) {
			
			b[i] = a[k]; ++i;
		}
	
	for (k=low; k<=high; ++k)
		a[k] = b[k];
	
	delete[] b;
	return;
}

void merge_sort (int *a, int low, int high) {
	
	int mid;
	
	if (low < high) {
		
		mid = (low+high)/2;
		merge_sort(a, low, mid);
		merge_sort(a, mid+1, high);
		merge(a, low, mid, high);
	}
	
	return;
}

int maxDiscount (int *a, int n) {
	
	int max = 0;
	
	for (int i=1; i<=n; ++i)
		if ((i%3) == 0) {
			
			max += a[n-i];
			std::cout << "+" << a[n-i] << " ";
		}
	
	return max;
}

int main (int argc, const char* argv[]) {
	
	//	initialize variable and array
	int n;												//	number of items
	int *itemCost = new int[n];							//	cost of items
	
	//	read input file
	n = fileOp(n, itemCost);							//	open and read an input file
	std::cout << "Value of n = " << n << std::endl;		//	check if the file was read correctly
	for (int i=0; i<n; ++i)
		std::cout << itemCost[i] << " ";
	std::cout << std::endl;
	
	//	sort itemCost array using merge sort
	merge_sort(itemCost, 0, n-1);
	std::cout << std::endl;
	for (int i=0; i<n; ++i)								//	check if the array was sorted corrently
		std::cout << itemCost[i] << " ";
	std::cout << std::endl;
	
	//	find maximum discount
	int maxD = maxDiscount(itemCost, n);				//	find maximum using function 'maxDiscount' and put it
	std::cout << std::endl << "maximum discount : " << maxD << std::endl;
	
	fileWt(maxD);
	
	delete[] itemCost;
	return 0;
}
