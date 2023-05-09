void mlv_creation_fenetre();
void mlv_affichage_menu();
int mlv_clic_menu();

void mlv_affichage_jouer();
int mlv_clic_jouer();

void mlv_affichage_options();
int mlv_clic_options();

void mlv_print_quadrillage();
void mlv_print_snake(int snake_point[100],int snake[100],char deplacement);


char mlv_demande_deplacement_first();
char mlv_demande_deplacement(char snake_deplacement);
int mlv_snake_lose(int snake_point,char deplacement, int snake[100]);
int mlv_affichage_lose();
char* mlv_demande_nom(char * nom);
void mlv_affiche_score();
int mlv_clic_score();
int mlv_affichage_save();
int mlv_menu_sauvegarde();
void snake_print_bas(int score,time_t start);
void mlv_mode_creatif();