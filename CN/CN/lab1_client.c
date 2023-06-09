#include<stdio.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
#include<stdbool.h>
int main(){
int csd,cc,cport,len,i=0,n;
char sendmsg[100],revmsg[100];
struct sockaddr_in servaddr;
printf("Enter the port:\n");
scanf("%d", &cport);
printf("%d", cport);
csd=socket(AF_INET,SOCK_STREAM,0);
if(csd<0)
printf("Can't create\n");
else
printf("socket is created\n");
servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
servaddr.sin_port=htons(cport);
cc=connect(csd,(struct sockaddr*) &servaddr, sizeof(servaddr));
if(cc<0)
printf("Can't Connect\n");
else{
printf("Connected successfully\n");
char str[100];
while(i!=1){
    scanf(" %[^\n]",str);
    send(csd,str,100,0);
    recv(csd,revmsg,100,0);
    printf("%s",revmsg);

}
}
}
