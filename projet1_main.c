#include "projet1.h"
#include <stdio.h>

int main(){
    int session=0;
     while (1)
     {
        session = loginC();
        if (session == 1)
        {
            menuAdmin();
        } 
        else if(session == 2){
            menuApprenant();
        }
        else{
            printf("Login ou mot de passe incorrect\n");
        }
     }
    
    
    return 0;
}