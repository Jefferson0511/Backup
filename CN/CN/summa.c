#include <stdio.h>
#include <string.h>
int main(){
    int Flag = 1;
    while (Flag != 0)
    {
        char Hell[100];
        printf("Server:");
        char okk[10];
        scanf("%s",okk);
        if (okk[0] == 'S' && okk[1] == 'P')
        {
            Flag = 0;
        }
        printf("okok: k%sk%zu\n",okk,strlen(okk));
    }
}