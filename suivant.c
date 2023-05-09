#include <stdio.h>
#include <stdlib.h>
#include "suivant.h"


/******************************/
/* Commentaire Doxygen Global */
/******************************/
/**
*\file suivant.c
*\brief Ce module contient les differentes fonctions permettant d'agrandir le snake
*\author Sinclair.M 
*\author Alban.C
*\version 1.0
*\date 20 decembre 2022
*/


/***********************/
/* Commentaire Doxygen */
/***********************/
/**
*\fn void snake_agrandir_queue(int snake_point[100],char deplacement)
*\brief Fonction permettant de recuperer le caractere de deplacement du joueur. La fonction est bloquante tant que le deplacement est incorect 
*\param snake_point[100] int contient les points du snake 
*\param deplacement char permet de calculer l'endroit de la future tete 
*\return void 
*/

void  snake_agrandir_queue(int snake_point[100] ,char deplacement){
  int tmp;
  int i=1;
 
  
  tmp = snake_point[0];
  for(i=98;i>0;i--){
    snake_point[i] = snake_point[i-1];
  }
  if (deplacement == 'z'){
    snake_point[0] = tmp-10;
  }
  if (deplacement == 'q'){
    snake_point[0] = tmp-1;
  }
  if (deplacement == 's'){
    snake_point[0] = tmp+10;
  }
  if(deplacement == 'd'){
    snake_point[0] = tmp+1;
  }
 
}


/***********************/
/* Commentaire Doxygen */
/***********************/
/**
*\fn void snake_prochaine_deplacement_une_tete(int snake[100],char deplacement, int snake_point[100],int score)
*\brief Fonction updatant le snake avec une rotation chronique des points du corp et si le score augmente alors on augmente de 1 le corps ! 
*\param snake[100] int pas vraiment utile 
*\param deplacement char permet de calculer le prochain emplacement de la tete 
*\param snake_point[100] int permet de faire la rotation chronique du snake ( contient les pts du snake )
*\param score int permet de savoir jusqu'a quand 
*\return void 
*/
void  snake_prochain_deplacement_une_tete(int snake[100] , char deplacement , int snake_point[100],int score){
  int i;
  int tmp;
  tmp = snake_point[0];
  for(i=score-1;i>=0;i--){
    snake_point[i] = snake_point[i-1];
  }
  if ( deplacement == 'z'){
    snake_point[0] = tmp - 10;
  }
  if ( deplacement == 'q'){
    snake_point[0] = tmp-1;
   
  }
  if ( deplacement == 's'){
    snake_point[0] = tmp +10;
  }
  if ( deplacement == 'd'){
    snake_point[0] = tmp +1;
  
  }
  
}

