#include <iostream>
#include <cstdlib>

using namespace std;

//	member function
void merge(int[], int, int, int);
void merge_sort(int[], int, int);
void print_array(int[], int);

int main(void) {
	
	int len = 50;
	
	int array[len];
	for (int i=0; i<len; ++i)
		array[len-i-1] = i;
	
	print_array(array, len);
	merge_sort(array, 0, len);
	print_array(array, len);
	
	return 0;
}

void merge (int a[], int low, int mid, int high) {
	
	int b[50];
	int x=low, y=mid+1;
	int i = low; 		//pointer C
	
	for (; x<=mid && y<=high; ++i) {
		
		if (a[x] <= a[y]) {
			
			b[i] = a[x];
			++x;
		}
		else {
			
			b[i] = a[y];
			++y;
		}
	}
	
	if (x>mid)
		for (int k=y; k<=high; ++k) {
			
			b[i] = a[k];
			++i;
		}
	else {
		for (int k=x; k<=mid; ++k) {
			
			b[i] = a[k];
			++i;
		}
	}
	
	//	copying b[] to a[]
	for (int k=low; k<=high; ++k)
		a[k] = b[k];
}

void merge_sort(int arr[], int low, int high) {
	
	int mid = (low+high)/2;
	
	if (low<high) {
		
		merge_sort(arr, low, mid);
		merge_sort(arr, mid+1, high);
		merge(arr, low, mid, high);
	}
}

void print_array (int arr[], int length) {
	
	for (int i=0; i<length; ++i) {
		
		cout << arr[i] << "\t";
	}
	
	cout << endl; 
}
