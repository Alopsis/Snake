#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>
#include <time.h>
#include "main.h"
#include "mlv.h"
#include "divers.h"
#include "update.h"
#include "suivant.h"
#include "types.h"



/******************************/
/* Commentaire Doxygen Global */
/******************************/
/**
*\file main.c
*\brief Ce module contient le make qui va mettre en relation toutes les fonctions cree dans les modules tiers afin de faire correctement marche notre Snake 
*\author Sinclair.M 
*\author Alban.C
*\version 1.9
*\date 20 decembre 2022
*/


int main (){
  int snake[100]; /* Tableau contenant la carte du snake*/
  int snake_point[100]; /* Tableau contenant les corps du snake */
  char deplacement ; /* Gestion des deplacements  */
  int est_pomme = 1; /* Gestion du mangage de pomme */
  int snake_pomme; /* Gestion si une pomme est sur le terrain */
  int score = 0; 
  int frame; /* Permet la verification du frame rate */
  char nom[20]; /* Nom du joueur */
  int sauvegarde; /* Renseigne sur la sauvegarde que le joueur choisi */
  int scoretmp=-5; /* Utilise uniquement si le joueur fait une sauvegarde */
  int scoreobt=0; /* vrai score */
  int z = 0; /* Variable d'utilisation pour savoir si on est au premier deplacement ou  on */
  time_t start ; /* variable de temps qui permet de faire le chrono */
  int mlv = 0; /* Choix du mode de jeu */
  int perdu = 0; /* Permet de savoir si on a perdu */
  int sauvegardee = 1;

  MLV_Music* music; /* Init de la musique */
  
  mlv_creation_fenetre(); 
  while(1){
    MLV_change_window_size(600,600); /* Retour a la taille de base  */

    /***************************************************************************/
    /*Reinitialisation des variables necessaires au bon fonctionnement du snake*/ 
    /***************************************************************************/

    mlv=0;
    scoreobt=0;
    scoretmp=-5;
    z = 0;
    perdu = 0;
    est_pomme = 1;
    score = 0;
    MLV_init_audio( );
    music = MLV_load_music( "./musica/musique1.mp3" ); /* Musique pour une ambience pepere */
    MLV_play_music( music, 1.0, -1 );

    /****************************/
    /*Fin de la reinitialisation*/
    /****************************/

    /*********************************************************/
    /*Menu MLV on sort uniquement si il y a quitter ou jouer !*/
    /**********************************************************/

    while ( 1 ) {
      if ( mlv > 9 ){
        break;
      }
      if ( mlv == 0 ){
        mlv_affichage_menu(); /* Actualise window */
        mlv = mlv_clic_menu();
      }
      if ( mlv ==  1){
        mlv_affichage_jouer(); /* Actualise window */
        mlv = mlv_clic_jouer();
      }
      if ( mlv == 2 ){
        mlv_affichage_options(); /* Actualise window */
        mlv = mlv_clic_options();
      } 
      if  (mlv == 4){
        mlv_affiche_score(); /* Actualise window */
        mlv = mlv_clic_score(); 
      }
    }

    /*****************/
    /*Fin du menu MLV*/ 
    /*****************/

    /*******************************************/
    /*Si on joue a l'original on demande le nom*/
    /*******************************************/
    if ( mlv == 10 ){
      strcpy(nom,mlv_demande_nom(nom)); /* Actualise window */
    }

    /**************************************************************/
    /*Initialisation du snake vide avec la tete du snake au centre*/
    /**************************************************************/
    if ( mlv == 21 ) {
      mlv_mode_creatif();
    }
    snake_remplir_zero(snake,mlv-10);
    snake_estpoint_init_premier(snake_point);
    snake_point[0] = 55;
    /**********************************/
    /*Fin de l'initialisation du snake*/
    /**********************************/

    /******************************************************************/
    /*Si on veut jouer avec sauvegarde alors on l'affiche ici le choix*/
    /******************************************************************/
  	MLV_clear_window(MLV_COLOR_BLACK);
    if(mlv == 10){
      sauvegardee = 1;
    }else 
    {
      sauvegardee = 0;
    }
    if ( mlv == 20){
      sauvegarde = mlv_menu_sauvegarde(); /* on recupere le numero de la sauvegarde voulu */
      scoretmp = snake_charger_partie(snake_point,snake,sauvegarde); /* charge la partie */
      score = scoretmp+1 ;      /*************************************************/
      mlv=10;                   /* <-- On initialise les parametres du snake save*/
      est_pomme = 1;            /*************************************************/
      MLV_clear_window(MLV_COLOR_BLACK);

    }

    

    /**********************/
    /*Print du snake a t=0*/
    /**********************/
    mlv_print_snake(snake_point,snake,'z');
    mlv_print_quadrillage();   
    MLV_change_window_size(600,800);
    MLV_draw_filled_rectangle(0,600,600,200,MLV_COLOR_WHITE);
    /**************/
    /*Fin du print*/
    /**************/




    /**************************************************/
    /* On rentre dans la boucle infinie pour le snake */
    /**************************************************/
    while (1){




      /***************************/
      /*Gestion des deplacements */
      /***************************/
      if ( z != 0 ){
        deplacement = mlv_demande_deplacement(deplacement);
        
      }
      else {
        start = time(NULL);
        mlv_print_quadrillage();
        mlv_print_snake(snake_point,snake,'z');
        snake_print_bas(score+1,start);     
        MLV_actualise_window();                                                    
        deplacement = mlv_demande_deplacement_first();
        if (scoretmp != -5){
          z++;
          
        }        
      }
      /*************************************/
      /*Fin de la gestion des deplacements */
      /*************************************/


      /************************************/
      /* Gestion si l'on veut sauvegarder */
      /************************************/
      if (deplacement == 'a'){ /* a est le caractere de sauvegarde */
          sauvegarde = mlv_affichage_save(); /* Actualise window */
          put_sauvegarde_fichier(sauvegarde ,snake_point,snake);
          break;
        }
      /************************************/
      /* Fin de la gestion si on veut save*/
      /************************************/


      /***********************************************/
      /* On regarde si on a perdu avec le deplacement*/
      /***********************************************/
      perdu = mlv_snake_lose(snake_point[0],deplacement,snake); /* Actualise window */
      if ( perdu == 1 ){
        break;
      }
      /****************************/
      /* Fin du cas si on a perdu */
      /****************************/


      /****************************************************/
      /* On regarde si dans notre decors il y a une pomme */
      /* * * * * * * * * * * * * * * * * * * * * * * * * **/
      est_pomme = snake_ya_pomme(snake);
      if(est_pomme == 1){
        snake_prochain_deplacement_une_tete(snake,deplacement,snake_point,score);
      }
      /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * **/
      /* Si on a pas de pomme on assiste au prochain deplacement  */
      /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * **/
      if (est_pomme == 0){
        if(z != 0){
	        snake_agrandir_queue(snake_point,deplacement);
        }
        scoreobt++;
	      snake_pomme = snake_spawn_pomme(snake);
        score++;
        z++;
      }
      /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
      /* Si il n'y a pas de pomme alors on va agrandir le snake et augmenter le score*/
      /*******************************************************************************/

      MLV_flush_event_queue();


    /*****************************/
    /* gestion d'un cas d'erreur */
    /*****************************/
      if(snake_point[0] >= 100 || snake_point[0] < 0){
        break; /* Vous avez perdu mais ce case d'erreur ne devrait pas apparaitre */
      }
      if(mlv == 22){
        frame = MLV_get_frame_rate();
        if( frame == 2 ){
           if((time (NULL) - start) > score * 12 + 5){
          break;
        }
        }
        if ( frame == 4 ){
           if((time (NULL) - start) > score * 7 + 5){
          break;
        }
        }
        if ( frame == 10 ){
           if((time (NULL) - start) > score * 3 + 5){
          break;
        }
        }
       
      }
    /************************************/
    /* Fin de la gestion du cas d'erreur*/
    /*************************************/


    
      /****************************************************************************/
      /* Bloc permettant de remettre les parametres a 0 avant d'afficher le snake */
      /****************************************************************************/
      snake_remplir_zero(snake,mlv-10);
      snake_remplir(snake,snake_point,snake_pomme,score,mlv-10);
	    MLV_clear_window(MLV_COLOR_BLACK);
      /************************/
      /* Fin de la remise a 0 */
      /************************/

      /********************************/
      /* Print du snake en version MLV*/
      /********************************/
      snake_print_bas(score,start);
      mlv_print_quadrillage();
      mlv_print_snake(snake_point,snake,deplacement);
      snake_mange_pomme(snake,deplacement,snake_point[0]); 

      /*********************************************/
      /* affichage si mode survie du temps restant */
      /*********************************************/
      if(mlv == 22){
        frame = MLV_get_frame_rate();
        if( frame == 2 ){
          MLV_draw_text(50,650,"Il vous reste %d seconds",MLV_COLOR_RED,(score * 12+5)-(time(NULL)-start) );
        }
        if ( frame == 4 ){
          MLV_draw_text(50,650,"Il vous reste %d seconds",MLV_COLOR_RED,(score * 7+5)-(time(NULL)-start) );
        }
        if ( frame == 10 ){
          MLV_draw_text(50,650,"Il vous reste %d seconds",MLV_COLOR_RED,(score * 3+5)-(time(NULL)-start) );
        }
       
      }
      MLV_actualise_window();
      /**********************************************/
      /* Fin de l'affichage du snake en version MLV */
      /**********************************************/
    }

    /*****************************************************************************************/
    /* Si on a fait une partie classique on regarde le score si on rentre dans le classement */
    /*****************************************************************************************/
    if( sauvegardee == 1 ){
      update_classement(score-1,nom); 
    }
    /*********************************/
    /* Fin de l'update du classement */
    /*********************************/
  }
}