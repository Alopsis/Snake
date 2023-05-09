void snake_remplir_zero(int snake[100],int niveau);
void snake_estpoint_init_premier(int snake_point[100]);

void snake_place_point(int point,int snake[100]);
void snake_mange_pomme(int snake[100],char deplacement, int tete );
void snake_remplir(int snake[100],int snake_point[100],int snake_pomme,int score,int niveau);
int snake_ya_pomme(int snake[100]);
int snake_spawn_pomme(int snake[100]);
int snake_charger_partie(int snake_point[100],int snake[100],int sauvegarde );