#include <stdio.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
int main()
{
    int sd, sd2, sport, len;
    int port, clien;
    time_t ticks;
    char sendmsg[100], rcvmsg[100];
    struct sockaddr_in servaddr, cliaddr;
    printf("Enter the server port: \n");
    scanf("%d", &sport);
    printf("%d", sport);
    sd = socket(AF_INET, SOCK_DGRAM, 0);
    ticks = time(NULL);
    strcpy(sendmsg, ctime(&ticks));
    strcpy(sendmsg, "Hello world");
    if (sd < 0)
        printf("Can't create\n");
    else
        printf("Socket is created\n");
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(sport);
    sd2 = bind(sd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    if (sd2 < 0)
        printf("Can't bind\n");
    else
        printf("Binded\n");

    clien = sizeof(cliaddr);

    while (true)
    {
        recvfrom(sd, rcvmsg, 100, 0, (struct sockaddr *)&cliaddr, &clien);
        printf("Client: %s\n", rcvmsg);
        if (strcmp(rcvmsg, "exit") == 0)
        {
            break;
        }
        char msg[100];
        printf("Server: ");
        scanf("%s", msg);
        if (strcmp(msg, "exit") == 0)
        {
            sendto(sd, sendmsg, 100, 0, (struct sockaddr *)&cliaddr, clien);
            break;
        }
        strcpy(sendmsg, msg);
        sendto(sd, sendmsg, 100, 0, (struct sockaddr *)&cliaddr, clien);
        printf("Client: ");
        printf("%s\n", rcvmsg);
    }
}
