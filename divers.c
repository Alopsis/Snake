#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "divers.h"
#include "types.h"


/* ancienne fonction permettant de faire un getchar sans avoir a press ENTER 
#include <termios.h>
#include <unistd.h>


int getch(void){
  struct termios oldattr, newattr;
  int ch;
  tcgetattr( STDIN_FILENO, &oldattr );
  newattr = oldattr;
  newattr.c_lflag &= ~( ICANON | ECHO );
  tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
  ch = getchar();
  tcsetattr( STDIN_FILENO, TCSANOW, &oldattr ) ;
  return ch;
}
*/

/******************************/
/* Commentaire Doxygen Global */
/******************************/
/**
*\file divers.c
*\brief Ce module contient les differentes fonctions concernant les sauvegardes 
*\author Sinclair.M 
*\author Alban.C
*\version 1.0
*\date 20 decembre 2022
*/


/***********************/
/* commentaire Doxygen */
/***********************/
/**
*\fn void update_classement(int scorej,char joueur[20])
*\brief Fonction permettant de recuperer les meilleurs scores dans le fichier "scorebet.txt" et si besoin il insere le score recu en parametre dans le fichier au bon endroit ( il trie et update le classement )
*\param scorej int 
*\param joueur[20] char 
*\return void 
*/



void update_classement(int scorej,char joueur[20]){
  
  
  
    FILE *fich = fopen("meilleurscore.txt", "r");
   char joueurattente[20];
   char joueurattentee[20];
   int scoreattente;
   int scoreattentee;
    int i = 0;
    int j=0;
    int z=0;
    char nomtmp[25] ;
    classement score[10];
    char a;

a=strlen(joueur);
 for(i=0;i<a;i++){
        if(joueur[i]!=' ')
        {
           nomtmp[j++] = joueur[i];
        }
 
    }
    strcpy(joueur,nomtmp);

    if (fich == NULL)
    {
      fprintf(stderr,"Votre fichier de classement n'a pas pu s'ouvrir malheuresement... \n");
      return;
    }
 
      for(i=0;i<10;i++){

      if(fscanf(fich,"%d %d %s\n",  &score[i].score, &score[i].place,score[i].nom)!=3){
          fprintf(stderr,"Votre fichier de classement est corrompu car certains champs sont incertain ... \n");
          return;
      }
  }
      
  
  
for(i=0;i<10;i++){
  if (z==1){
     strcpy(joueurattentee,score[i].nom);
    scoreattentee=score[i].score;
    strcpy(score[i].nom,joueurattente);
    score[i].score = scoreattente;
    strcpy(joueurattente,joueurattentee);
    scoreattente = scoreattentee;
  }else 
  if(scorej>score[i].score){
    strcpy(joueurattente,score[i].nom);
    scoreattente=score[i].score;
    strcpy(score[i].nom,joueur); 
    score[i].score=scorej;
    
    z=1;
  }
}



fclose(fich);

    FILE *fic = fopen("meilleurscore.txt","w");
    if ( fic == NULL ){
      fprintf(stderr,"Votre fichier meilleurscore est corrompue \n");
    }

for (i=0;i<10;i++){
  if(strlen(score[i].nom)== 0){
        fprintf(fic,"%d %d NoName\n",score[i].score,score[i].place);
  }
  else {
    fprintf(fic,"%d %d %s\n",score[i].score,score[i].place,score[i].nom);
  }

}


fclose(fic);
    
}

/***********************/
/* Commentaire Doxygen */
/***********************/
/**
*\fn void put_sauvegarde_fichier (int sauvegarde,it snake_point[100],int snake[100])
*\brief Fonction permettant de mettre son stade du snake dans un fichier de sauvegarde afin de le garder pour les parties suivantes
*\param sauvegarde int  
*\param joueur[20] char 
*\return void 
*/
void put_sauvegarde_fichier(int sauvegarde ,int snake_point[100],int snake[100]){
  int i;
  int acc=5;
  FILE * fichier;
  int save[100];
  if (sauvegarde == 1){
     fichier= fopen("sauvegarde/save1.txt","w");
     if(fichier == NULL){
      fprintf(stderr,"Le fichier 1 a été mal ouvert... \n");
     }
     else {
     }
  }
  if (sauvegarde == 2){
     fichier= fopen("sauvegarde/save2.txt","w");
      if(fichier == NULL){
      fprintf(stderr,"Le fichier 2 a été mal ouvert... \n");
     }
     else {
     }
  }
  if (sauvegarde == 3){
     fichier= fopen("sauvegarde/save3.txt","w");
 if(fichier == NULL){
      fprintf(stderr,"Le fichier 3 a été mal ouvert... \n");
     }
     else {
     }
  }
  if (sauvegarde == 4){
     fichier= fopen("sauvegarde/save4.txt","w");
 if(fichier == NULL){
      fprintf(stderr,"Le fichier 4 a été mal ouvert... \n");
     }
     else {
     }  }
  if (sauvegarde == 5){
     fichier= fopen("sauvegarde/save5.txt","w");
 if(fichier == NULL){
      fprintf(stderr,"Le fichier 5 a été mal ouvert... \n");
     }
     else {
     }  }
  for(i=0;i<100;i++){
    save[i] = snake[i];
  }
  save[snake_point[0]] = 4;
  for(i=1;i<100;i++){
    if (snake_point[i] != -1){
      save[snake_point[i]] = acc;   
      acc ++;
    }
  }
  for(i=0;i<100;i++){
    fprintf(fichier,"%d ",save[i]);
    if ( (i+1)%10 == 0){
      fprintf(fichier,"\n");
    }
  }
  fclose(fichier);
}