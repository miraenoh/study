// Chat program server
// LINUX Environment
// HOW TO RUN : enter "./chatServer" in the program folder (problem1)
// For compile, "gcc chatServer.c -o chatServer"
#include "headerFiles.h"
#define SERV_PORT 50728

int serrev(char *new, char *str, int len);

int main(void) {

	// Declare variables
	int ls;
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
	if ((ls = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
		perror("Socket Creation Failed");
		exit(1);
	}

	// Bind the listening socket
	if (bind(ls, (struct sockaddr*)&servAddr, sizeof(servAddr)) < 0) {
		perror("Binding Failed");
		close(ls);
		exit(1);
	}

	// Listen
	if (listen(ls, waitSize) < 0) {
		perror("Listening Failed");
		close(ls);
		exit(1);
	}

	clntAddrLen = sizeof(clntAddr);

	// Communication
	while(1) {

		// Accept the client
		if ((s = accept(ls, (struct sockaddr*)&clntAddr, &clntAddrLen)) < 0) {
			perror("Accepting Failed");
			close(ls);
			exit(1);
		}

		printf("connected\n");
		// Recieve the message

		// Recieve the message and send the reverse
		int n;
		while(1) {
			if ((len = recv(s, ptr, maxLen, 0)) > 0) {
				//printf("recieved\n");
				buffer[len] = '\0';

				if (strcmp(buffer, "quit") == 0) {
					close(s);
					printf("disconnected\n");
					break;
				}

				// Reverse
				serrev(sBuffer, buffer, len);

				// Send
				send(s, sBuffer, strlen(sBuffer), 0);
			}
		}
		close(s);
	}

	close(ls);
	exit(0);
}

int serrev(char *new, char *str, int len) {

	int index = 0;
	for(int i=len-1; i>=0; --i) {
		new[index] = str[i];
		++index;
	}
	new[index] = '\0';

	return 0;
}