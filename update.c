
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "update.h"


/******************************/
/* Commentaire Doxygen Global */
/******************************/
/**
*\file update.c
*\brief Ce module contient les differentes fonctions permettant le bon fonctionnement du snake
*\author Sinclair.M 
*\author Alban.C
*\version 1.2
*\date 20 decembre 2022
*/



/***********************/
/* Commentaire Doxygen */
/***********************/
/**
*\fn void snake_remplir_zero(int snake[100],int niveau)
*\brief Fonction permettant de recuperer le caractere de deplacement du joueur. La fonction est bloquante tant que le deplacement est incorect 
*\param snake[100] int sert a etre rempli par le niveau souhaite
*\param niveau int permet de savoir quel niveau on doit remplir 
*\return void 
*/

void snake_remplir_zero(int snake[100],int niveau){
  int i;
  FILE *level;
  if (niveau == 0 || niveau == 12) {
    for(i=0;i<100;i++){
      snake[i] = 0;
    } 
  }
else if ( niveau == 1){
    if ((level  = fopen("niveaux/niveau1.txt","r"))!= NULL){
      for (i=0;i<101;i=i+10){
	
	  fscanf(level,"%d %d %d %d %d %d %d %d %d %d",&snake[i+0],&snake[i+1],&snake[i+2],&snake[i+3],&snake[i+4],&snake[i+5],&snake[i+6],&snake[i+7],&snake[i+8],&snake[i+9]);
      }
    }
  }
  else if ( niveau == 2){
    if ((level  = fopen("niveaux/niveau2.txt","r"))!= NULL){
      for (i=0;i<101;i=i+10){
	
	  fscanf(level,"%d %d %d %d %d %d %d %d %d %d",&snake[i+0],&snake[i+1],&snake[i+2],&snake[i+3],&snake[i+4],&snake[i+5],&snake[i+6],&snake[i+7],&snake[i+8],&snake[i+9]);
      }
    }
  }
  else if ( niveau == 3){
    if ((level  = fopen("niveaux/niveau3.txt","r"))!= NULL){
      for (i=0;i<101;i=i+10){
	
	  fscanf(level,"%d %d %d %d %d %d %d %d %d %d",&snake[i+0],&snake[i+1],&snake[i+2],&snake[i+3],&snake[i+4],&snake[i+5],&snake[i+6],&snake[i+7],&snake[i+8],&snake[i+9]);
      }
    }
  }
  else if ( niveau == 4){
    if ((level  = fopen("niveaux/niveau4.txt","r"))!= NULL){
      for (i=0;i<101;i=i+10){
	
	  fscanf(level,"%d %d %d %d %d %d %d %d %d %d",&snake[i+0],&snake[i+1],&snake[i+2],&snake[i+3],&snake[i+4],&snake[i+5],&snake[i+6],&snake[i+7],&snake[i+8],&snake[i+9]);
      }
    }
  }
  else if ( niveau == 5){
    if ((level  = fopen("niveaux/niveau5.txt","r"))!= NULL){
      for (i=0;i<101;i=i+10){
	
	  fscanf(level,"%d %d %d %d %d %d %d %d %d %d",&snake[i+0],&snake[i+1],&snake[i+2],&snake[i+3],&snake[i+4],&snake[i+5],&snake[i+6],&snake[i+7],&snake[i+8],&snake[i+9]);
      }
    }
  }
  else if ( niveau == 6){
    if ((level  = fopen("niveaux/niveau6.txt","r"))!= NULL){
      for (i=0;i<101;i=i+10){
	
	  fscanf(level,"%d %d %d %d %d %d %d %d %d %d",&snake[i+0],&snake[i+1],&snake[i+2],&snake[i+3],&snake[i+4],&snake[i+5],&snake[i+6],&snake[i+7],&snake[i+8],&snake[i+9]);
      }
    }
  }
  else if ( niveau == 7){
    if ((level  = fopen("niveaux/niveau7.txt","r"))!= NULL){
      for (i=0;i<101;i=i+10){
	
	  fscanf(level,"%d %d %d %d %d %d %d %d %d %d",&snake[i+0],&snake[i+1],&snake[i+2],&snake[i+3],&snake[i+4],&snake[i+5],&snake[i+6],&snake[i+7],&snake[i+8],&snake[i+9]);
      }
    }
  }
  else if ( niveau == 8){
    if ((level  = fopen("niveaux/niveau8.txt","r"))!= NULL){
      for (i=0;i<101;i=i+10){
	
	  fscanf(level,"%d %d %d %d %d %d %d %d %d %d",&snake[i+0],&snake[i+1],&snake[i+2],&snake[i+3],&snake[i+4],&snake[i+5],&snake[i+6],&snake[i+7],&snake[i+8],&snake[i+9]);
      }
    }
  }
  else if ( niveau == 9){
    if ((level  = fopen("niveaux/niveau9.txt","r"))!= NULL){
      for (i=0;i<101;i=i+10){
	
	  fscanf(level,"%d %d %d %d %d %d %d %d %d %d",&snake[i+0],&snake[i+1],&snake[i+2],&snake[i+3],&snake[i+4],&snake[i+5],&snake[i+6],&snake[i+7],&snake[i+8],&snake[i+9]);
      }
    }
  }
   else if ( niveau == 11){
    if ((level  = fopen("niveaux/niveaucreatif.txt","r"))!= NULL){
      for (i=0;i<101;i=i+10){
	
	  fscanf(level,"%d %d %d %d %d %d %d %d %d %d",&snake[i+0],&snake[i+1],&snake[i+2],&snake[i+3],&snake[i+4],&snake[i+5],&snake[i+6],&snake[i+7],&snake[i+8],&snake[i+9]);
      }
    }
  }
  

}



/***********************/
/* Commentaire Doxygen */
/***********************/
/**
*\fn void snake_estpoint_init_premier(int snake_point[100])
*\brief Fonction 
*\param snake_point[100] int permet d'avoir les points du snake ( le corps ) 
*\return void 
*/

void snake_estpoint_init_premier(int snake_point[100]){
  int i;
  for(i=0;i<100;i++){
    snake_point[i] = -1;


   
  }
}



/***********************/
/* Commentaire Doxygen */
/***********************/
/**
*\fn void snake_place_point(int point,int snake[100])
*\brief Fonction permettant de recuperer le caractere de deplacement du joueur. La fonction est bloquante tant que le deplacement est incorect 
*\param point int permet de rajouter un point 
*\param snake[100] int initialise les points du decors a 1 
*\return void 
**/

void snake_place_point(int point,int snake[100]){
  int i;
  for(i=0;i<100;i++){
    if (i==point){
      snake[i] = 1;
    }
  }
}



/***********************/
/* Commentaire Doxygen */
/***********************/
/**
*\fn void snake_mange_pomme(int snake[100],char deplacement, int tete)
*\brief Fonction permettant de savoir si on mange la pomme 
*\param snake[100] int decors du snake 
*\param deplacement char permet de connaitre le deplacement 
*\param tete int tete du serpent servant a voir si le prochain deplacement de la tete correspond a une tete 
*\return void 
*/

void snake_mange_pomme(int snake[100],char deplacement ,int tete){
  int i;
  int tmp;
  for(i=0;i<100;i++){
    
    if ( deplacement == 'z'){
      tmp = tete - 10;
      if (snake[i] == 2 && snake[i] == tmp){
      }
    }
    if ( deplacement == 'q'){
      tmp = tete-1;
        if (snake[i] == 2 && snake[i] == tmp){
      }
    }
    if ( deplacement == 's'){
      tmp = tete +10;
        if (snake[i] == 2 && snake[i] == tmp){
      }
    }
    if ( deplacement == 'd'){
      tmp = tete +1;
        if (snake[i] == 2 && snake[i] == tmp){

	}
    }
  }
}


/***********************/
/* Commentaire Doxygen */
/***********************/
/**
*\fn void snake_remplir(int snake[100],int snake_point[100],int snake_pomme,int score,int niveaue)
*\brief Fonction permettant d'initialiser le snake d'apres une sauvegarde avec le decors les points et la pomme 
*\param snake[100] int Va etre rempli suivant le niveau 
*\param snake_point[100] int va contenir les points du snake des niveaux d'avant 
*\param snake_pomme int va savoir si il y a une pomme ou non 
*\param score int va contenir le score afin de refaire le snake 
*\param niveau int sert a savoir dans quel niveau on est 
*\return void 
*/

void snake_remplir(int snake[100] ,int snake_point[100] , int snake_pomme,int score,int niveau){
  int i=0;
  int tmp;
  FILE*level;
  if (niveau == 0) {
    for (i=0;i<100;i++){
      snake[i] = 0;
    }
  }
  else if(niveau == 1){ 
    if ((level  = fopen("niveaux/niveau1.txt","r"))!= NULL){
      for (i=0;i<101;i=i+10){
	fscanf(level,"%d %d %d %d %d %d %d %d %d %d",&snake[i+0],&snake[i+1],&snake[i+2],&snake[i+3],&snake[i+4],&snake[i+5],&snake[i+6],&snake[i+7],&snake[i+8],&snake[i+9]);
      }
    }
  }
  else if(niveau == 2){ 
    if ((level  = fopen("niveaux/niveau2.txt","r"))!= NULL){
      for (i=0;i<101;i=i+10){
	fscanf(level,"%d %d %d %d %d %d %d %d %d %d",&snake[i+0],&snake[i+1],&snake[i+2],&snake[i+3],&snake[i+4],&snake[i+5],&snake[i+6],&snake[i+7],&snake[i+8],&snake[i+9]);
      }
    }
  }
  else if(niveau == 3){ 
    if ((level  = fopen("niveaux/niveau3.txt","r"))!= NULL){
      for (i=0;i<101;i=i+10){
	fscanf(level,"%d %d %d %d %d %d %d %d %d %d",&snake[i+0],&snake[i+1],&snake[i+2],&snake[i+3],&snake[i+4],&snake[i+5],&snake[i+6],&snake[i+7],&snake[i+8],&snake[i+9]);
      }
    }
  }
  else if(niveau == 4){ 
    if ((level  = fopen("niveaux/niveau4.txt","r"))!= NULL){
      for (i=0;i<101;i=i+10){
	fscanf(level,"%d %d %d %d %d %d %d %d %d %d",&snake[i+0],&snake[i+1],&snake[i+2],&snake[i+3],&snake[i+4],&snake[i+5],&snake[i+6],&snake[i+7],&snake[i+8],&snake[i+9]);
      }
    }
  }
  else if(niveau == 5){ 
    if ((level  = fopen("niveaux/niveau5.txt","r"))!= NULL){
      for (i=0;i<101;i=i+10){
	fscanf(level,"%d %d %d %d %d %d %d %d %d %d",&snake[i+0],&snake[i+1],&snake[i+2],&snake[i+3],&snake[i+4],&snake[i+5],&snake[i+6],&snake[i+7],&snake[i+8],&snake[i+9]);
      }
    }
  }
  else if(niveau == 6){ 
    if ((level  = fopen("niveaux/niveau6.txt","r"))!= NULL){
      for (i=0;i<101;i=i+10){
	fscanf(level,"%d %d %d %d %d %d %d %d %d %d",&snake[i+0],&snake[i+1],&snake[i+2],&snake[i+3],&snake[i+4],&snake[i+5],&snake[i+6],&snake[i+7],&snake[i+8],&snake[i+9]);
      }
    }
  }
  else if(niveau == 7){ 
    if ((level  = fopen("niveaux/niveau7.txt","r"))!= NULL){
      for (i=0;i<101;i=i+10){
	fscanf(level,"%d %d %d %d %d %d %d %d %d %d",&snake[i+0],&snake[i+1],&snake[i+2],&snake[i+3],&snake[i+4],&snake[i+5],&snake[i+6],&snake[i+7],&snake[i+8],&snake[i+9]);
      }
    }
  }
  else if(niveau == 8){ 
    if ((level  = fopen("niveaux/niveau8.txt","r"))!= NULL){
      for (i=0;i<101;i=i+10){
	fscanf(level,"%d %d %d %d %d %d %d %d %d %d",&snake[i+0],&snake[i+1],&snake[i+2],&snake[i+3],&snake[i+4],&snake[i+5],&snake[i+6],&snake[i+7],&snake[i+8],&snake[i+9]);
      }
    }
  }
  else if(niveau == 9){ 
    if ((level  = fopen("niveaux/niveau9.txt","r"))!= NULL){
      for (i=0;i<101;i=i+10){
	fscanf(level,"%d %d %d %d %d %d %d %d %d %d",&snake[i+0],&snake[i+1],&snake[i+2],&snake[i+3],&snake[i+4],&snake[i+5],&snake[i+6],&snake[i+7],&snake[i+8],&snake[i+9]);
      }
    }
  }
  for (i=0;i<100;i++){
    if ( snake_pomme == i){
      snake[i] = 2;
    }
  
  }
  i=0;
  while ( snake_point[i] != -1){
    tmp = snake_point[i];
    snake[tmp] = 1;
    i++;
  }
  
}



/***********************/
/* Commentaire Doxygen */
/***********************/
/**
*\fn int snake_ya_pomme(int snake[100])
*\brief Fonction retournant le savoir si il y a une pomme ou non dans le decors 
*\param snake[100] int sert a etre rempli par le niveau souhaite 
*\return int 
**/

int snake_ya_pomme(int snake[100]){
  int i;
  for(i=0;i<100;i++){
    if (snake[i] == 2 ){
      return 1;
    }
  }
  return 0;
}


/***********************/
/* Commentaire Doxygen */
/***********************/
/**
*\fn void snake_spawn_pomme(int snake[100])
*\brief Fonction permettant de faire spawn une pomme et renvoie l'indice de la pomme 
*\param snake[100] int contient le decors 
*\return int 
*/

int  snake_spawn_pomme(int snake[100]){
  int i;
  int casevide = 0;
  int random;
  for (i=0;i<100;i++){
    if (snake[i] ==0 ){
      casevide ++;
    }
  }
  while(snake[random] != 0){
   random = rand()% (casevide+0);
   for (i=0;i<100;i++){
    if (snake[i] ==0 ){
      casevide ++;
    }
  }
  }
  for (i=0;i<100;i++){
    if(random == i){
      snake[i] = 2;
      break;
    }
    
  }
  return  random;
} 

  


/***********************/
/* Commentaire Doxygen */
/***********************/
/**
*\fn int snake_charger_partie(int snake_point[100],int snake[100],int sauvegarde)
*\brief Fonction permettant      printf("LA VALEUR EST %d\n",xx);
 de recuperer le caractere de deplacement du joueur. La fonction est bloquante tant que le deplacement est incorect 
*\param snake_point[100] int Permet de connaitre les corps du snake 
*\param snake[100]  int contient le decors 
*\param sauvegarde int charge la partie suivant la sauvegarde choisie 
*\return int 
*/

int snake_charger_partie(int snake_point[100],int snake[100],int sauvegarde ){
  int i;
  int tmp=1;
    FILE* fichier;
    if ( sauvegarde == 1){
    fichier = fopen("sauvegarde/save1.txt","r");
    }
      if ( sauvegarde == 2){
    fichier = fopen("sauvegarde/save2.txt","r");
    }
      if ( sauvegarde == 3){
    fichier = fopen("sauvegarde/save3.txt","r");
    }
      if ( sauvegarde == 4){
    fichier = fopen("sauvegarde/save4.txt","r");
    }
      if ( sauvegarde == 5){
    fichier = fopen("sauvegarde/save5.txt","r");
    }
    for (i=0;i<10;i++){
      
      if (fscanf(fichier,"%d %d %d %d %d %d %d %d %d %d",&snake[i*10],&snake[i*10+1],&snake[i*10 +2],&snake[i*10 +3],&snake[i*10 +4],&snake[i*10 +5],&snake[i*10 +6],&snake[i*10 +7],&snake[i*10 +8],&snake[i*10+9])!= 10){
        fprintf(stderr,"Erreur lors du chargement du plateau de jeu pour la sauvegarde %d",sauvegarde);
      }
    }
  
    for (i=0;i<100;i++){
      if ((snake[i] != 0) && (snake[i] !=3)) {
        if (snake[i] == 4){
          snake_point[0] = i;
          
          snake[i] = 0;
        }
        else if (snake[i] >3){

          snake_point[snake[i]-4]=i;
          /*snake_point[snake[i]-4] = i;*/
          snake[i] = 0;
          tmp++;
          
        }
       
      }
      if ( snake[i] == 3){
        snake[i] = 0;

      }
    }

    /* Ici y'a un 98 qui pop mais faut voir d'ou ! */


  return tmp;

  
} 