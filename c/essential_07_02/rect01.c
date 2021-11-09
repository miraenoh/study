#include <stdio.h>

int main(void) {
	int rows = 5;
	int cols = 0;
	while (rows > 0) {
		cols = 5;
		while (cols > 0) {
			printf("*\t");
			cols--;
		}
		printf("\n");
		rows--;
	}

	return 0;
}