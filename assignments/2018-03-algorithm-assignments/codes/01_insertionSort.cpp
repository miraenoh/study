#include <iostream>
#include <cstdlib>

using namespace std;

//	member function
void insertion_sort(int[], int);
void print_array(int[], int);

int main(void) {
	
	int array[] = {5, 4, 3, 2, 1};
	insertion_sort(array, 5);
	print_array(array, 5);
	
	return 0;
}

void insertion_sort(int arr[], int length) {
	
	for (int i=1; i<length; ++i) {
		for (int j=i; arr[j-1]>arr[j]; --j) {
			
			int tmp = arr[j];
			arr[j] = arr[j-1];
			arr[j-1] = tmp;
		}
	}
}

void print_array (int arr[], int length) {
	
	for (int i=0; i<length; ++i) {
		
		cout << arr[i] << "\t";
	}
	
	cout << endl; 
}
