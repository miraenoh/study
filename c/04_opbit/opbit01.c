#include <stdio.h>

int main(void) {

	int nData = 0x11223344;

	printf("%08X\n", nData);
	printf("%08X\n", nData & 0x00FFFF00);
	printf("%08X\n", nData | 0x2211FFFF);
	printf("%08X\n", nData ^ 0x2211FFFF);
	printf("%08X\n", ~nData);
	printf("%08X\n", nData >> 8);
	printf("%08X\n", nData << 16);

	return 0;
}