#include<stdio.h>
#include<stdlib.h>
void main()
{
int a;
float b;
int sum;
int x;

scanf("%d",&a);
scanf("%d",&b);
for(int i=0;i<=10;i++)
{
	sum=sum+a;
}
if(a<b) {printf("a is greater");}
else {printf("b is greater");}
printf("sum=%d",sum);
return 1;
}
