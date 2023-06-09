#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <time.h>
int prime(int n)
{
    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}
int main()
{
    int sd, sd2, nsd, clilen, sport, len, no_of = 0;
    int port;
    time_t ticks;
    char rcvmsg[20];
    struct sockaddr_in servaddr, cliaddr;
    printf("Enter the server port: \n");
    scanf("%d", &sport);
    printf("%d\n", sport);
    sd = socket(AF_INET, SOCK_STREAM, 0);
    ticks = time(NULL);
    char sendmsg[100] = "100100";
    if (sd < 0)
        printf("Can't create \n");
    else
        printf("Socket created \n");
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(sport);
    sd2 = bind(sd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    if (sd2 > 0)
        printf("Can't bind\n");
    else
        printf("Binded \n");
    listen(sd, 5);
    clilen = sizeof(cliaddr);
    nsd = accept(sd, (struct sockaddr *)&cliaddr, &clilen);
    for (int i = 0; i < 10; i++)
    {
        recv(nsd, rcvmsg, 20, 0);
        int n = atoi(rcvmsg);
        printf("%d accepted\n", n);
        if (prime(n) == 1)
            send(nsd, rcvmsg, 20, 0);
        else
            send(nsd, "Entered Num is not prime\n", 20, 0);
    }
    if (nsd < 0)
        printf("Can't accept \n");
    else
        printf("Accepted \n");
}