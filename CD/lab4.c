
#include <stdio.h>
#include <string.h>

char prod[8][10] = {"E->TX", "X->+TX", "X->#","T->FY","Y->*FY", "Y->#","F->(E)","F->i"};
char table[5][6][10] = {{"TX"," "," ","TX"," "," "},
{" ","+TX"," "," ","#","#"},
{"FY"," "," ","FY"," "," "},
{" ","#","*FY"," ","#","#"},
{"i"," "," ","(E)"," "," "}};

int top = -1;
char stack[50];
void push(char c){
    top++;
    stack[top] = c;
}
void pop(){
    top--;

}
void show(){
    for (int i = top; i >= 0; --i)
            printf("%c", stack[i]);
}

int numr(char c)
{
   switch (c)
   {
    case 'E':
        return 0;
 
    case 'X':
        return 1;
 
    case 'T':
        return 2;
 
    case 'Y':
        return 3;
    case 'F':
    return 4;
    case 'i': return 0;
    case '+': return 1;
    case '*': return 2;
    case '(': return 3;
    case ')':return 4;
    case '$': return 5;
   }
 
   return (2);
}

void revstr(char *str1)  {   
    int i, len, temp;  
    len = strlen(str1);  
    for (i = 0; i < len/2; i++)  {  
        temp = str1[i];  
        str1[i] = str1[len - i - 1];  
        str1[len - i - 1] = temp;  
    }  
}  


int main(){
    for(int i=0;i<8;i++){
        printf("%s\n",prod[i]);
    }
    printf("\n");
    char input[10]= "i+i*i+i$";
    char input1[10];
    strcpy(input1,input);
    push('$');
    push('E');
    char x = stack[top];
    int k=0;
    char token = input[k];
    printf("Stack                    Input                     Output\n");
    printf("--------------------------------------------------------------\n");
    while(x!='$'){
        show();
        printf("                        ");
        int d= k;
        while(input[d]!='\0'){
            printf("%c", input[d]);
            d++;
        }
        printf("                        ");
        if(x=='(' || x==')' || x== 'i'|| x=='+' || x=='$'
        || x=='*'){
            if(x==token){
                pop();
                k++;
                token= input[k];
                printf("\n");
            }
            else{
                printf("error");
                break;
            }
        }
        else{
            char rem[10], rem1[10];
            strcpy(rem, table[numr(x)][numr(token)]);
            strcpy(rem1,rem);
            revstr(rem);
            if(rem[0]=='#'){
                pop();
                printf("%c->ep\n", x);
            }
            else if(rem[0]==' '){
                printf("error");
                break;
            }
            else
            {int temp=strlen(rem);
            int r=0;
            pop();
            while(temp!=0){
                push(rem[r]);
                r++;
                temp--;
            }
            printf("%c->%s\n", x, rem1);
            }
        }
        x=stack[top];
    }
    if(stack[top]=='$'){
        printf("\nString accepted");
    }
    else{
        printf("\nString not accepted");
    }
}