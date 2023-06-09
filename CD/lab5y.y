%{
#include<stdio.h>
#include <math.h>
#include<ctype.h>
#include<stdlib.h>
int flag=0;
%}

%token NUMBER
%left '+' '-'
%left '*' '/' '%'
%left '(' ')'
%left '^'
%%
ArithmeticExpression: EXP;

EXP:EXP'+'EXP 
|EXP'-'EXP 
|EXP'*'EXP 
|EXP'/'EXP 
|EXP'%'EXP 
|'('EXP')' 
|EXP'^'EXP 
|EXP'+''+'
|EXP'-''-'
|'+''+'EXP
|'-''-'EXP
|NUMBER 
;

%%


void main()
{
printf("\nEnter:\n");
yyparse();
if(flag==0)
printf("\nEntered arithmetic expression is Valid\n\n");
}

void yyerror()
{
printf("\nEntered arithmetic expression is Invalid\n\n");
flag=1;
}