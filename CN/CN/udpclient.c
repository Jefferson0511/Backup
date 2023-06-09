#include <stdio.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <stdbool.h>
int main()
{
    int csd, cport, len, clien, sd2;
    char sendmsg[100], revmsg[100];
    struct sockaddr_in servaddr, cliaddr;
    printf("Enter the port:\n");
    scanf("%d", &cport);
    printf("%d", cport);
    csd = socket(AF_INET, SOCK_DGRAM, 0);

    if (csd < 0)
        printf("Can't create\n");
    else
        printf("socket is created\n");
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(cport);
    sd2 = bind(csd, (struct sockaddr *)&cliaddr, sizeof(cliaddr));

    clien = sizeof(servaddr);
    char msg1[100];
    printf("Client: ");
    scanf("%s", msg1);
    strcpy(sendmsg, msg1);
    sendto(csd, sendmsg, 100, 0, (struct sockaddr *)&servaddr, clien);
    while (true)
    {
        recvfrom(csd, revmsg, 100, 0, (struct sockaddr *)&servaddr, &clien);
        printf("Server: %s\n", revmsg);
        if (strcmp(revmsg, "exit") == 0)
        {
            break;
        }
        char msg[100];
        printf("Client: ");
        scanf("%s", msg);
        if (strcmp(msg, "exit") == 0)
        {
            sendto(csd, sendmsg, 100, 0, (struct sockaddr *)&servaddr, clien);
            break;
        }
        strcpy(sendmsg, msg);
        sendto(csd, sendmsg, 100, 0, (struct sockaddr *)&servaddr, clien);
    }
}
