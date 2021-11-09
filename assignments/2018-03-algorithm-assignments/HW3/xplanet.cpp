#include <iostream>
#include <stdlib.h>
#include <string.h>
typedef struct {
	
	char s[4];
	int num;
} triplet;

char** readFile(int*);
void writeFile(int);
int highestAppear(char* string, triplet* triplets, int* k);


int main(void) {
	
	char** dnaStr;
	int n = 0;
	
	dnaStr = readFile(&n);
	/*
	//	check
	std::cout << n << std::endl;
	for (int i=0; i<n; ++i)
		std::cout << dnaStr[i] << std::endl;
	//	check*/
	/*
	
	for (int i=0; i<n; ++i) {
		
		int curHigh = highestAppear(dnaStr[i]);
		if (curHigh > highest)
			highest = curHigh;
	}
	*/
	triplet triplets[998];
	int k = 0;
	int highest = 0;
	for (int i=0; i<n; ++i)
		highest = highestAppear(dnaStr[i], triplets, &k);
	
	//std::cout << "Final Highest Appearence : " << highest << std::endl;
	
	writeFile(highest);
	
	return 0;
}

int highestAppear(char* string, triplet* triplets, int* k) {
	
	//int triplets[26][26][26];
	
	for (int i=0; string[i+2]!='\0';++i){
		
		char c[4] = {string[i], string[i+1], string[i+2], '\0'};
		bool isExist = false;
		
		for (int j=0; j<*k; ++j)
			if (!strcmp(c,triplets[j].s)) {
				++triplets[j].num;
				isExist = true;
				//std::cout << c << "stored in triplets " << j << std::endl; 
				break;
			}
		
		if (isExist == false) {
			strcpy(triplets[*k].s, c);
			triplets[*k].num = 1;
			//std::cout << c << "(new)stored in triplets " << *k << std::endl; 
			++*k;
			
		}
	}
	
	int high = 0;
	for (int i=0; i<*k; ++i)
		if (triplets[i].num > high)
			high = triplets[i].num;
	
	//std::cout << std::endl << "Current highest appearence : " << high << std::endl << std::endl;
	
	return high;
}

char** readFile(int *n) {
	
	FILE *fptr;
	fptr = fopen("xplanet.inp", "r");
	fscanf(fptr, "%d", n);
	
	char ** strings;
	strings = (char**)calloc(*n, sizeof(*strings));
	for (int i=0; i<*n; ++i) {
		strings[i] = (char*)calloc(1000, sizeof(**strings));
		fscanf(fptr, "%s", strings[i]);
	}
	
	fclose(fptr);
	return strings;
}

void writeFile (int input) {
	
	FILE *fptr;
	
	fptr = fopen("xplanet.out", "w");
	fprintf(fptr, "%d", input);
	
	fclose(fptr);
	return;
}
