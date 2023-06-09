#include <stdio.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <time.h>
int main()
{
    int sd, sd2, nsd, clilen, sport, len;
    int port;
    time_t ticks;
    char sendmsg[100], rcvmsg[100];
    struct sockaddr_in servaddr, cliaddr;
    printf("Enter the server port: \n");
    scanf("%d", &sport);
    
    sd = socket(AF_INET, SOCK_STREAM, 0);
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
    listen(sd, 5);
    clilen = sizeof(cliaddr);
    nsd = accept(sd, (struct sockaddr *)&cliaddr, &clilen);
    if (nsd < 0)
        printf("can't accept\n");
    else
        printf("Accepted\n");
    
    printf("Even(e)/Odd(o): ");
    char Check_e_o[100];
    scanf(" %[^\n]",Check_e_o);
    send(nsd, Check_e_o, 100, 0);
    int Flag = 1;
    while (Flag != 0)
    {
        char Hell[100];
        printf("Server: ");
        scanf(" %[^\n]",Hell);
     
        if (Hell[0] == 'S' && Hell[1] == 'P')
        {   
            send(nsd, "SP", 100, 0);
            Flag = 0;
            break;
        }
        int c=0;
        int len=0;
        for (int i=0;i<strlen(Hell);i++){ 
        if (Hell[i]=='1'){c++;}
        if (Hell[i]=='1' || Hell[i]=='0'){len++;}
        }
        if (len!=strlen(Hell)){printf("Only binary Allowed\n");continue;}
        if (Check_e_o[0]=='e'){if (c%2==0){if (c%2==0){strcat(Hell,"0");}else{strcat(Hell,"1");}}}
        else if (Check_e_o[0]=='o'){if (c%2==0){strcat(Hell,"1");}else{strcat(Hell,"0");}}else{printf("Try Again\n"); break;}


        strcpy(sendmsg, Hell);
        send(nsd, sendmsg, 100, 0);
        printf("Data Sent Successfully with Parity: %s\n",sendmsg);

    }
}