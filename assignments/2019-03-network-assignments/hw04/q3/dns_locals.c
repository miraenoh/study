#include "headerfiles.h"

#define LOCAL_PORT 8000
#define GLOBAL_PORT 9000
#define FILENAME "local_dns.txt"

char* findDomain(char *string);

int main(void) {

    // Declare variables
    int udps;
    int waitSize = 16;
    struct sockaddr_in localAddr;
    struct sockaddr_in clntAddr;
    int clntAddrLen;

    char input[256];                // input string
    char* inputp = input;           // input string pointer
    int inputLen;

    // Create local socket address
    memset(&localAddr, 0, sizeof(localAddr));	// all set by 0
    localAddr.sin_family = AF_INET;
    localAddr.sin_addr.s_addr = htonl(INADDR_ANY);	//	default ip address
    localAddr.sin_port = htons(LOCAL_PORT);				// default port

    // Create a udp socket
    if ((udps = socket(PF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Error: UDP socket failed!");
        exit(1);
    }

    if (bind(udps, (struct sockaddr*)&localAddr, sizeof(localAddr)) < 0) {
      perror("Error: bind failed!");
      exit(1);
    }

    clntAddrLen = sizeof(clntAddr);
    while (1) {
        inputLen = recvfrom(udps, inputp, sizeof(input), 0, (struct sockaddr*)&clntAddr, &clntAddrLen);
        input[inputLen] = '\0';

        // Check if the domain exists
        printf("domain: %s\n", input);

        char* outputp;
        outputp = findDomain(input);
        // If not exists, request it to global server
        if (outputp == NULL) {

          char output[128];
          outputp = output;

          int tcps;
          struct sockaddr_in globalAddr;

          // Create global server Address
          memset(&globalAddr, 0, sizeof(globalAddr));
          globalAddr.sin_family = AF_INET;
          globalAddr.sin_addr.s_addr = htonl(INADDR_ANY);
          globalAddr.sin_port = htons(GLOBAL_PORT);

          // Create sockets
          if ((tcps = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
              perror("Error: socket creation failed!");
              exit(1);
          }
          // Connect to the global server
          if (connect(tcps, (struct sockaddr*)&globalAddr, sizeof(globalAddr)) < 0) {
              perror("Error: connection failed!");
              exit(1);
          }
          // send the domain
          send(tcps, input, strlen(input), 0);
          // recv the ip address or "Not found" message
          int len;
          memset(outputp, 0, sizeof(outputp));
          len = recv(tcps, outputp, sizeof(output), 0);
          output[len] = '\0';

          close(tcps);
        }
        printf("output: %s\n", outputp);

        if (sendto(udps, outputp, strlen(outputp), 0, (struct sockaddr*)&clntAddr, clntAddrLen) < 0) {
          perror("Error: sending failed!");
          exit(1);
        }
    }

  	close(udps);
  	// close(ls);
  	return 0;
}

char* findDomain(char *string) {

    char *buffer;
    int size;
    int count;

    FILE *fptr = fopen(FILENAME, "r");

    fseek(fptr, 0, SEEK_END);
    size = ftell(fptr);

    buffer = malloc(size + 1);
    memset(buffer, 0, size + 1);

    fseek(fptr, 0, SEEK_SET);
    count = fread(buffer, size, 1, fptr);

    char* str;
    str = strtok(buffer, " \n");
    while(str != NULL) {
      if(!strcmp(str, string)) {
        printf("found!\n");
        str = strtok(NULL, " \n");
        fclose(fptr);
        free(buffer);
        return str;
      }
      str = strtok(NULL, " \n");
    }

    printf("not found!\n");
    fclose(fptr);
    free(buffer);
    return NULL;
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
