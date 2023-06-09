#include <stdio.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
int main()
{
    int csd, cport, len;
    char sendmsg[100], revmsg[100];
    struct sockaddr_in servaddr;
    printf("Enter the port:\n");
    scanf("%d", &cport);
   
    csd = socket(AF_INET, SOCK_STREAM, 0);
    if (csd < 0)
        printf("Can't create\n");
    else
        printf("socket is created");
        printf(" at %d\n", cport);
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(cport);
    if (connect(csd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1)
        printf("Can't Connect\n");
    else
        printf("Connected successfully\n");
    int Flag = 1;
    char Hell[100];
    char CHECK[100];
    char Check_e_o[100];
    recv(csd,Check_e_o,100,0);
    while (Flag != 0)
    {
        recv(csd, revmsg, 100, 0);
        strcpy(Hell,revmsg);
        if (Hell[0] == 'S' && Hell[1] == 'P')
        {
            Flag = 0;
            break;
        }
       	int c=0;
        
        for (int i=0;i<strlen(Hell)-1;i++){ 
        if (Hell[i]=='1'){c++;}
        
        }
        
        if (Check_e_o[0]=='e'){if (c%2==0){strcpy(CHECK,"0");}else{strcpy(CHECK,"1");}}
        else if (Check_e_o[0]=='o'){if (c%2==0){strcpy(CHECK,"1");}else{strcpy(CHECK,"0");}}else{printf("Try Again\n"); continue;}

        if (CHECK[0]==revmsg[strlen(revmsg)-1]){printf("Data Received Successfully with Parity(No error): %s\n",revmsg);}else{ printf("ERROR\n");continue;}
    }
}
