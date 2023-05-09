#include <MLV/MLV_all.h>
#include <time.h>
#include "mlv.h"
#include "types.h"


/******************************/
/* Commentaire Doxygen Global */
/******************************/
/**
*\file mlv.c
*\brief Ce module contient les differentes fonctions d'affichage 
*\author Sinclair.M 
*\author Alban.C
*\version 1.2
*\date 20 decembre 2022
*/



/***********************/
/* Commentaire Doxygen */
/***********************/
/**
*\fn void mlv_creation_fenetre()
*\brief Fonction simple creant la fenetre et initialisant le frame rate a 4
*\return void 
*/


void mlv_creation_fenetre(){
  MLV_create_window("Snake | Projet L2 informatique","Snake",600,600);
  MLV_change_frame_rate(4);
}

/***********************/
/* Commentaire Doxygen */
/***********************/
/**
*\fn void mlv_affichage_menu()
*\brief Fonction affichant le menu ( UNIQUEMENT GRAPHIQUE ) et renvoyant sur mlv_clic_menu afin de faire le renvoie de la valeur du menu sur le main
*\return void 
*/
void mlv_affichage_menu(){
  /****************************/
  /* Simple affichage du menu */
  /****************************/
  MLV_Font * police1 = MLV_load_font("./Polices/Police1.ttf",50);
    MLV_Font * police2 = MLV_load_font("./Polices/Police1.ttf",40);
    MLV_Font * police3 = MLV_load_font("./Polices/Police1.ttf",25);
    MLV_clear_window(MLV_COLOR_BLACK);
  MLV_draw_rectangle(220,130,150,150,MLV_COLOR_RED);  
  MLV_draw_adapted_text_box_with_font(245,50,"Snake",police1,1,MLV_COLOR_BLACK,MLV_COLOR_RED,MLV_COLOR_BLACK,MLV_TEXT_CENTER);
  
  MLV_draw_adapted_text_box_with_font(255,185,"Play",police1,1,MLV_COLOR_BLACK,MLV_COLOR_RED,MLV_COLOR_BLACK,MLV_TEXT_CENTER);
  MLV_draw_rectangle(120,340,150,150,MLV_COLOR_GREY);
  MLV_draw_adapted_text_box_with_font(130,390,"Options",police2,1,MLV_COLOR_BLACK,MLV_COLOR_GREY,MLV_COLOR_BLACK,MLV_TEXT_CENTER);
  MLV_draw_rectangle(320,340,150,150,MLV_COLOR_GREY);
  MLV_draw_adapted_text_box_with_font(345,390,"Quitter",police2,1,MLV_COLOR_BLACK,MLV_COLOR_GREY,MLV_COLOR_BLACK,MLV_TEXT_CENTER);
  MLV_draw_rectangle(100,520,400,50,MLV_COLOR_WHITE);
  MLV_draw_adapted_text_box_with_font(215,535,"Meilleurs scores",police3,1,MLV_COLOR_BLACK,MLV_COLOR_GREY,MLV_COLOR_BLACK,MLV_TEXT_CENTER);


  MLV_actualise_window();
}


/***********************/
/* Commentaire Doxygen */
/***********************/
/**
*\fn int mlv_clic_menu()
*\brief Fonction renvoyant le choix du menu( jouer opts quitter la fenetre ou meilleurs scores )
*\return int 
*/
int mlv_clic_menu(){
  int x;
  int y;
  /*******************/
  /* Gestion du clic */
  /*******************/
  while (1){
    MLV_wait_mouse(&x, &y);
    if (( x>220 && y> 130 )&& (x<370 && y<280)){
      return 1; /* -> jouer */
    }
    else if (( x> 120 && y> 340 ) && ( x< 270 && y<490)){
      return 2 ; /* -> Options */
    }
    else if ((x> 320 && y> 340 ) && ( x<470 && y < 490 )){
      MLV_free_window(); /* -> Quitter la fenetre */
      exit(0);
    }
    else if ((x>100  && y>520 ) && (x<500  && y<570 )){
      return 4; /* Meilleurs scores */
    }
  }
}


/***********************/
/* Commentaire Doxygen */
/***********************/
/**
*\fn void mlv_affichage_options()
*\brief Fonction graphique des options renvoyant sur les mlv_clic_options
*\return void 
*/
void mlv_affichage_options(){
  MLV_Font * police1 = MLV_load_font("./Polices/Police1.ttf",40);
  MLV_Font * police2= MLV_load_font("./Polices/Police2.ttf",20);
  int rate;
  rate = MLV_get_frame_rate();
  MLV_clear_window(MLV_COLOR_BLACK);
  MLV_draw_adapted_text_box_with_font(240,250,"Vitesse",police1,20,MLV_COLOR_BLUE,MLV_COLOR_BLUE,MLV_COLOR_BLACK,MLV_TEXT_CENTER);
  if(rate == 2){
  MLV_draw_adapted_text_box_with_font(140,350,"Lent",police2,20,MLV_COLOR_BLUE,MLV_COLOR_BLUE,MLV_COLOR_GREEN,MLV_TEXT_CENTER);
  }
  else {
    MLV_draw_adapted_text_box_with_font(140,350,"Lent",police2,20,MLV_COLOR_BLUE,MLV_COLOR_BLUE,MLV_COLOR_BLACK,MLV_TEXT_CENTER);

  }
  if(rate == 4){  
  MLV_draw_adapted_text_box_with_font(250,350,"Normal",police2,20,MLV_COLOR_BLUE,MLV_COLOR_BLUE,MLV_COLOR_GREEN,MLV_TEXT_CENTER);
  }
  else {
    MLV_draw_adapted_text_box_with_font(250,350,"Normal",police2,20,MLV_COLOR_BLUE,MLV_COLOR_BLUE,MLV_COLOR_BLACK,MLV_TEXT_CENTER);

  }
  if(rate == 10){
  MLV_draw_adapted_text_box_with_font(385,350,"Rapide",police2,20,MLV_COLOR_BLUE,MLV_COLOR_BLUE,MLV_COLOR_GREEN,MLV_TEXT_CENTER);
  } 
  else {
      MLV_draw_adapted_text_box_with_font(385,350,"Rapide",police2,20,MLV_COLOR_BLUE,MLV_COLOR_BLUE,MLV_COLOR_BLACK,MLV_TEXT_CENTER);

  }
  MLV_draw_adapted_text_box_with_font(450,500,"Regles",police2,20,MLV_COLOR_BLUE,MLV_COLOR_BLUE,MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box_with_font(20,20,"Retour",police2,20,MLV_COLOR_BLUE,MLV_COLOR_BLUE,MLV_COLOR_BLACK,MLV_TEXT_CENTER);

  MLV_actualise_window();
}

/***********************/ 
/* Commentaire Doxygen */
/***********************/
/**
*\fn int mlv_clic_options()
*\brief Fonction d'utilisation afin de renvoyer le choix de l'option 
*\return int 
*/
int mlv_clic_options(){
  int x;
  int y;
    MLV_Font * police1 = MLV_load_font("./Polices/Police1.ttf",20);

  while (1){
  MLV_wait_mouse(&x,&y);  

  if (( x>20 && y> 20 )&& (x<133 && y<83)){
      return 0; /* -> Retour*/
    }
    else if (( x> 140 && y> 353 ) && ( x< 227 && y<414)){
      /* -> Lent  */
      MLV_change_frame_rate(2);
      mlv_affichage_options();
    }
      else if (( x> 250 && y> 354 ) && ( x< 363 && y<416)){
       /* -> Normal */
       MLV_change_frame_rate(4);
       mlv_affichage_options();
    }
      else if (( x> 388 && y> 354 ) && ( x< 490 && y<414)){
       /* -> Rapide */
       MLV_change_frame_rate(10);
       mlv_affichage_options();
    }
      else if (( x> 451 && y> 502 ) && ( x< 559 && y<566)){
      MLV_clear_window(MLV_COLOR_BLACK);
    
        MLV_draw_adapted_text_box_with_font(30,100,"Le snake est un jeu de plateau \n qui permet de faire manger a un serpent des pommes afin de grandir \n le but est d'atteindre une taille maximal\n",police1,20,MLV_COLOR_BLUE,MLV_COLOR_BLUE,MLV_COLOR_GREEN,MLV_TEXT_CENTER);

      MLV_draw_text(10,10,"appuyer pour quitter",MLV_COLOR_RED);
      MLV_actualise_window();
      MLV_wait_mouse(&x,&y);
      mlv_affichage_options();


    }
  }
  return 0;
}


/***********************/
/* Commentaire Doxygen */
/***********************/
/**
*\fn void mlv_affichage_jouer()
*\brief Fonction graphique affichant les differents mode de jeu
*\return void 
*/
void mlv_affichage_jouer(){

  MLV_clear_window(MLV_COLOR_BLACK);
  MLV_Font * police1 = MLV_load_font("./Polices/Police1.ttf",40);
  MLV_Font * police2= MLV_load_font("./Polices/Police2.ttf",20);

  /************************************/
  /* Affichage des diffèrents niveaux */
  /************************************/
  MLV_draw_adapted_text_box_with_font(225,100,"L'original",police1,10,MLV_COLOR_RED,MLV_COLOR_RED,MLV_COLOR_BLACK,MLV_TEXT_CENTER);
  MLV_draw_adapted_text_box_with_font(100,300,"Niveau 1",police2,20,MLV_COLOR_BLUE,MLV_COLOR_BLUE,MLV_COLOR_BLACK,MLV_TEXT_CENTER);
  MLV_draw_adapted_text_box_with_font(250,300,"Niveau 2",police2,20,MLV_COLOR_BLUE,MLV_COLOR_BLUE,MLV_COLOR_BLACK,MLV_TEXT_CENTER);
  MLV_draw_adapted_text_box_with_font(400,300,"Niveau 3",police2,20,MLV_COLOR_BLUE,MLV_COLOR_BLUE,MLV_COLOR_BLACK,MLV_TEXT_CENTER);
  MLV_draw_adapted_text_box_with_font(100,400,"Niveau 4",police2,20,MLV_COLOR_BLUE,MLV_COLOR_BLUE,MLV_COLOR_BLACK,MLV_TEXT_CENTER);
  MLV_draw_adapted_text_box_with_font(250,400,"Niveau 5",police2,20,MLV_COLOR_BLUE,MLV_COLOR_BLUE,MLV_COLOR_BLACK,MLV_TEXT_CENTER);
  MLV_draw_adapted_text_box_with_font(400,400,"Niveau 6",police2,20,MLV_COLOR_BLUE,MLV_COLOR_BLUE,MLV_COLOR_BLACK,MLV_TEXT_CENTER);
  MLV_draw_adapted_text_box_with_font(100,500,"Niveau 7",police2,20,MLV_COLOR_BLUE,MLV_COLOR_BLUE,MLV_COLOR_BLACK,MLV_TEXT_CENTER);
  MLV_draw_adapted_text_box_with_font(250,500,"Niveau 8",police2,20,MLV_COLOR_BLUE,MLV_COLOR_BLUE,MLV_COLOR_BLACK,MLV_TEXT_CENTER);
  MLV_draw_adapted_text_box_with_font(400,500,"Niveau 9",police2,20,MLV_COLOR_BLUE,MLV_COLOR_BLUE,MLV_COLOR_BLACK,MLV_TEXT_CENTER);
  MLV_draw_adapted_text_box_with_font(225,200,"Sauvegarde",police2,20,MLV_COLOR_RED,MLV_COLOR_YELLOW,MLV_COLOR_BLACK,MLV_TEXT_CENTER);
  MLV_draw_adapted_text_box_with_font(405,200,"Creatif",police2,20,MLV_COLOR_RED,MLV_COLOR_YELLOW,MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    MLV_draw_adapted_text_box_with_font(105,200,"Survie",police2,20,MLV_COLOR_RED,MLV_COLOR_YELLOW,MLV_COLOR_BLACK,MLV_TEXT_CENTER);

    MLV_draw_adapted_text_box_with_font(20,20,"Retour",police2,20,MLV_COLOR_BLUE,MLV_COLOR_BLUE,MLV_COLOR_BLACK,MLV_TEXT_CENTER);
  MLV_actualise_window();
}


/***********************/
/* Commentaire Doxygen */
/***********************/
/**
*\fn int mlv_clic_jouer()
*\brief Fonction d'utilisation du menu jouer renvoyant l'option choisi par le joueur
*\return int 
*/
int mlv_clic_jouer(){
int x,y;

/********************/
/* Gestion des clic */
/********************/
while (1){
    MLV_wait_mouse(&x, &y);
    

    if (( x>226 && y> 100 )&& (x<378 && y<163)){
      return 10; /* -> jouer classique*/
    }
    else if (( x> 100 && y> 300 ) && ( x< 215 && y<361)){
      return 11 ; /* -> niveau 1  */
    }
    else if ((x> 251 && y> 300 ) && ( x<370 && y < 362 )){
      return 12; /* -> niveau 2 */
    }
    else if ((x>400  && y>300 ) && (x<521  && y<363 )){
      return 13; /* -> niveau 3 */
    }
  if (( x>20 && y> 20 )&& (x<133 && y<83)){
      return 0; /* Retour au menu */
    }
    else if (( x> 100 && y>400 ) && ( x< 215 && y<461)){
      return 14 ; /* -> Niveau 4  */
    }
    else if ((x> 251 && y> 400 ) && ( x<370 && y < 462 )){
      return 15; /* -> Niveau 5  */
    }
    else if ((x>400  && y>400 ) && (x<521  && y<463 )){
      return 16; /* -> Niveau 6*/
    }
    else if (( x> 100 && y> 500 ) && ( x< 215 && y<561)){
      return 17 ; /* -> Niveau 7 */
    }
    else if ((x> 251 && y> 500 ) && ( x<370 && y < 562 )){
      return 18; /* -> Niveau 8 */
    }
    else if ((x>400  && y>500 ) && (x<521  && y<563 )){
      return 19; /* -> Niveau 9 */
    }
    else if ((x>225 && y> 200) && (x<380 && y< 265)){
      return 20;  /* -> Partie de sauvegarde */
    }
    else if((x>400 && y> 200) && (x< 520 && y< 261)){
      return 21; /* Partie creative */
    }
    else if((x>100 && y>200) && (x<200 &&   y<262)){
      return 22; /* Partie survie */
    }
  }
  MLV_clear_window(MLV_COLOR_WHITE);
  /*Niveau originial -> 10
  Niveau 1 -> 11
  Niveau 2 -> 12 
  ...
  */
  return 10; /* Cette valeur ne doit normalement pas être retournée */
}


/***********************/
/* Commentaire Doxygen */
/***********************/
/**
*\fn void mlv_affichage_score()
*\brief Fonction graphique affichant les scores 
*\return void 
*/


void mlv_affiche_score(){
  int score;
  int place;
  char nom[20];
  int i;
	
  MLV_Font * police2= MLV_load_font("./Polices/Police2.ttf",20);
  FILE *fich = fopen("meilleurscore.txt","r+");
  MLV_clear_window(MLV_COLOR_BLACK);
    MLV_draw_adapted_text_box_with_font(20,20,"Retour",police2,20,MLV_COLOR_BLUE,MLV_COLOR_BLUE,MLV_COLOR_BLACK,MLV_TEXT_CENTER);

  MLV_draw_adapted_text_box_with_font(185,25,"Meilleurs scores :",police2,20,MLV_COLOR_BLUE,MLV_COLOR_BLUE,MLV_COLOR_BLACK,MLV_TEXT_CENTER);
  /*MLV_draw_rectangle(10,10,75,75,MLV_COLOR_WHITE);*/
  /*****************************************/
  /* Boucle affichant les meilleurs scores */
  /*****************************************/
  for(i=1;i<=10;i++){
    fscanf(fich,"%d %d %s", &score, &place, nom);
    fscanf(fich,"\n");

    MLV_draw_rectangle(100,50*i+50,400,50,MLV_COLOR_GREEN);
    MLV_draw_adapted_text_box_with_font(125,50*i+65,"%d",police2,1,MLV_COLOR_BLACK,MLV_COLOR_BLUE,MLV_COLOR_BLACK,MLV_TEXT_CENTER,place);
    MLV_draw_adapted_text_box_with_font(200,50*i+65,"%s",police2,1,MLV_COLOR_BLACK,MLV_COLOR_BLUE,MLV_COLOR_BLACK,MLV_TEXT_CENTER,nom);
    MLV_draw_adapted_text_box_with_font(400,50*i+65,"%d",police2,1,MLV_COLOR_BLACK,MLV_COLOR_BLUE,MLV_COLOR_BLACK,MLV_TEXT_CENTER,score);
}
  MLV_actualise_window();
  fclose(fich);
}

/***********************/
/* Commentaire Doxygen */
/***********************/
/**
*\fn int mlv_clic_score()
*\brief Fonction d'utilisation permettant de renvoyer le choix ou non de revient au menu
*\return int 
*/


int mlv_clic_score(){
  int x,y;
  while (1){
    MLV_wait_mouse(&x, &y);
  if (( x>20 && y> 20 )&& (x<133 && y<83)){
      return 0; 
    }
  }
return 0;
}


/***********************/
/* Commentaire Doxygen */
/***********************/
/**
*\fn void mlv_print_quadrillage()
*\brief Fonction d'affichage permettant de faire la grille sur lequel le snake va circuler 
*\return void 
*/


void mlv_print_quadrillage(){
  int i;
  int haut = 0;
  int gauche = 0;
  for(i=0;i<100;i++){
    MLV_draw_rectangle(gauche,haut,60,60,MLV_COLOR_GREY);
    gauche=gauche+60;
    if((i+1)%10 == 0 ){
      haut=haut+60;
      gauche = 0;
    }
  }
}


/***********************/
/* Commentaire Doxygen */
/***********************/
/**
*\fn void mlv_print_snake(int snake_point[100],int snake[100],char deplacement)
*\brief Fonction permettant d'afficher le snake avec son corp et la tete oriente vers le deplacement prochain
*\param snake_point[100] int  Aide a afficher les parties du snake 
*\param snake[100] int  Aide a afficher les elements du decors 
*\param deplacement char Permet d'oriente la tete 
*\return void 
*/
  

void mlv_print_snake(int snake_point[100],int snake[100],char deplacement){
  int i;

  MLV_Image *haut;
  MLV_Image *droite;
  MLV_Image *bas;
  MLV_Image *gauche;
  for(i=0;i<100;i++){
   
    if ( snake_point[i] != -1 && i > 0){
      MLV_draw_filled_rectangle((snake_point[i])%10*60,(snake_point[i])/10*60,60,60,MLV_COLOR_TAN2);
    }


    
    if (snake_point[i] != -1 &&  i == 0){
      if(deplacement == 'z'){
	haut   = MLV_load_image( "images/teteserpenthaut.png" );
	MLV_resize_image_with_proportions( haut, 60, 60);	
	MLV_draw_image( haut,(snake_point[i])%10*60,(snake_point[i])/10*60); 
      }
      if(deplacement == 'q'){
	gauche = MLV_load_image( "images/teteserpentgauche.png" );
       	MLV_resize_image_with_proportions( gauche, 60, 60);
	MLV_draw_image( gauche,(snake_point[i])%10*60,(snake_point[i])/10*60); 
      }
      if(deplacement == 's'){
	bas    = MLV_load_image( "images/teteserpentbas.png" );
	MLV_resize_image_with_proportions( bas, 60, 60);
	MLV_draw_image( bas,(snake_point[i])%10*60,(snake_point[i])/10*60); 
      }
      if(deplacement == 'd'){
	droite = MLV_load_image( "images/teteserpentdroite.png" );
	MLV_resize_image_with_proportions( droite, 60, 60);
	MLV_draw_image( droite,(snake_point[i])%10*60,(snake_point[i])/10*60); 
      }
    }



    
    if (snake[i] == 2){
      	haut   = MLV_load_image( "images/souris.png" );
	MLV_resize_image_with_proportions( haut, 60, 60);	
	MLV_draw_image( haut,i%10*60,i/10*60);
    }
    if ( snake[i] == 3){
      MLV_draw_filled_rectangle(i%10*60,i/10*60,60,60,MLV_COLOR_RED);
    }
  }
}


/***********************/
/* Commentaire Doxygen */
/***********************/
/**
*\fn char mlv_demande_deplacement_first()
*\brief Fonction permettant de recuperer le caractere de deplacement du joueur. La fonction est bloquante tant que le deplacement est incorect 
*\return char 
*/
char mlv_demande_deplacement_first(){
  MLV_Keyboard_button bouton;
  MLV_Event event = MLV_NONE;
  
  while (1){

    MLV_delay_according_to_frame_rate();
     event = MLV_get_event( 
			  &bouton, NULL, NULL,
			  NULL, NULL,
			  NULL, NULL, NULL,
			  NULL
			   );
     if( event == MLV_KEY){
        if ( bouton == MLV_KEYBOARD_a ){
          return 'a';
        }
       else if ( bouton == MLV_KEYBOARD_z || bouton == MLV_KEYBOARD_UP){
	        return 'z';
       }
       else if ( bouton == MLV_KEYBOARD_q || bouton == MLV_KEYBOARD_LEFT){
	        return 'q';
       }
       else if ( bouton == MLV_KEYBOARD_s || bouton == MLV_KEYBOARD_DOWN){
	        return 's';
       }
       else if ( bouton == MLV_KEYBOARD_d || bouton == MLV_KEYBOARD_RIGHT ){
	        return 'd';
       }
      
     }
  }
  
}


/***********************/
/* Commentaire Doxygen */
/***********************/
/**
*\fn char mlv_demande_deplacement(char deplacement)
*\brief Fonction permettant de recuperer le caractere de deplacement du joueur. Si la touche appuye est incorrect alors on renvoie la touche du dernier deplacement 
*\param deplacement char dernier deplacement 
*\return char 
*/

char mlv_demande_deplacement(char deplacement){
  MLV_Keyboard_button bouton;
  char dp;
  MLV_Event event = MLV_NONE;
  dp = deplacement;
  MLV_delay_according_to_frame_rate();

  event =  MLV_get_event( 
                        &bouton, NULL, NULL,
                        NULL, NULL,
                        NULL, NULL, NULL,
                        NULL
			  );


   
  if ( event == MLV_KEY){
    
    if ( bouton == MLV_KEYBOARD_a ){
          return 'a';
    }
    else if (bouton == MLV_KEYBOARD_ESCAPE){
       MLV_draw_text(200,625,"Reprendre -> appuie sur p ",MLV_COLOR_TAN2);
      MLV_actualise_window();
      while(bouton != MLV_KEYBOARD_p && bouton != MLV_KEYBOARD_a){
        MLV_wait_keyboard(&bouton,NULL,NULL);
        deplacement = dp; 
      }
      if ( bouton == MLV_KEYBOARD_a){
        return 'a';
      }
      else {
      MLV_draw_text(400,625,"3",MLV_COLOR_RED);
      MLV_actualise_window();
      MLV_wait_seconds(1);
      MLV_draw_text(425,625,"2",MLV_COLOR_RED);
      MLV_actualise_window();
      MLV_wait_seconds(1);
      MLV_draw_text(450,625,"1",MLV_COLOR_RED);
      MLV_actualise_window();  
      MLV_wait_seconds(1);
      MLV_delay_according_to_frame_rate();
      }

      
    }
    else if ( bouton == MLV_KEYBOARD_z || bouton == MLV_KEYBOARD_UP){
      return 'z';
    }
    else if ( bouton == MLV_KEYBOARD_q || bouton == MLV_KEYBOARD_LEFT){
      return 'q';
    }
    else if ( bouton == MLV_KEYBOARD_s || bouton == MLV_KEYBOARD_DOWN){
      return 's';
    }
    else if ( bouton == MLV_KEYBOARD_d || bouton == MLV_KEYBOARD_RIGHT ){
      return 'd';
    }
  }

  return deplacement;
}


/***********************/
/* Commentaire Doxygen */
/***********************/
/**
*\fn int mlv_snake_lose(int snake_point,char deplacement,int snake[100])
*\brief Fonction indiquant si nous avons perdu 
*\param snake_point int tete du serpent 
*\param deplacement char deplacement prochain 
*\param snake[100] int tableau contenant le decors 
*\return int 
*/
int mlv_snake_lose(int snake_point,char deplacement,int snake[100]){
  if ( deplacement == 'z' ){
    if(snake_point -10 < 0){
      mlv_affichage_lose(); /* sortie */
      return 1;
    }
    else if(snake[snake_point-10] == 1){
      mlv_affichage_lose(); /* queue */
      return 1;
    }
    else if (snake[snake_point-10] == 3){
      mlv_affichage_lose(); /* mur */
      return 1;
    }
  }
  else if ( deplacement == 'q' ){
    if((snake_point -1) % 10 == 9){
      mlv_affichage_lose(); /* sortie */
      return 1;
    }
    else if ( snake[snake_point-1] == 1 ){
      mlv_affichage_lose(); /* queue */
      return 1;
    }
     else if (snake[snake_point-1] == 3){
      mlv_affichage_lose(); /* mur */
      return 1;
    }
    
  }
  else if ( deplacement == 's' ){
    if(snake_point+10 > 99 ){
      mlv_affichage_lose(); /* sortie */
      return 1;
    }
    else if(snake[snake_point+10] == 1){
      mlv_affichage_lose(); /* queue */
      return 1;
    }
     else if (snake[snake_point+10] == 3){
      mlv_affichage_lose(); /* mur */
      return 1;
    }
  }
  else if ( deplacement == 'd' ){
    if((snake_point +1 ) % 10 == 0){
      mlv_affichage_lose(); /* sortie */
      return 1;
    }
    else if(snake[snake_point+1] == 1 ){
      mlv_affichage_lose(); /* queue */
      return 1;
    }
     else if (snake[snake_point+1] == 3){
      mlv_affichage_lose(); /* mur */
      return 1;
    }
    
  }
  return 0;
}


  
  
/***********************/
/* Commentaire Doxygen */
/***********************/
/**
*\fn int mlv_affichage_lose()
*\brief Fonction d'affichage de fin de partie  
*\return int 
*/

int mlv_affichage_lose(){

int x,y;
   MLV_Font * police2= MLV_load_font("./Polices/Police2.ttf",20);

MLV_clear_window(MLV_COLOR_BLACK);
  MLV_draw_adapted_text_box_with_font(225,100,"Vous avez perdu",police2,10,MLV_COLOR_RED,MLV_COLOR_RED,MLV_COLOR_BLACK,MLV_TEXT_CENTER); 
    MLV_draw_adapted_text_box_with_font(205,500,"Retour au menu",police2,30,MLV_COLOR_RED,MLV_COLOR_RED,MLV_COLOR_BLACK,MLV_TEXT_CENTER); MLV_actualise_window();
MLV_actualise_window();
 while (1){
 
  MLV_wait_mouse(&x,&y);
  if((x>200 && y>500 )&& (x<415 && y<580 )){
    return 1; 
  }
 }
}

/***********************/
/* Commentaire Doxygen */
/***********************/
/**
*\fn char* mlv_demande_nom()
*\brief Fonction graphique demandant le nom et le renvoyant 
*\param nom char* Permet d'avoir l'adresse du nom pour le changer ( on a eu des problemes si on le mettais pas )
*\return char* 
*/

char* mlv_demande_nom(char* nom){

  MLV_clear_window(MLV_COLOR_BLACK);
  MLV_draw_text(
                75, 250,
                "Veuillez entrer votre nom dans la fenêtre ci-dessous.",
                MLV_COLOR_RED
		);

  MLV_wait_input_box(
		     150,300,
		     200,100,
		     MLV_COLOR_RED, MLV_COLOR_GREEN, MLV_COLOR_BLACK,
		     "Votre nom : ",
		     &nom
		     );
  
  MLV_actualise_window();
  return nom;

}

/***********************/
/* Commentaire Doxygen */
/***********************/
/**
*\fn int mlv_affichage_save()
*\brief Fonction d'affichage et d'interpretation affichant et renvoyant la partie de sauvegarde que l'on veut
*\return int 
*/
int mlv_affichage_save(){
  int x,y;
  MLV_Font * police2= MLV_load_font("./Polices/Police2.ttf",40);
    MLV_Font * police3= MLV_load_font("./Polices/Police2.ttf",75);


  MLV_clear_window(MLV_COLOR_BLACK);
  MLV_draw_adapted_text_box_with_font(65,100,"Menu des sauvegardes",police2,10,MLV_COLOR_RED,MLV_COLOR_RED,MLV_COLOR_BLACK,MLV_TEXT_CENTER); 
  MLV_draw_rectangle(100-50,200,100,100,MLV_COLOR_RED);
    MLV_draw_adapted_text_box_with_font(100,250,"1",police3,10,MLV_COLOR_RED,MLV_COLOR_RED,MLV_COLOR_BLACK,MLV_TEXT_CENTER); 

  MLV_draw_rectangle(300-50,200,100,100,MLV_COLOR_RED);
    MLV_draw_adapted_text_box_with_font(300,250,"2",police3,10,MLV_COLOR_RED,MLV_COLOR_RED,MLV_COLOR_BLACK,MLV_TEXT_CENTER); 

  MLV_draw_rectangle(500-50,200,100,100,MLV_COLOR_RED);
    MLV_draw_adapted_text_box_with_font(500,250,"3",police3,10,MLV_COLOR_RED,MLV_COLOR_RED,MLV_COLOR_BLACK,MLV_TEXT_CENTER); 


 MLV_draw_rectangle(200-50,400,100,100,MLV_COLOR_RED);
    MLV_draw_adapted_text_box_with_font(200,450,"4",police3,10,MLV_COLOR_RED,MLV_COLOR_RED,MLV_COLOR_BLACK,MLV_TEXT_CENTER); 

 MLV_draw_rectangle(400-50,400,100,100,MLV_COLOR_RED);
    MLV_draw_adapted_text_box_with_font(400,450,"5",police3,10,MLV_COLOR_RED,MLV_COLOR_RED,MLV_COLOR_BLACK,MLV_TEXT_CENTER); 

  MLV_actualise_window();
  while (1){
  MLV_wait_mouse(&x,&y);
   if((x>50 && y>200 ) && (x<150 && y<350 )){
    return 1;
  }
   if((x>250 && y>200 ) && (x<360 && y<350 )){
    return 2;
  }
   if((x>450 && y>200 ) && (x<564 && y<350 )){
    return 3;
  }
   if((x>150 && y>400 ) && (x<264 && y<550 )){
    return 4;
  }
   if((x>350 && y>400 ) && (x< 464&& y<550 )){
    return 5;
  }
  } 
 

}

/***********************/
/* Commentaire Doxygen */
/***********************/
/**
*\fn int mlv_menu_sauvegarde()
*\brief Fonction d'affichage et d'interpretation des sauvegardes 
*\return int 
*/

int mlv_menu_sauvegarde(){
   int x,y;
  MLV_Font * police2= MLV_load_font("./Polices/Police2.ttf",40);
    MLV_Font * police3= MLV_load_font("./Polices/Police2.ttf",75);


  MLV_clear_window(MLV_COLOR_BLACK);
  MLV_draw_adapted_text_box_with_font(65,100,"Menu des sauvegardes",police2,10,MLV_COLOR_RED,MLV_COLOR_RED,MLV_COLOR_BLACK,MLV_TEXT_CENTER); 
  MLV_draw_rectangle(100-50,200,100,100,MLV_COLOR_RED);
    MLV_draw_adapted_text_box_with_font(100,250,"1",police3,10,MLV_COLOR_RED,MLV_COLOR_RED,MLV_COLOR_BLACK,MLV_TEXT_CENTER); 

  MLV_draw_rectangle(300-50,200,100,100,MLV_COLOR_RED);
    MLV_draw_adapted_text_box_with_font(300,250,"2",police3,10,MLV_COLOR_RED,MLV_COLOR_RED,MLV_COLOR_BLACK,MLV_TEXT_CENTER); 

  MLV_draw_rectangle(500-50,200,100,100,MLV_COLOR_RED);
    MLV_draw_adapted_text_box_with_font(500,250,"3",police3,10,MLV_COLOR_RED,MLV_COLOR_RED,MLV_COLOR_BLACK,MLV_TEXT_CENTER); 

 MLV_draw_rectangle(200-50,400,100,100,MLV_COLOR_RED);
    MLV_draw_adapted_text_box_with_font(200,450,"4",police3,10,MLV_COLOR_RED,MLV_COLOR_RED,MLV_COLOR_BLACK,MLV_TEXT_CENTER); 

 MLV_draw_rectangle(400-50,400,100,100,MLV_COLOR_RED);
    MLV_draw_adapted_text_box_with_font(400,450,"5",police3,10,MLV_COLOR_RED,MLV_COLOR_RED,MLV_COLOR_BLACK,MLV_TEXT_CENTER); 

  MLV_actualise_window();
  while (1){
  MLV_wait_mouse(&x,&y);
  
   if((x>50 && y>200 ) && (x<150 && y<350 )){
    return 1;
  }
   if((x>250 && y>200 ) && (x<360 && y<350 )){
    return 2;
  }
   if((x>450 && y>200 ) && (x<564 && y<350 )){
    return 3;
  }
   if((x>150 && y>400 ) && (x<264 && y<550 )){
    return 4;
  }
   if((x>350 && y>400 ) && (x< 464&& y<550 )){
    return 5;
  }
  } 
 

}


/***********************/
/* Commentaire Doxygen */
/***********************/
/**
*\fn void snake_print_bas(int score,time_t start)
*\brief Fonction permettant d'afficher le score et le temps :)
*\param score int Permet de recup le score
*\param start time_t structure de <time.h> permettant de calculer le temps depuis le debut 
*\return void 
*/
void snake_print_bas(int score,time_t start){
    MLV_Font * police2= MLV_load_font("./Polices/Police2.ttf",20);


  MLV_draw_filled_rectangle(0,600,600,200,MLV_COLOR_WHITE);
     MLV_draw_text(200,675,"Pour mettre en pause appuyer sur echap ",MLV_COLOR_TAN2);
       MLV_draw_text(200,650,"Pour sauvegarder appuyer sur a",MLV_COLOR_TAN2);
    MLV_draw_adapted_text_box_with_font(25,720,"Chrono : %d secondes",police2,20,MLV_COLOR_RED,MLV_COLOR_RED,MLV_COLOR_BLACK,MLV_TEXT_CENTER,(time(NULL) - start)); 
  MLV_draw_adapted_text_box_with_font(400,720,"Score : %d points",police2,20,MLV_COLOR_RED,MLV_COLOR_RED,MLV_COLOR_BLACK,MLV_TEXT_CENTER,score-1); 

}


void mlv_mode_creatif(){
  int i;
  int x,y;
  int haut = 0;
  int gauche = 0;
  int snake[100];
  int xx;
  FILE * fich;
  MLV_Font * police2= MLV_load_font("./Polices/Police2.ttf",40);

  fich = fopen("niveaux/niveaucreatif.txt","r+");
  for (i=0;i<101;i=i+10){
	  fscanf(fich,"%d %d %d %d %d %d %d %d %d %d",&snake[i+0],&snake[i+1],&snake[i+2],&snake[i+3],&snake[i+4],&snake[i+5],&snake[i+6],&snake[i+7],&snake[i+8],&snake[i+9]);
  }
/* ouvrir le fichier et recup les valeurs */
  MLV_change_window_size(600,800);
  MLV_clear_window(MLV_COLOR_BLACK);
  while( 1 ){
    
    MLV_draw_filled_rectangle(0,600,600,200,MLV_COLOR_WHITE);
    MLV_draw_adapted_text_box_with_font(230,650,"Jouer",police2,20,MLV_COLOR_RED,MLV_COLOR_RED,MLV_COLOR_BLACK,MLV_TEXT_CENTER); 
 
    for(i=0;i<100;i++){
      if (snake[i] == 3 ){
      MLV_draw_filled_rectangle(gauche,haut,60,60,MLV_COLOR_GREY);
      }
      gauche=gauche+60;
      if((i+1)%10 == 0 ){
        haut=haut+60;
        gauche = 0;
      }
    }
    gauche = 0;
    haut = 0;
    MLV_actualise_window();
    MLV_wait_mouse(&x,&y);
    MLV_clear_window(MLV_COLOR_BLACK);
    if(x<600 && y<600){
      xx = (x/60)+ (y/60)*10;    
      if(xx != 55){  
        if( snake[xx] == 3 ){
          snake[xx] = 0;
        }
        else {
          snake[xx]=3;
        }
      }
    }
    if((x>230 && y>650) && ( x<383 && y<732)){
      break;
    }
  }
  fclose(fich);
  fich = fopen("niveaux/niveaucreatif.txt","w+");

    for (i=0;i<99;i=i+10){
	  fprintf(fich,"%d %d %d %d %d %d %d %d %d %d\n",snake[i+0],snake[i+1],snake[i+2],snake[i+3],snake[i+4],snake[i+5],snake[i+6],snake[i+7],snake[i+8],snake[i+9]);
    }
    fclose(fich);
  /* Ouvrir le fichier et ecrire les valeurs */
}