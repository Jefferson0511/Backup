#include <stdio.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <time.h>
#include<stdbool.h>
int main()
{
    int sd, sd2,clien, sport, len;
    int port;
    time_t ticks;
    char sendmsg[100], rcvmsg[100];
    struct sockaddr_in servaddr, cliaddr;
    printf("Enter the server port: \n");
    scanf("%d", &sport);
    
    sd = socket(AF_INET, SOCK_DGRAM, 0);
    ticks = time(NULL);

    if (sd < 0)
        printf("Can't create\n");
    else
        printf("Socket is created");
        printf(" at %d\n", sport);
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(sport);
    sd2 = bind(sd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    if (sd2 < 0)
        printf("Can't bind\n");
    else
        printf("Binded\n");
    clien = sizeof(cliaddr);

    int Flag = 1;
    while (Flag != 0)
    {
        char Hell[100];
        printf("Server: ");
        scanf(" %[^\n]",Hell);
        if (Hell[0] == 'S' && Hell[1] == 'P')
        {
            Flag = 0;
            break;
        }
        strcpy(sendmsg, Hell);
        //send(nsd, sendmsg, 100, 0);
        sendto(sd, sendmsg, 100, 0,(struct sockaddr*) &cliaddr, clien);
        printf("Client: ");
        //recv(nsd, rcvmsg, 100, 0);
        sendto(sd, sendmsg, 100, 0,(struct sockaddr*) &cliaddr, clien);
        printf("%s\n", rcvmsg);
    }
}
