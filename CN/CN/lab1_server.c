#include<stdio.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
#include<time.h>
#include<stdbool.h>
int prime(int n){
    int flag=0;
    for(int i=2;i<n;i++){
        if (n%i==0){
            flag=1;
            printf("hi");
            break;
        }
    }
    return flag;
}


int main(){
int sd, sd2, nsd, clilen, sport, len,i=0;
int port;
time_t ticks;
char sendmsg[100], rcvmsg[100],str[100];
struct sockaddr_in servaddr, cliaddr;
printf("Enter the server port: \n");
scanf("%d", &sport);
printf("%d", sport);
sd=socket(AF_INET,SOCK_STREAM,0);
ticks=time(NULL);
strcpy(sendmsg,ctime(&ticks));
if(sd<0)
printf("Can't create\n");
else 
printf("Socket is created\n");
servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
servaddr.sin_port=htons(sport);
sd2=bind(sd,(struct sockaddr*) &servaddr, sizeof(servaddr));
if (sd2<0)
printf("Can't bind\n");
else
printf("Binded\n");
listen(sd,5);
clilen=sizeof(cliaddr);
nsd=accept(sd,(struct sockaddr*) &cliaddr, &clilen);
if(nsd<0)
printf("can't accept\n");
else{
printf("Accepted\n");
// send(nsd,"ACK",100,0);
while(i!=1){
    recv(nsd,rcvmsg,100,0);
    printf("%s",rcvmsg);
    scanf(" %[^\n]",sendmsg);
    send(nsd,sendmsg,100,0);
}
}
}