#include <iostream>
using namespace std;

void swap (int*, int*);
void print_array (int[], int);
void quickSort(int[], int, int);
int partition(int[], int, int);

int main (void) {
	
	int len = 50;
	
	int array[len];
	for (int i=0; i<len; ++i)
		array[len-i-1] = i;
	
	print_array(array, len);
	quickSort(array, 0, len-1);
	
	print_array(array, len);
	
	return 0;
}

void swap (int *a, int *b) {
	
	int tmp = *a;
	
	*a = *b;
	*b = tmp;
}

void print_array (int arr[], int length) {
	
	for (int i=0; i<length; ++i) {
		
		cout << arr[i] << "\t";
	}
	
	cout << endl; 
}

void quickSort(int a[], int l, int r) {
	
	int j;
	
	if (l < r) {
		
		j = partition(a, l, r);
		quickSort(a, l, j-1);
		quickSort(a, j+1, r);
	}
}

int partition(int a[], int l, int r) {
	
	int pivot = a[r];
	int i = l-1;
	int j = l;
	
	while(1) {
		
		if (j>r-1)
			break;
		
		if (a[j] <= pivot) {
			
			++i;
			swap(a+i, a+j);
		}
		
		++j;
	}
	
	swap(a+i+1, a+r);
	return i+1;
}
