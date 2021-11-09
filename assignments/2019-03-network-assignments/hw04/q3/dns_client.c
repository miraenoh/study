#include "headerfiles.h"

#define SERV_PORT 8000
#define INPUTNAME "domain.txt"
#define OUTPUTNAME "result.txt"

char* readFile(FILE*, char*);
void writeFile(char*);

int main(void) {

    // Declare and define
    int s;									// socket descriptor
    int n;									// # of bytes in each recv call
    char* servName;							// server name
    int servPort = 60728;					// server port number
    struct sockaddr_in servAddr;			// server socket address
    int servAddrSize;

    char input[256];                // input string
    char* inputp = input;           // input string pointer
    char output[64];                // output string
    char* outputp = output;         // output string pointer

    // Read file
    FILE *fptr;
    fptr = fopen(INPUTNAME, "r");
    inputp = readFile(fptr, inputp);
    fclose(fptr);

    printf("input: %s\n", input);

    // Create Server Address
    memset(&servAddr, 0, sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    //inet_pton(AF_INET, servName, (struct sockaddr*)&servAddr.sin_addr);
    servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servAddr.sin_port = htons(SERV_PORT);

    // Create sockets
    if ((s = socket(PF_INET, SOCK_DGRAM, 0)) < 0) {

        perror("Error: socket creation failed!");
        exit(1);
    }

    servAddrSize = sizeof(servAddr);
    // Send the domain name to local server
    if (sendto(s, input, strlen(input), 0, (struct sockaddr*)&servAddr, servAddrSize) < 0) {
          perror("Error: sending failed!");
          exit(1);
    }

    // Recieve the ip address from local Server
    int len;
    len = recvfrom(s, outputp, sizeof(output), 0, (struct sockaddr*)&servAddr, &servAddrSize);
    output[len] = '\0';

    // Write the ip addreess on output file
    printf("ip address: %s\n", output);
    writeFile(output);

    close(s);
    return 0;
}

char* readFile(FILE *fptr, char *string) {
    memset(string, 0, sizeof(string));

    if (fptr != NULL) {
      if (!feof(fptr))
        fscanf(fptr, "%s", string);
      else
        return NULL;
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
