// Chat program client
// LINUX Environment
/*
HOW TO RUN
(for compile, "gcc chatClient.c -o chatClient")
./chatClient
then enter the message
for termination, enter "quit"
*/
#include "headerFiles.h"
#define SERV_PORT 50728

int main(void) {

	// Declare variables
	int s;
	char* servName;
	struct sockaddr_in servAddr;

	// Variables for sending
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
	servAddr.sin_port = htons(SERV_PORT);

	// Create socket
	if ((s = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
		perror("Socket Creation Failed");
		exit(1);
	}

	// Connect to the server
	if (connect(s, (struct sockaddr*)&servAddr, sizeof(servAddr)) < 0) {
		perror("Connection Failed");
		close(s);
		exit(1);
	}

	// Send input and recieve the output
	printf("ENTER YOUR MESSAGE. ENTER quit TO FINISH.\n");
	while(1) {
		memset(buffer, 0, sizeof(*buffer));
		scanf("%s", buffer);
		send(s, buffer, strlen(buffer), 0);

		if (strcmp(buffer, "quit") == 0)
			break;

		memset(rBuffer, 0, sizeof(*rBuffer));
		rLen = 0;
		while(1) {
			if ((rLen = recv(s, rptr, maxLen, 0)) > 0)
				break;
		}
		rBuffer[rLen] = '\0';
		printf("%s\n", rBuffer);
	}

	close(s);
	exit(0);
}