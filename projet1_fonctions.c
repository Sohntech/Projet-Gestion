#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const char ADMIN_PASSWORD[] = "adminpass";

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
        fprintf(Userlist, "Wane adminpassword 1\n");
        fprintf(Userlist, "Lamine passB 2\n");
        fprintf(Userlist, "Astou passC 2\n");
        fprintf(Userlist, "Bamba passD 2\n");
        fprintf(Userlist, "Aly passE 2\n");
        fprintf(Userlist, "Marie passF 2\n");
        fprintf(Userlist, "Alioune passG 2\n");
        fprintf(Userlist, "Soda passH 2\n");
        fprintf(Userlist, "Saer passI 2\n");
        fprintf(Userlist, "Pape passJ 2\n");
        fprintf(Userlist, "Wahab passK 2\n");
        
    }  
    fclose(Userlist);
}
    

void marquePresenceApr();
int loginC();

int menuApprenant(){
    printf("*****MENU DES APPRENANTS*****\n");
    printf("1.MARQUER MA PRÉSENCE\n");
    printf("2.NOMBRE DE MINUTES D’ABSENCE\n");
    printf("3.MES MESSAGES (0)\n");
    printf("4.QUITTER\n");
    int choix;
    do {
        printf("Saisissez entre 1 et 4 pour lancer une des 4 options ci-dessus : ");
        scanf("%d", &choix);
        if(choix < 1 || choix > 4){
            printf("\033[0;31m");
            printf("Saisie incorrecte ! Veuillez saisir un nombre compris entre 1 et 5 \n");
            printf("\033[0m");
        }
        while (getchar() != '\n');
    }while (choix < 1 || choix > 4);
    if(choix == 1){
       system("clear");
       marquePresenceApr();
    }
     if(choix == 4){
       system("clear");
       printf("Vous avez quitté l'application!\n");  
    }

    return choix;
}

int menuAdmin();

void marquePresenceAd() {
     char pass1[50];
    char log[50];
    char pass[50];
    char ligne[100];
    int x = 0;
    FILE *login = fopen("Userlist.txt", "r");
    FILE *presenceFile = fopen("PresenceList.txt", "a");

    if (login == NULL || presenceFile == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }
    
            
    //system("clear"); 
    printf("******MARQUER LES PRÉSENCES******\n");
    printf("Saisissez le code d'étudiant (Q pour quitter) :\n");
    scanf("%s", pass1);

    // Vérifier si l'utilisateur veut quitter
    if (toupper(pass1[0]) == 'Q') {
        char adminPass[50];
        printf("Confirmez avec le mot de passe de l'ADMIN :\n");
        int i = 0; 
        char c;
    while (1) {
        c = getch();
        if (c == '\n') {
            adminPass[i] = '\0';
            break;
        } else if (c == 127) { 
            if (i > 0) {
                i--;
                printf("\b \b"); 
            }
        } else {
            adminPass[i++] = c;
            printf("*"); 
        }     
    }

        if (strcmp(adminPass, ADMIN_PASSWORD) == 0) {
            system("clear");
            menuAdmin();
            fclose(login);
            fclose(presenceFile);
            return;
        } else {
            system("clear");
            printf("Mot de passe de l'ADMIN incorrect. Réessayez.\n");
            fclose(login);
            fclose(presenceFile);
            marquePresenceAd(); // Retourner dans la boucle pour demander le code d'étudiant
            return;
        }
    }

    // Revenir au début du fichier
    fseek(login, 0, SEEK_SET);

    while (fgets(ligne, sizeof(ligne), login)) {
        sscanf(ligne, "%s %s", log, pass);
        if (strcmp(pass, pass1) == 0) {
            x = 1;
            time_t t;
            struct tm *tm_info;
            time(&t);
            tm_info = localtime(&t);

            system("clear");
            printf("Code correct! Etudiant marqué présent.\n");
            fprintf(presenceFile, "L'etudiant %s ayant comme pass %s est présent le %02d/%02d/%d à %02d:%02d:%02d\n", log, pass, tm_info->tm_mday, tm_info->tm_mon + 1, tm_info->tm_year + 1900, tm_info->tm_hour, tm_info->tm_min, tm_info->tm_sec);
        }
    }
     
    // Si le code d'étudiant n'est pas trouvé dans le fichier
    if (x == 0) {
        system("clear"); 
        printf("Code incorrect. Veuillez réessayer.\n");
        fclose(login);
        fclose(presenceFile);
        marquePresenceAd(); // Retourner dans la boucle pour demander le code d'étudiant
        return;
    }

    fclose(login);
    fclose(presenceFile);
    marquePresenceAd();
   
} 

void marquePresenceApr(){
    char pass1[50];
    char log[50];
    char log1[50];
    char pass[50];
    char ligne[100];
    int x = 0;
    FILE *login = fopen("Userlist.txt", "r");
    FILE *presenceFile = fopen("PresenceList.txt", "a");

    if (login == NULL || presenceFile == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }
    
            
    //system("clear"); 
    printf("******MARQUER MA PRÉSENCE******\n");
    printf("Saisissez votre code d'étudiant:\n");
    scanf("%s", pass1);
     while (fgets(ligne, sizeof(ligne), login)) {
        sscanf(ligne, "%s %s", log, pass);
        if (strcmp(pass, pass1) == 0) {
            x = 1;
            time_t t;
            struct tm *tm_info;
            time(&t);
            tm_info = localtime(&t);

            system("clear");
            printf("Le marquage de votre présence est reussie.\n");
            fprintf(presenceFile, "L'etudiant %s ayant comme pass %s est présent le %02d/%02d/%d à %02d:%02d:%02d\n", log, pass, tm_info->tm_mday, tm_info->tm_mon + 1, tm_info->tm_year + 1900, tm_info->tm_hour, tm_info->tm_min, tm_info->tm_sec);
            
            

        }
    }
     
    // Si le code d'étudiant n'est pas trouvé dans le fichier
    if (x == 0) {
        system("clear"); 
        printf("Vous n'avez pas saisi votre bon code. Veuillez réessayer.\n");
        fclose(login);
        fclose(presenceFile);
        marquePresenceApr(); // Retourner dans la boucle pour demander le code d'étudiant
        return;
    }

    

    fclose(login);
    fclose(presenceFile);
    printf("Retour au menu précédent en cours...\n");
    sleep(2);
    system("clear");
    menuApprenant();

}


void marquePresenceAd();
void generatePresenceTable();

int menuAdmin(){
    printf("****MENU DES ADMINS****\n");
    printf("1.GESTION DES ÉTUDIANTS\n");
    printf("2.GÉNÉRATION DE FICHIERS\n");
    printf("3.MARQUER LES PRÉSENCES\n");
    printf("4.ENVOYER UN MESSAGE\n");
    printf("5.Quitter\n");
    int choix;
    do {
        printf("Saisissez entre 1 et 5 pour lancer une des 5 options ci-dessus : ");
        scanf("%d", &choix);
        if(choix < 1 || choix > 5){
            printf("\033[0;31m");
            printf("Saisie incorrecte ! Veuillez saisir un nombre compris entre 1 et 5 \n");
            printf("\033[0m");
        }
        while (getchar() != '\n');
    }while (choix < 1 || choix > 5);
    if(choix == 3){
       system("clear");
       marquePresenceAd();
    }
    if(choix == 5){
       system("clear");
       printf("Vous avez quitté l'application!\n");
    }
      if(choix == 2){
       system("clear");
       printf("****************MENU GÉNÉRATION FICHIER******************\n");
       printf("1.GÉNÉRER LE FICHIER DE PRÉSENCE DU JOUR DES ÉTUDIANTS\n");
       printf("2.GÉNÉRER LE FICHIER DE PRÉSENCE DES ÉTUDIANTS PAR DATE\n");
       printf("3.GÉNÉRER LE FICHIER DE PRÉSENCE DES ÉTUDIANTS PAR CLASSE\n");
        do {
        printf("Saisissez entre 1 et 3 pour lancer une des 3 options ci-dessus : ");
        scanf("%d", &choix);
        if(choix < 1 || choix > 3){
            printf("\033[0;31m");
            printf("Saisie incorrecte ! Veuillez saisir un nombre compris entre 1 et 3 \n");
            printf("\033[0m");
        }
         while (getchar() != '\n');
        }while (choix < 1 || choix > 3);
        if(choix == 1){
        system("clear");
        generatePresenceTable();
        }


    }

    return choix;

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
        }else {
            pass1[i++] = c;
            printf("*"); 
        }     
    }
    
   while (fgets(fullog, sizeof(fullog), login)) {
    sscanf(fullog, "%s %s %d", log, pass, &type);
    if (strcmp(log1, log) == 0 && strcmp(pass1, pass) == 0) {
        if (type == 1) {
            return 1;
            break;
        } else {
            return 2;
            break;
        }
    }
     else if(strcmp(log1, log) == 0 && strcmp(pass1, pass) != 0)
    {
        system("clear");
        printf("Login ou mot de passe incorrect, veuillez réessayer!\n");
        loginC();

    }
     
    }
   
    
    return 0;
}

void generatePresenceTable() {
     FILE *presenceFile = fopen("PresenceList.txt", "r");
    FILE *tableFile = fopen("PresenceTable.txt", "w");
    
    if (presenceFile == NULL || tableFile == NULL) {
        perror("Erreur lors de l'ouverture des fichiers");
        exit(EXIT_FAILURE);
    }

    fprintf(tableFile, "*********************************************************************\n");
    fprintf(tableFile, "*               TABLEAU DES PRÉSENCES DES ÉTUDIANTS                 *\n");
    fprintf(tableFile, "*********************************************************************\n");
    fprintf(tableFile, "| %-20s | %-20s | %-20s|\n", "        Nom", "        Code", "   Date et Heure");
    fprintf(tableFile, "*********************************************************************\n");

    char line[200];

    while (fgets(line, sizeof(line), presenceFile)) {
        char name[50], code[50];
        int day, month, year, hour, min, sec;
        sscanf(line, "L'etudiant %s ayant comme pass %s est présent le %d/%d/%d à %d:%d:%d\n", name, code, &day, &month, &year, &hour, &min, &sec);
        fprintf(tableFile, "| %-20s | %-20s | %02d/%02d/%d %02d:%02d:%02d |\n", name, code, day, month, year, hour, min, sec);
    }

    fprintf(tableFile, "*********************************************************************\n");

    fclose(presenceFile);
    fclose(tableFile);
}




    




 



