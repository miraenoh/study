#include "headerfiles.h"

#define SERV_PORT 60728
#define INPUTNAME "moves.txt"
#define OUTPUTNAME "position.txt"

char* readLine(FILE*, char*);
void writeFile(char*);

int main(void) {

    // Declare and define
    int s;									// socket descriptor
    int n;									// # of bytes in each recv call
    char* servName;							// server name
    int servPort = 60728;					// server port number
    struct sockaddr_in servAddr;			// server socket address

    // Create Server Address
    memset(&servAddr, 0, sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    //inet_pton(AF_INET, servName, (struct sockaddr*)&servAddr.sin_addr);
    servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servAddr.sin_port = htons(SERV_PORT);

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

    // Read file and send each command
    char cmd[32];
    char* cmdptr = cmd;
    char str[32];
    char* strptr = str;
    FILE *fptr;
    fptr = fopen(INPUTNAME, "r");
    while (cmdptr = readLine(fptr, cmdptr)) {
        if (strlen(cmdptr) > 1) {

            if (cmd[strlen(cmd)-1] == '\n') {
                cmd[strlen(cmd)-1] = '\0';
                cmd[strlen(cmd)-1] = '\0';
            }
            /*
            else
                cmd[strlen(cmd)] = '\0';*/
            printf("command: %s\n", cmd);
            send(s, cmd, strlen(cmd), 0);
            recv(s, strptr, sizeof(str), 0);
            printf("recieve: %s\n", str);
            writeFile(str);
        }
    }
    printf("command done.\n");

    fclose(fptr);
    close(s);
    return 0;
}

char* readLine(FILE *fptr, char *string) {
    memset(string, 0, sizeof(string));

    if (fptr != NULL) {
        if (!feof(fptr)) {
            string = fgets(string, 32, fptr);
            return string;
        } else {
            return NULL;
        }
    } else {
        perror("Error: File not exist");
        exit(1);
    }
}

void writeFile(char* str) {

    FILE *fptr;
    fptr = fopen(OUTPUTNAME, "w");

    fprintf(fptr, "%s", str);

    fclose(fptr);

    return;
}
