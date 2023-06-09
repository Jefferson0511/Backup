#include <stdio.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include<stdbool.h>
int main()
{
    int csd, cport, len,clien,sd2;
    char sendmsg[100], revmsg[100];
    struct sockaddr_in servaddr,cliaddr;
    printf("Enter the port:\n");
    scanf("%d", &cport);
   
    csd = socket(AF_INET, SOCK_DGRAM, 0);
    if (csd < 0)
        printf("Can't create\n");
    else
        printf("socket is created");
        printf(" at %d\n", cport);
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(cport);
    
    sd2=bind(csd,(struct sockaddr*) &cliaddr, sizeof(cliaddr));
    clien=sizeof(servaddr);
    int Flag = 1;
    char Hell[100];
    while (Flag != 0)
    {   
        printf("ok %s ok",revmsg);
        recvfrom(csd,revmsg,100,0,(struct sockaddr*) &servaddr, &clien);
        printf("Server: ");
        printf("%s\n",revmsg);
        
        printf("Client: ");
        scanf(" %[^\n]", Hell);
        if (Hell[0] == 'S' && Hell[1] == 'P')
        {
            Flag = 0;
            break;
        }
        strcpy(sendmsg, Hell);
        sendto(csd, sendmsg, 100, 0,(struct sockaddr*) &servaddr, clien);
    }
}
