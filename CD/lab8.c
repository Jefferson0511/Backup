//Write a C program to generate machine code using the instruction sets of 8086 microprocessor. Input for this program is quadruple form of three address code generated from Lab exercise 7.




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// convert given 3 addr to machine code

typedef struct q
{
    char op[10];
    char arg1[10];
    char arg2[10];
    char arg3[10];
} quad;

int main()
{

    FILE *fp;
    fp = fopen("3addr.txt", "r");
    char ch = fgetc(fp);
    int n;
    sscanf(&ch, "%d", &n);
    quad q[n];

    char word[10];
    int ind = 0;
    int c = 0;
    int pos = 0;
    while (fscanf(fp, "%s", word) == 1)
    {

        if (pos == 0)
        {
            // printf("%d op %s\n",ind,word);
            c++;
            strcpy(q[ind].op, word);
        }
        else if (pos == 1)
        {
            // printf("%d arg1 %s\n",ind,word);
            c++;
            strcpy(q[ind].arg1, word);
        }
        else if (pos == 2)
        {
            // printf("%d arg2 %s\n",ind,word);
            c++;
            strcpy(q[ind].arg2, word);
        }
        else if (pos == 3)
        {
            // printf("%d arg3 %s\n",ind,word);
            c++;
            strcpy(q[ind].arg3, word);
        }
        if (c == 4)
        {
            ind = ind + 1;
            c = 0;
        }
        pos = (pos + 1) % 4;
    }
    // printf("\n\n\n\n");
    printf("Given 3 addr quad code is :\n\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s %s %s %s\n", q[i].op, q[i].arg1, q[i].arg2, q[i].arg3);
    }

    printf("Its MAchine code is\n\n");

    int reg = 0;
    for (int i = 0; i < n; i++)
    {
        char opp = q[i].op[0];
        switch (opp)
        {
        case '+':
            printf("LOAD R%d %s\n", reg, q[i].arg1);
            printf("LOAD R%d %s\n", reg + 1, q[i].arg2);
            printf("ADD R%d R%d\n", reg, reg + 1);
            printf("STORE %s %d\n", q[i].arg3, reg);
            break;
        case '-':
            printf("LOAD R%d %s\n", reg, q[i].arg1);
            printf("LOAD R%d %s\n", reg + 1, q[i].arg2);
            printf("SUB R%d R%d\n", reg, reg + 1);
            printf("STORE %s %d\n", q[i].arg3, reg);
            break;
            break;
        case '*':
            printf("LOAD R%d %s\n", reg, q[i].arg1);
            printf("LOAD R%d %s\n", reg + 1, q[i].arg2);
            printf("MUL R%d R%d\n", reg, reg + 1);
            printf("STORE %s %d\n", q[i].arg3, reg);
            break;
        case '/':
            printf("LOAD R%d %s\n", reg, q[i].arg1);
            printf("LOAD R%d %s\n", reg + 1, q[i].arg2);
            printf("DIV R%d R%d\n", reg, reg + 1);
            printf("STORE %s %d\n", q[i].arg3, reg);
            break;
        case '=':
            printf("LOAD R%d %s\n", reg, q[i].arg1);
            printf("STORE %s %d\n", q[i].arg3, reg);
            break;
        case '>':
            printf("LOAD R%d %s\n", reg, q[i].arg1);
            printf("LOAD R%d %s\n", reg + 1, q[i].arg2);
            printf("JGT R%d R%d %s\n", reg, reg + 1, q[i].arg3);
            break;
        case '<':
            printf("LOAD R%d %s\n", reg, q[i].arg1);
            printf("LOAD R%d %s\n", reg + 1, q[i].arg2);
            printf("JLT R%d R%d %s\n", reg, reg + 1, q[i].arg3);
            break;
        case 'g': // if op is goto
            printf("JMP %s\n", q[i].arg3);
            break;
        case 'p': // if op is print
            printf("OUT %s\n", q[i].arg3);
            break;
        default:
            printf("Invalid quad\n");
            break;
        }
        printf("\n");
    }
    printf("\n\n3 ADDR TO MACHINE DONE\n\n");
    return 0;
}
