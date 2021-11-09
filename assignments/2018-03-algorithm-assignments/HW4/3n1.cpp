#include <iostream>

#define FILENAME_INP "3n1.inp"
#define FILENAME_OUT "3n1.out"

int readFile(const char*);
void writeFile(const char*, unsigned long, unsigned long long);
unsigned long findSmall(int);
unsigned long long findLarge(int);

int main(void) {
	
	int k = readFile(FILENAME_INP);
	
	unsigned long small = findSmall(k);
	unsigned long long large = findLarge(k);
	/*
	//	CHECK
	std::cout << "k = " << k << std::endl;
	std::cout << "smallest = " << small << std::endl;
	std::cout << "Largest  = " << large << std::endl;
	//	CHECK
	*/
	writeFile(FILENAME_OUT, small, large);
	
	return 0;
}

unsigned long findSmall(int k) {
	
	unsigned long n = 1;
	
	for (unsigned long i=0; i<k; ++i) {
		if ((n-1)%3 == 0 && (n-1)/3 > 1)
			n = (n-1)/3;
		else
			n *= 2;
	}
	
	return n;
}

unsigned long long findLarge(int k) {
	
	unsigned long long n = 1;
	
	for (unsigned long i=0; i<k; ++i)
		n *= 2;
	
	return n;
}

int readFile(const char* fileName) {
	
	FILE *fptr;
	fptr = fopen(fileName, "r");
	
	unsigned long n;
	fscanf(fptr,"%d", &n);
	
	fclose(fptr);
	return n;
}

void writeFile(const char* fileName, unsigned long n1, unsigned long long n2) {
	
	FILE *fptr;
	fptr = fopen(fileName, "w");
	
	fprintf(fptr, "%lu %llu", n1, n2);
	
	fclose(fptr);
	return;
}
