#include <iostream>
#include <stdlib.h>
#include <time.h>

/*  TEST FILE GENERATOR  */
int main(void) {
	
	int n = 0;
	std::cin >> n;
	
	FILE *test;
	test = fopen("shopping.inp", "w");
	fprintf(test,"%d\n", n);
	
	srand(time(NULL));
	for (int i=0; i<n; ++i)
		fprintf(test, "%d ", rand()%1000000);
	
	return 0;
}
