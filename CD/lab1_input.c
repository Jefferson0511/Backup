#include <stdio.h>
#include <math.h>
#define PI 3.14

void main()
{
    int radius_1;
    float area_cir, perimeter;
    int i,code;
    for(i=1;i<=10;i++)
    {
        scanf("%d",&code);
        scanf("%d",&radius_1);
        if (code==1)
           {
               area_cir = PI*pow(radius_1,2);
               printf("area of the circle %f",area_cir);
           }
           else
           {
               perimeter = 2*PI*radius_1;
               printf("perimeter of the circle %f",perimeter);
           }
    }
}
