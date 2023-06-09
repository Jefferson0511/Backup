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
ArithmeticExpression: EXP{printf("\nCalculated Value=%d\n", $$);
		return 0;
		};

EXP:EXP'+'EXP {$$=$1+$3;}
|EXP'-'EXP {$$=$1-$3;}
|EXP'*'EXP {$$=$1*$3;}
|EXP'/'EXP {$$=$1/$3;}
|EXP'%'EXP {$$=$1%$3;}
|'('EXP')' {$$=$2;}
|EXP'^'EXP {$$=pow($1,$3);}
|EXP'+''+'{$$=$1+1;}
|EXP'-''-'{$$=$1-1;}	
|'+''+'EXP{$$=$1+1;}
|'-''-'EXP{$$=$1-1;}
|NUMBER {$$=$1;}
;

%%

void main()
{
printf("\nEnter arithmetic expression: \n");
yyparse();
if(flag==0){printf("Thank you\n");}
}

void yyerror()
{
flag=1;
}
