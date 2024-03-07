#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void functionAdminList(){
    FILE *Userlist = NULL; 
    Userlist = fopen("Userlist.txt","w");
    if(Userlist != NULL){
        //Admin
        fprintf(Userlist, "id : 00\t");
        fprintf(Userlist, "Droit: 1\t");
        fprintf(Userlist, "nom : Wane\t");
        fprintf(Userlist, "prenom : Birane\t");
        fprintf(Userlist, "username : Birane_01\t");
        fprintf(Userlist, "motDePasse : 1234\n");

        //Apprenants classe DEV_WEB

        fprintf(Userlist, "id : 01\t");
        fprintf(Userlist, "Droit: 2\t");
        fprintf(Userlist, "Classe: 1\t");
        fprintf(Userlist, "nom : Diedhiou\t");
        fprintf(Userlist, "prenom : Ousseynou\t");
        fprintf(Userlist, "username : Ousseynou_01\t");
        fprintf(Userlist, "motDePasse : 4321\n");

        fprintf(Userlist, "id : 02\t");
        fprintf(Userlist, "Droit: 2\t");
        fprintf(Userlist, "Classe: 1\t");
        fprintf(Userlist, "nom : Mbow\t");
        fprintf(Userlist, "prenom : Bamba\t");
        fprintf(Userlist, "username : Bamba_02\t");
        fprintf(Userlist, "motDePasse : 4322\n");

        fprintf(Userlist, "id : 03\t");
        fprintf(Userlist, "Droit: 2\t");
        fprintf(Userlist, "Classe: 1\t");
        fprintf(Userlist, "nom : Diallo\t");
        fprintf(Userlist, "prenom : Ibrahim\t");
        fprintf(Userlist, "username : Ibrahim_03\t");
        fprintf(Userlist, "motDePasse : 4323\n");

        fprintf(Userlist, "id : 04\t");
        fprintf(Userlist, "Droit: 2\t");
        fprintf(Userlist, "Classe: 1\t");
        fprintf(Userlist, "nom : Dione\t");
        fprintf(Userlist, "prenom : Awa\t");
        fprintf(Userlist, "username : Awa_04\t");
        fprintf(Userlist, "motDePasse : 4324\n");

        fprintf(Userlist, "id : 05\t");
        fprintf(Userlist, "Droit: 2\t");
        fprintf(Userlist, "Classe: 1\t");
        fprintf(Userlist, "nom : Mbow\t");
        fprintf(Userlist, "prenom : Saer\t");
        fprintf(Userlist, "username : Saer_05\t");
        fprintf(Userlist, "motDePasse : 4325\n");

        //Apprenants classe DEV_DATA

        fprintf(Userlist, "id : 06\t");
        fprintf(Userlist, "Droit: 2\t");
        fprintf(Userlist, "Classe: 2\t");
        fprintf(Userlist, "nom : Diop\t");
        fprintf(Userlist, "prenom : Moustapha\t");
        fprintf(Userlist, "username : Moustapha_06\t");
        fprintf(Userlist, "motDePasse : 4326\n");

        fprintf(Userlist, "id : 07\t");
        fprintf(Userlist, "Droit: 2\t");
        fprintf(Userlist, "Classe: 2\t");
        fprintf(Userlist, "nom : Mbacké\t");
        fprintf(Userlist, "prenom : Cheikh\t");
        fprintf(Userlist, "username : Cheikh_07\t");
        fprintf(Userlist, "motDePasse : 4327\n");

        fprintf(Userlist, "id : 08\t");
        fprintf(Userlist, "Droit: 2\t");
        fprintf(Userlist, "Classe: 2\t");
        fprintf(Userlist, "nom : Soumaré\t");
        fprintf(Userlist, "prenom : Wahab\t");
        fprintf(Userlist, "username : Wahab_08\t");
        fprintf(Userlist, "motDePasse : 4328\n");

        fprintf(Userlist, "id : 09\t");
        fprintf(Userlist, "Droit: 2\t");
        fprintf(Userlist, "Classe: 2\t");
        fprintf(Userlist, "nom : Faye\t");
        fprintf(Userlist, "prenom : Abdoulaye\t");
        fprintf(Userlist, "username : Abdoulaye_09\t");
        fprintf(Userlist, "motDePasse : 4329\n");

        fprintf(Userlist, "id : 10\t");
        fprintf(Userlist, "Droit: 2\t");
        fprintf(Userlist, "Classe: 2\t");
        fprintf(Userlist, "nom : Kouyaté\t");
        fprintf(Userlist, "prenom : Makan\t");
        fprintf(Userlist, "username : Makan_10\t");
        fprintf(Userlist, "motDePasse : 4330\n");

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

void afficherMenu(){
    int profile = 1;
    if(profile == 1){
        menuAdmin();
        menuApprenant();
    }else{
        menuApprenant();
    }
}
int loginC(){
    char log[50],pass[50], log1[50], pass1[50];
    int type, type1;
    FILE *login = NULL; 
    char fullog[50];
    login = fopen("Userlist.txt","r");
    printf("Saisissez le login\n");
    scanf("%s", log1);
    printf("Saisissez le mot de passe\n");
    scanf("%s", pass1);
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