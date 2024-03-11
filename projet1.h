#ifndef PROJET1_H
#define PROJET1_H

#include <time.h>

typedef struct{
    int j;
    int m;
    int a;
}Date;

typedef struct{
    int id;
    char nom[20];
    
}Classe;

typedef struct{
    int id;
    time_t date_presence;
}Presence;

typedef struct{
    int id;
    char code[10];
    char usernamed[50];
    char password[50];
    char nom[20];
    char prenom[50];
    Date date_naissance;
    enum etat{BLOQUER, ACTIF}etat;
    enum role{ADMIN=1, APPRENANT}role;
    enum classe{DEV_WEB=1, DEV_DATA, REF_DIG}classe;
    Presence presence;
}Utilisateur;


void functionAdminList();
int menuAdmin();
int menuApprenant();
int loginC();
char getch();
void marquePresenceAd();
void marquePresenceApr();
void generatePresenceTable();


#endif