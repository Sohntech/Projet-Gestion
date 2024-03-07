#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>



// Fonction pour cacher le mot de passe
char getch() {
    char buf = 0;
    struct termios old = {0};
    fflush(stdout);
    if (tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    if (read(0, &buf, 1) < 0)
        perror("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0)
        perror("tcsetattr ~ICANON");
    return buf;
}



void functionAdminList(){
    FILE *Userlist = NULL; 
    Userlist = fopen("Userlist.txt","w");
    if(Userlist != NULL){
        fprintf(Userlist, "PREM passA 1\n");
        fprintf(Userlist, "SEC passB 2\n");
        fprintf(Userlist, "TER passC 2\n");
        fprintf(Userlist, "CAT passD 2\n");
        fprintf(Userlist, "SIX passE 2\n");
        
    }  
    fclose(Userlist);
}

void menuAdmin(){
    printf("    MENU DES ADMINS\n");
    printf("1.GESTION DES ÉTUDIANTS\n");
    printf("2.GÉNÉRATION DE FICHIERS\n");
    printf("3.MARQUER LES PRÉSENCES\n");
    printf("4.ENVOYER UN MESSAGE\n");
    printf("5.Quitter\n");
}

void menuApprenant(){
    printf("    MENU DES APPRENANTS\n");
    printf("1.MARQUER MA PRÉSENCE\n");
    printf("2.NOMBRE DE MINUTES D’ABSENCE\n");
    printf("3.MES MESSAGES (0)\n");
    printf("4.QUITTER\n");
}



int loginC(){
    char log[50],pass[50], log1[50], pass1[50];
    int type, type1;
    FILE *login = NULL; 
    char fullog[50];
    login = fopen("Userlist.txt","r");
    printf("******MENU DE CONNEXION******\n");
    printf("Saisissez le login\n");
    scanf("%s", log1);
    printf("Saisissez le mot de passe\n");
    char c;
    int i = 0;
    while (1) {
        c = getch();
        if (c == '\n') {
            pass1[i] = '\0';
            break;
        } else if (c == 127) { 
            if (i > 0) {
                i--;
                printf("\b \b"); 
            }
        } else {
            pass1[i++] = c;
            printf("*"); 
        }     
    }
    while (fgets(fullog, sizeof(fullog), login))
    {
        sscanf(fullog,"%s %s %d", log, pass, &type);
        if(strcmp(log1,log)==0 && strcmp(pass1,pass)==0)
        {
            if(type == 1){
                return 1;
            }
            else{
                return 2;
            }
        }
     
    }
    return 0;
}
 



