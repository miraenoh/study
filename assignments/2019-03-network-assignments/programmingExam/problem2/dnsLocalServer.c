// Chat program server
// LINUX Environment
// HOW TO RUN : enter "./chatServer" in the program folder (problem1)
// For compile, "gcc chatServer.c -o chatServer"
#include "headerFiles.h"
#define SERV_PORT 50728

int serrev(char *new, char *str, int len);

int main(void) {

	// Declare variables
	int s;
	int waitSize = 16;
	struct sockaddr_in servAddr;
	struct sockaddr_in clntAddr;
	int clntAddrLen;

	// Variables for recieving
	int len = 0;
	char buffer[1024+1];
	char *ptr = buffer;
	int maxLen = sizeof(buffer);
	// Variables for sending
	int sLen = 0;
	char sBuffer[1024+1];

	// Create the listening socket
	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servAddr.sin_port = htons(SERV_PORT);
	if ((s = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
		perror("Socket Creation Failed");
		exit(1);
	}

	// Bind the listening socket
	if (bind(s, (struct sockaddr*)&servAddr, sizeof(servAddr)) < 0) {
		perror("Binding Failed");
		close(s);
		exit(1);
	}

	close(s);
	exit(0);
}