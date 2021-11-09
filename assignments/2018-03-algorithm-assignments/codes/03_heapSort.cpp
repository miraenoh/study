#include <iostream>
using namespace std;

void max_heapify(int*, int, int);
void build_maxheap(int*, int);
void heapsort(int*, int);
void swap (int*, int*);
void print_array (int[], int);

int main (void) {
	
	int len = 50;
	
	int array[len];
	for (int i=0; i<len; ++i)
		array[i] = i;
		//array[len-i-1] = i;
	
	print_array(array, len);
	
	build_maxheap(array, len-1);
	print_array(array, len);
	
	heapsort(array, len-1);
	
	print_array(array, len);
	
	return 0;
}

void max_heapify(int *a, int i, int n) {
	
	int largest = i;
	int l = 2*i;
	int r = 2*i+1;
	
	if (l<=n && a[l] > a[i])
		largest = l;
	
	if (r<=n && a[r] > a[i])
		largest = r;
	
	if (largest != i) {
		
		swap(a+i, a+largest);
		max_heapify(a, largest, n);
	}
}

void build_maxheap(int *a, int n) {
	
	for (int i=n/2; i>=0; --i)
		max_heapify(a, i, n);
}

void heapsort(int *a, int n) {
	
	for (int i=n; i>0; --i) {
		
		swap(a+i, a);
		max_heapify(a, 0, i-1);
	}
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
