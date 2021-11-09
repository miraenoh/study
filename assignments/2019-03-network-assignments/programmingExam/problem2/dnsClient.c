// DNS program client
// LINUX Environment
/*
HOW TO RUN
*/
#include "headerFiles.h"
#define LOCAL_SERV_PORT 8000
#define GLOBAL_SERV_PORT 9000
#define FILENAME "domain.txt"

char* readFile(char *string, int *size);


int main(void) {

	// Declare variables
	int s;
	char* servName;
	struct sockaddr_in servAddr;

	// Variables for sending
	char* string;
	int len = 0;

	char buffer[1024+1];
	char *ptr = buffer;
	int maxLen = sizeof(buffer - 1);
	// for recieving
	int rLen = 0;
	char rBuffer[1024+1];
	char *rptr = rBuffer;

	// Create Server Address
	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	//inet_pton(AF_INET, servName, (struct sockaddr*)&servAddr.sin_addr);
	servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servAddr.sin_port = htons(LOCAL_SERV_PORT);

	// Create socket
	if ((s = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
		perror("Socket Creation Failed");
		exit(1);
	}


	string = readFile(string, &len);
	printf("%s\n", string);

	free(string);
	close(s);
	exit(0);
}

char* readFile(char *string, int *size) {
	
	FILE *fptr;
	fptr = fopen(FILENAME, "r");

	// Find out file's size and allocate string pointer
	fseek(fptr, 0L, SEEK_END);
	*size = ftell(fptr);
	fseek(fptr, 0L, SEEK_SET);
	string = (char*)calloc(*size, sizeof(char));

	for (int i=0; i<*size; ++i)
		fscanf(fptr, "%c", &(string[i]));

	fclose(fptr);
	return string;
}
