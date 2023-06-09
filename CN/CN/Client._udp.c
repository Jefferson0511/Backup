#include <stdio.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
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
    int csd, cport, len, no_of = 0;
    int arr[10];
    char sendmsg[100], revmsg[100], l1[2];
    strcpy(l1, "1");
    struct sockaddr_in servaddr;
    printf("Enter the port: \n");
    scanf("%d", &cport);
    printf("%d\n", cport);
    csd = socket(AF_INET, SOCK_STREAM, 0);
    if (csd < 0)
        printf("Can't create \n");
    else
        printf("Socket is created\n");
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(cport);

    if (connect(csd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
        printf("Can't connect\n");
    else
        printf("Connected successfully\n");
    printf("Enter 10 numbers:\n");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
        char c[20];
        sprintf(c, "%d\n", arr[i]);
        send(csd, c, 20, 0);
        char c1[20];
        recv(csd, c1, 20, 0);
        printf("%s\n", c1);
    }
}