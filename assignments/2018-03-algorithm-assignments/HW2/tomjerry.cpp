#include <iostream>

void readFile (long long*, long long*);
void writeFile (int);
int findNPaths (long long, long long);
long long fact (long long);

int main (int argc, const char* argv[]) {
	
	long long r = 0, c = 0;
	
	readFile(&r, &c);
	
	int nPaths = findNPaths(r, c);
	
	//	check
	//std::cout << "r : " << r << ", c : " << c << std::endl << "paths : " << nPaths << std::endl;
	
	writeFile(nPaths);
	
	return 0;
}

void readFile (long long *r, long long *c) {
	
	FILE *fptr;
	fptr = fopen("tomjerry.inp", "r");
	fscanf(fptr,"%lld%lld", r, c);
	
	fclose(fptr);
	return;
}

void writeFile (int input) {
	
	FILE *fptr;
	
	fptr = fopen("tomjerry.out", "w");
	fprintf(fptr, "%d", input);
	
	fclose(fptr);
	
	return;
}

int findNPaths (long long r, long long c) {
	
	//std::cout << fact(r+c-2) << " " << fact(r-1) << " " << fact(c-1) << " " << std::endl;
	
	return fact(r+c-2)/(fact(r-1)*fact(c-1));
}

long long fact (long long n) {
	
	if (n>1)
		return n*fact(n-1);
	else
		return n;
}
