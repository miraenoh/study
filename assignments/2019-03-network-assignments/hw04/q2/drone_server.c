#include "headerfiles.h"

#define SERV_PORT 60728
#define FILENAME "position.txt"

#define UP "Move_UP"
#define DOWN "Move_DOWN"
#define LEFT "Move_LEFT"
#define RIGHT "Move_RIGHT"

void calPosition(int*, int, int);

int main(void) {

    // Declare variables
    int ls;
    int s;
    int waitSize = 16;
    struct sockaddr_in servAddr;
    struct sockaddr_in clntAddr;
    int clntAddrLen;

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

    // Recieve commands, calculate the position, and send it
	char cmd[32];
	char* cmdptr = cmd;
	char str[32];
	char* strptr = str;
	int len = 0;
	int position[2] = {5, 5};
	FILE* wfile;
	while (1) {
        memset(cmdptr, 0, sizeof(cmdptr));
        if ((len = recv(s, cmdptr, sizeof(cmd), 0)) <= 0)
            break;
        cmd[len] = '\0';
        printf("%s, %d\n", cmd, (int)strlen(cmd));
        if (!strcmp(cmd, UP))
            calPosition(position, 0, -1);
        else if (!strcmp(cmd, DOWN))
            calPosition(position, 0, 1);
        else if (!strcmp(cmd, LEFT))
            calPosition(position, -1, 0);
        else if (!strcmp(cmd, RIGHT))
            calPosition(position, 1, 0);
        else
            continue;
        printf("(%d,%d)\n", position[0], position[1]);
        sprintf(str, "(%d,%d)\n", position[0], position[1]);
        send(s, str, strlen(str), 0);
	}

	close(s);
	close(ls);
	return 0;
}

void calPosition(int* position, int varx, int vary) {
    int newx = position[0] + varx;
    int newy = position[1] + vary;

    if (newx >= 1 && newx <= 10)
        position[0] = newx;
    if (newy >= 1 && newy <= 10)
        position[1] = newy;
}