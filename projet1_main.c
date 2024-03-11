#include "projet1.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    int session=0;
    functionAdminList();
     while (1)
     {
        session = loginC();
        if (session == 1)
        {
            system("clear");
            menuAdmin();
            break;
        } 
        else if(session == 2){

            system("clear");
            menuApprenant();
            break;
        }
        else{
            printf("Login ou mot de passe incorrect\n");
        }
     }
     
    
    
    return 0;
} 