#include "headerfiles.h"

#define SERV_PORT 9000
#define FILENAME_EDU "global_edu_dns.txt"
#define FILENAME_COM "global_com_dns.txt"

char* findDomain(char *string, char *fname);

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

    char input[256];
    char* inputp = input;
    int inputLen;
    int len;
    // Recieve the domain, find, return
  	while (1) {

          // Accept connections from client
          if((s = accept(ls, (struct sockaddr*)&clntAddr, &clntAddrLen)) < 0) {

              perror("Error: Accepting failed!");
              exit(1);
          }
          printf("Connetcion with a client\n");

          memset(inputp, 0, sizeof(inputp));
          if ((len = recv(s, inputp, sizeof(input), 0)) <= 0)
              break;
          input[len] = '\0';

          // find the domain
          char output[128];
          char* outputp = output;
          outputp = findDomain(input, FILENAME_EDU);
          if (outputp == NULL)
            outputp = findDomain(input, FILENAME_COM);
          if (outputp == NULL)
            outputp = "Not found";

          if (send(s, outputp, strlen(outputp), 0) < 0)
            printf("Send failed\n");
          else
            printf("sent!\n");
  	}

  	close(s);
  	close(ls);
  	return 0;
}

char* findDomain(char *string, char *fname) {

    char *buffer;
    int size;
    int count;

    FILE *fptr = fopen(fname, "r");

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
        str = strtok(NULL, " \n");
        printf("found! %s\n", str);
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
