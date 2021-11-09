// TCP file transfer client program
#include "headerFiles.h"

void writeFile(char*, int);

int main(void) {

	// Declare and define
	int s;															// socket descriptor
	int n;															// # of bytes in each recv call
	char* servName;										// server name
	int servPort;											// server port number
	int len = 0;												// length of string to be echoed
	char buffer[1024+1];							// buffer
	char* ptr = buffer;								// pointer to move along the buffer
	int maxLen = sizeof(buffer);
	struct sockaddr_in servAddr;			// server socket address

	printf("Enter the port number(1398) : ");
	scanf("%d", &servPort);

	// Create remote (server) socket address
	memset((struct sockaddr*)&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	inet_pton(AF_INET, servName, (struct sockaddr*)&servAddr.sin_addr);
	servAddr.sin_port = htons(servPort);

	// Create sockets
	if ((s = socket(PF_INET, SOCK_STREAM, 0)) < 0) {

		perror("Error: socket creation failed!");
		exit(1);
	}

	// Connect to the server
	if (connect(s, (struct sockaddr*)&servAddr, sizeof(servAddr)) < 0) {

		perror("Error: connection failed!");
		exit(1);
	}
	
	// Data transfer section
	while((n = recv(s, ptr, maxLen, 0)) > 0) {
		ptr += n;
		maxLen -= n;
		len += n;
	}

	
	buffer[len] = '\0';
	writeFile(buffer, len);

	// Close socket
	close(s);

	// Stop program
	exit(0);
}

void writeFile(char* string, int size) {

	char fName[100];
	printf("Enter the name of file to save : ");
	scanf("%s", fName);

	FILE *fptr;
	fptr = fopen(fName, "w");

	for (int i=0; i<size; ++i)
		fprintf(fptr, "%c", string[i]);

	fclose(fptr);
	return;
}
