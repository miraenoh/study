#include <iostream>
#include <stdlib.h>
#include <time.h>

/*  TEST FILE GENERATOR  */
int main(void) {
	
	int m = 0, n = 0;
	std::cin >> m >> n;
	
	FILE *test;
	test = fopen("universe.inp", "w");
	fprintf(test,"%d %d\n", m, n);
	
	srand(time(NULL));
	for (int i=0; i<m; ++i) {
		
		for (int j=0; j<n; ++j)
			fprintf(test, "%d ", rand()%1000000);
		fprintf(test, "\n");
		for (int j=0; j<n; ++j)
			fprintf(test, "%d ", rand()%1000000);
		fprintf(test, "\n");
	}
	
	return 0;
}
