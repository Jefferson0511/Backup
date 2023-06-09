#include <stdio.h>
int E();
int EP();
int F();
int T();
int TP();
char input[10];
int i;
int main(){
    scanf("%s",input);
    if(E()){
        if(input[i]=='$'){
            printf("\n string is accepted\n");
        }
        else{
            printf("\n string is not accepted");
        }
    }
    else{
        printf("\n string is not accepted");
    }
}

int E(){
    
    if(T()){
        
        if(EP()){
            return(1);
        }
        else{
            return(0);
        }   
    }
    else{
        return(0);
    }
        
}
        
int EP(){
    if(input[i]=='#'){
        i++;
        if(T()){
            if(EP()){
                return(1);
            }
            else{
                return(0);
            }
            
        }
        else{
            return(0);
        }
    }
    else{
        return(1);
    }
        
        
}
int T(){
    if(F()){
        if(TP()){
            return(1);
        }
        else{
            return(0);
        }
    }
    else{
        return(0);
    }
    
    
}

int TP(){
    if(input[i]=='&'){
        i++;
        if(F()){
            if(TP()){
                return(1);
            }
            else{
                return(0);
            }
                
        }
        else{
            return(0);
        }
    }
    else{
        return(1);
    }   
}
        
int F(){

    if(input[i] == '!'){
        i++;
        if(F()){
            return(1);
        }
        else{
            return(0);
        }

    }
    else if(input[i]=='('){
        i++;
        if(E()){
            if(input[i]==')'){
                i++;
                return(1);
            }
            else{
                return(0);
            }
        }
        else{
            return(0);
        }
    }
    else{
        if(input[i]>='a'&&input[i]<='z'||input[i]>='A'&&input[i]<='Z'){
            i++;
            return(1);
            
        }
        else{
            return(0);
        }
    }
}
