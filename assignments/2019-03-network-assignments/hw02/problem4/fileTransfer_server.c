//	TCP file transfer server program
#include "headerFiles.h"

#define SERV_PORT 1398
#define FILENAME "send"

char* readFile(char*, int*);

int main(void) {

	// Declare and define
	int ls;													// listen socket descriptor
	int s;													// socket descriptor
	int len = 0;											// # of bytes to send or recieve
	int n = 0;												// # of bytes for each recv call
	int waitSize = 16;								// size of waiting clients
	struct sockaddr_in servAddr;		// server address(local)
	struct sockaddr_in clntAddr;		// client address(remote)
	int clntAddrLen;								// length of client address

	char* contents;

	// Read the file to send
	contents = readFile(contents, &len);

	// Create local(server) socket address
	memset(&servAddr, 0, sizeof(servAddr));	// all set by 0
	servAddr.sin_family = AF_INET;	
	servAddr.sin_addr.s_addr = htonl(INADDR_ANY);	//	default ip address
	servAddr.sin_port = htons(SERV_PORT);				// default port

	// Create listen socket
	if ((ls = socket(PF_INET, SOCK_STREAM, 0)) < 0) {

		perror("Error: Listen socket failed!");
		exit(1);
	}

	// Bind listen socket to the local socket address
	if (bind(ls, (struct sockaddr*)&servAddr, sizeof(servAddr)) < 0) {

		perror("Error: Binding failed!");
		exit(1);
	}

	// Listen to connection requests
	if (listen(ls, waitSize) < 0) {

		perror("Error: Listening failed!");
		exit(1);
	}

	clntAddrLen = sizeof(clntAddr);

	// Accept connections from client
	if((s = accept(ls, (struct sockaddr*)&clntAddr, &clntAddrLen)) < 0) {

		perror("Error: Accepting failed!");
		exit(1);
	}
	printf("Connetcion with a client\n");

	// Send the file data
	send(s, contents, len, 0);

	// Close sockets
	close(s);
	close(ls);

	free(contents);
	return 0;
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

